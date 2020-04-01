#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <fstream>
#include <limits>
#include <cmath>
#include <iostream>
#include "Macierz2x2.hh"


/*!
 * \file
 *
 * \brief Deklaracja klasy typu Prostokat
 *
 * Plik zawiera deklaracje klasy Prostokat
 */

/*!
 *\brief Modeluje informacje dotyczace polozenia prostokata
 *
 * Modeluje zestaw informacji dotyczacych polozenia prostokata.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Prostokat {
  Wektor2D _prostokat[4];

  public:
  /*!
   * \brief Inicjalizacja zmiennej typu Prostokat zerami 
   */
  Prostokat(){ for(int i=0;i<4;++i) _prostokat[i]=Wektor2D(); }
  /*!
   * \brief Inicjalizacja zmiennej typu Prostokat wartosciami
   *
   * \param[in] x_{0,1,2,3} ustawia parametry pierwszej wspolrzednej
   *                        wierzcholkow prostokata.
   * \param[in] y_{0,1,2,3} ustawia parametry drugiej wspolrzednej
   *                        wierzcholkow prostokata.
   */
  Prostokat(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3){Prostokat(); Ustaw(x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3);}
  /*!
   * \brief Inicjalizacja zmiennej typu Prostokat wartosciami
   *
   * Każdy wierzchołek jest oreślony jako wektor
   *
   * \param[in] Wekt_{0,1,2,3} ustawia parametry wierzchołka prostokąta
   *                           powinny być typu Wektor2D
   */
  Prostokat(Wektor2D Wekt_0,Wektor2D Wekt_1,Wektor2D Wekt_2,Wektor2D Wekt_3){ Prostokat(); Ustaw(Wekt_0,Wekt_1,Wekt_2,Wekt_3);}

  // void Ustaw(double tmp[8]);
  /*!
   * \brief Ustawia wartosci poszczegolnych wierzcholkow
   *
   * Każdy wierzcholek powinien być określony przez współrzędne
   *
   * \param[in] x_{0,1,2,3} ustawia parametry pierwszej wspolrzednej
   *                        wierzcholkow prostokata.
   * \param[in] y_{0,1,2,3} ustawia parametry drugiej wspolrzednej
   *                        wierzcholkow prostokata.
   */
  void Ustaw(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);
  /*!
   * \brief Ustawia wartosci poszczegolnych wierzcholkow
   *
   * Każdy wierzchołek jest oreślony jako wektor
   *
   * \param[in] Wekt_{0,1,2,3} ustawia parametry wierzchołka prostokąta
   *                           powinny być typu Wektor2D
   */
  void Ustaw(Wektor2D Wekt_0,Wektor2D Wekt_1,Wektor2D Wekt_2,Wektor2D Wekt_3);
  /*!
   * \brief Obraca prostakat o kat a
   *
   * \param[in] a kąt o jaki obrócić prostokąt
   *
   * \param[in] count ile razy obrócić
   */
  void ObrocOKat(float a,int count);
  /*!
   * /brief Znajdz długości przeciwległych bokow
   */
  void DlugosciBokow() const;
  /*!
   * \brief Przesuwa Prostokat o wektor
   *
   * \param[in] Wek - Wektor o jaki maja byc przesuniete wierzcholki prostokata
   */
  void PrzesunOWektor(Wektor2D const Wek);
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  Wektor2D operator[] (int Ind)const { return _prostokat[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  Wektor2D &operator[] (int Ind) { return _prostokat[Ind];}
  /*!
   * \brief Zapisuje wspolrzedne do pliku w formacie zgodnym z Gnuplotem 
   *
   * Funkcja jest niewielką modyfikacją funkcji "PrzykladZapisuWspolrzednychDoPliku" z pliku main dostarczonego w folderze zalazek
   */
  bool ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku);

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr);


#endif
