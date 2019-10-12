#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include "Wektor3D.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

/*!
 * \file
 *
 * \brief Definicja klasy typu Macierz2x2
 *
 * Plik zawiera deklaracje kalsy Macierz2x2
 */


/*!
 *\brief Modeluje informacje dotyczace macierzy ktora jest uzywana do obrotu bryły
 *
 * Modeluje zestaw informacji dotyczacych obrotu bryły.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Macierz2x2 {
  double _Tab[2][2];
  public:
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 0
   */ 
  Macierz2x2() { for(int i=0;i<2;i++) for(int j=0;j<2;j++) _Tab[i][j]=0;}
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa
   *
   * \param[in] a wartosc kąta obrotu w stopniach
   * 
   *  Zmienna a jest katem podanym w stopniach
   */ 
  Macierz2x2(float a);
  /*!
   * \brief Nadaje wartosc macierzy. 
   *
   * \param[in] a wartosc kąta obrotu w stopniach
   *
   * Przypisanie wartosci sinusow i cosinusow dla kata a
   */
  void UstawAlpha(float a);
  
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  Wektor3D operator *(Wektor3D& Wektor);
  friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);
  
};




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
