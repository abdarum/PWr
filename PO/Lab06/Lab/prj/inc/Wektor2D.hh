#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>


#define WYMIAR_WEKTORA 2

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
  double _wart[WYMIAR_WEKTORA];
  static int _laczna_liczba_utworzonych;
  static int _aktualna_liczba_istniejacych;
  void Aktualizuj_Statystyki(){++_laczna_liczba_utworzonych; ++_aktualna_liczba_istniejacych; 
}

  //  void   
public:
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D zerami
   */    
  Wektor2D() {Aktualizuj_Statystyki(); Zeroj_Wektor();}
  /*!
   *  \brief Konstruktor kopiujący
   */    
  Wektor2D(const Wektor2D &Wek) {*this=Wek; Aktualizuj_Statystyki();}
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D wartosciami 
   *
   *  param[in] x_new - inicjalizuje pierwsza współrzędną wartoscią x_new
   *  param[in] y_new - inicjalizuje drugą współrzędną wartoscią y_new
   */    
  Wektor2D(double x_new, double y_new) {Aktualizuj_Statystyki(); _wart[0]=x_new;
 _wart[1]=y_new;}
  /*!
   * \brief Destruktor
   *
   * Po usunięciu zmiennej zmniejsza dekrementuje liczbę aktualnie istniejących objektów
   */
  ~Wektor2D(){/*std::cout<<"Destruktor"<<std::endl;*/ --_aktualna_liczba_istniejacych;}
  /*!
   *  \brief Ustawia pierwsza wspolrzedno wektora na x_new
   */
  void Ustaw_X(double x_new){_wart[0]=x_new;}
  /*!
   *  \brief Ustawia druga wspolrzedna wektora na y_new
   */
  void Ustaw_Y(double y_new){_wart[1]=y_new;}
  /*!
   *  \brief Ustawia  wartosc współrzędnej wektora Ind na wartość wart_new
   *  \param[in] wart_new - wartość która ma być nadana wybranej współrzędnej wektora
   *  \param[in] Ind - współrzędna dla której wartość ma być zmieniona
   *  Ind dla pierwszej współrzędnej 0, drugiej 1 itd.
   */
  void Ustaw_Wsp(double wart_new, int Ind){assert(Ind<WYMIAR_WEKTORA); _wart[Ind]=wart_new;}
  /*!
   *  \brief Ustawia  wspolrzedne wektora na odpowiednio x_new, y_new 
   */
  void Ustaw(double x_new, double y_new){_wart[0]=x_new; _wart[1]=y_new;}
  /*!
   * \brief Zwraca wartosc pierwszej wspolrzednej
   */
  double Zroc_X(){return _wart[0];}
  /*!
   * \brief Zwraca wartosc drugiej wspolrzednej
   */
  double Zwroc_Y(){return _wart[1];}
  /*!
   * \brief Przeciarzenie operatra odejmowania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być odjęty 
   */
  Wektor2D operator- (Wektor2D Wek){Wektor2D tmp;for(int i=0;i<WYMIAR_WEKTORA;++i) tmp[i]=_wart[i]-Wek[i]; return tmp; }
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor2D operator+ (Wektor2D Wek){for(int i=0;i<WYMIAR_WEKTORA;++i) Wek[i]+=_wart[i]; return Wek; }
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma być dodany 
   */
  Wektor2D& operator+= (const Wektor2D& Wek){*this=*this+Wek; return *this; }
  /*!
   * \brief Przeciarzenie operatra mnożenia wektora przez liczbę
   * 
   * \param[in] Liczba przez jaką wektor ma być przemnożony 
   */
  Wektor2D operator* (const double &Liczba) const {Wektor2D Wek=*this; for(int i=0;i<WYMIAR_WEKTORA;++i) Wek[i]*=Liczba; return Wek; }
  /*!
   * \brief Przeciarzenie operatra mnożenia wektorów
   * 
   * \param[in] Liczba przez jaką wektor ma być przemnożony 
   */
  Wektor2D& operator*= (const double& Liczba){*this=*this*Liczba; return *this; }
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
  /*!
   * \brief Funkcja zeruje wartości wektora
   */
  void Zeroj_Wektor(){for(int i=0;i< WYMIAR_WEKTORA;++i) _wart[i]=0;}
  /*!
   * \brief Zwraca odległość między dwoma wektorami
   */
  double Odleglosc_Wektorow(Wektor2D Wek)const{return sqrt(pow(Wek[0]-_wart[0],2)+pow(Wek[1]-_wart[1],2));}
  /*!
   * \brief Funkcja zwraca liczbę istniejących objektów 
   */
  static  int Ile_Istnieje(){return _aktualna_liczba_istniejacych;}
  /*!
   * \brief Funkcja zwraca  łączną liczbę utworzonych objektów  
   */
  static int Ile_Utworzono(){return _laczna_liczba_utworzonych;}
  /*!
   * \brief Funkcja wypisuje statystyki ile utworzono objektów a ile teraz istnieje
   */
  static void Wyswietl_Statystyki(){
    std::cout<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "<<_laczna_liczba_utworzonych<<std::endl;
    std::cout<<"      Ilosc istniejacych obiektow klasy Wektor2D: "<<_aktualna_liczba_istniejacych<<std::endl;  }
};

/*!
 *\brief Wczytuje współrzędne wektora
 *
 * Współrzędne są pobierane w kolejności x , y
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 *\brief Wyswietla współrzędne wektora
 *
 * Współrzędne są zwracane w kolejności x (znak tabulacji) y
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
