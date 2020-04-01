#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>
#include <iomanip>
#include <cassert>

#define WYMIAR_WEKTORA 3

/*!
 * \file
 *
 * \brief Definicja kalsy typu Wektor3D
 *
 * Plik zawiera deklaracje klasy Wektor3D i przeciążeń operatorów
 * cout i cin dla klasy Wektor3D
 */


/*!
 *\brief Modeluje informacje dotyczace wektora
 *
 * Modeluje zestaw informacji dotyczacych wektora.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Wektor3D {
  double _wart[WYMIAR_WEKTORA];
  public:
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor3D zerami
   */    
  Wektor3D() { for(int i=0;i<WYMIAR_WEKTORA;++i) _wart[i]=0; }
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor3D wartosciami 
   *
   *  param[in] x_new - inicjalizuje pierwsza współrzędną wartoscią x_new
   *  param[in] y_new - inicjalizuje drugą współrzędną wartoscią y_new
   *  param[in] z_new - inicjalizuje trzecia współrzędną wartoscią z_new
   */    
  Wektor3D(double x_new, double y_new, double z_new) {_wart[0]=x_new; _wart[1]=y_new; _wart[2]=z_new;}
  /*!
   *  \brief Ustawia pierwsza wspolrzedno wektora na x_new
   */
  void Ustaw_X(double x_new){_wart[0]=x_new;}
  /*!
   *  \brief Ustawia druga wspolrzedna wektora na y_new
   */
  void Ustaw_Y(double y_new){_wart[1]=y_new;}
  /*!
   *  \brief Ustawia trzecią wspolrzedna wektora na z_new
   */
  void Ustaw_Z(double z_new){_wart[2]=z_new;}
  /*!
   *  \brief Ustawia  wartosc współrzędnej wektora Ind na wartość wart_new
   *  \param[in] wart_new - wartość która ma być nadana wybranej współrzędnej wektora
   *  \param[in] Ind - współrzędna dla której wartość ma być zmieniona
   *  Ind dla pierwszej współrzędnej 0, drugiej 1 itd.
   */
  void Ustaw_Wsp(double wart_new, int Ind){assert(Ind<WYMIAR_WEKTORA); _wart[Ind]=wart_new;}
  /*!
   *  \brief Ustawia  wspolrzedne wektora na odpowiednio x_new, y_new i z_new
   */
  void Ustaw(double x_new, double y_new, double z_new){_wart[0]=x_new; _wart[1]=y_new; _wart[2]=z_new;}
  /*!
   * \brief Zwraca wartosc pierwszej wspolrzednej
   */
  double Zroc_X(){return _wart[0];}
  /*!
   * \brief Zwraca wartosc drugiej wspolrzednej
   */
  double Zwroc_Y(){return _wart[1];}
  /*!
   * \brief Zwraca wartosc trzeciej wspolrzednej
   */
  double Zwroc_Z(){return _wart[2];}
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor3D operator+ (Wektor3D Wek){for(int i=0;i<WYMIAR_WEKTORA;++i) Wek[i]+=_wart[i]; return Wek; }
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor3D& operator+= (const Wektor3D& Wek){*this=*this+Wek; return *this; }
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  double operator[] (int Ind)const { return _wart[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  double &operator[] (int Ind) { return _wart[Ind];}
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;

  // tymczasowo
  Wektor3D operator / (double liczba){for(int i=0;i<WYMIAR_WEKTORA;++i) _wart[i]=_wart[i]/liczba; return *this; }



};

/*!
 *\brief Wczytuje współrzędne wektora
 *
 * Współrzędne są pobierane w kolejności x , y, z
 */
std::istream& operator >> (std::istream &Strm, Wektor3D &Wek);

/*!
 *\brief Wyswietla współrzędne wektora
 *
 * Współrzędne są zwracane w kolejności x (znak tabulacji) y
 */
std::ostream& operator << (std::ostream &Strm, const Wektor3D &Wek);

#endif
