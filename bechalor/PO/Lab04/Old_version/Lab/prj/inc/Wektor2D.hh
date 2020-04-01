#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <iomanip>

/*!
 * \file
 *
 * \brief Definicja kalsy typu Wektor2D
 *
 * Plik zawiera deklaracje klasy Wektor2D i przeciążeń operatorów
 * cout i cin dla klasy Wektor2D
 */


/*!
 *\brief Modeluje informacje dotyczace wektora
 *
 * Modeluje zestaw informacji dotyczacych wektora.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Wektor2D {
  double _x,_y;
  public:
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D zerami
   */    
  Wektor2D() { _x=_y=0; }
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D 
   *
   *  Nadaje im wartosci poczatkowe rowne 0
   */    
  Wektor2D(double x_new, double y_new) {_x=x_new; _y=y_new;}
  /*!
   *  \brief Ustawia pierwsza wspolrzedno wektora na x_new
   */
  void Ustaw_X(double x_new){_x=x_new;}
  /*!
   *  \brief Ustawia druga wspolrzedna wektora na y_new
   */
  void Ustaw_Y(double y_new){_y=y_new;}
  /*!
   *  \brief Ustawia obie wspolrzedne wektora na odpowiednio x_new i y_new
   */
  void Ustaw(double x_new, double y_new){_x=x_new; _y=y_new;}
  /*!
   * \brief Zwraca wartosc pierwszej wspolrzednej
   */
  double Zroc_X(){return _x;}
  /*!
   * \brief Zwraca wartosc drugiej wspolrzednej
   */
  double Zwroc_Y(){return _y;}
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor2D operator+ (Wektor2D Wek){Wek[0]+=_x; Wek[1]+=_y; return Wek; }
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor2D& operator+= (const Wektor2D& Wek){*this=*this+Wek; return *this; }
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  double operator[] (int Ind)const { return Ind==0 ? _x: _y;}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  double &operator[] (int Ind) { return Ind==0 ? _x: _y;}
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;
};

/*!
 *\brief Wczytuje współrzędne wektora
 *
 * Współrzędne są pobierane w kolejności x potem  y
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 *\brief Wyswietla współrzędne wektora
 *
 * Współrzędne są zwracane w kolejności x (znak tabulacji) y
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
