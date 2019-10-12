#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>


/*!
 * \file
 * \brief Definicja kalsy Wektor
 *
 * Modeluje ogólne pojêcie wektora.
 */
class Wektor2D {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  double _x,_y;
  public:
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D zerami
   */    
  Wektor2D() { _x=_y=0; }
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D 
   *
   *  Nadaje im wartosci poczatkowe
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
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  double operator[] (int Ind)const { return Ind==0 ? _x: _y;}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  double &operator[] (int Ind) { return Ind==0 ? _x: _y;}

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
