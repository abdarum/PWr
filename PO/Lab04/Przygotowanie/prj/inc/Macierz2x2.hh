#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include "Wektor2D.hh"
#include <iostream>
#include <cmath>

/*!
 * \file
 * \brief Definicja klasy Macierz2x2
 *
 * Plik zawiera kalse Macierz2x2
 */
class Macierz2x2 {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  double _Tab[2][2];
  public:
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 
   *  gdzie a jest katem podanym w stopniach
   */ 
  Macierz2x2(float a);
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 0
   */ 
  Macierz2x2() { for(int i=0;i<2;i++) for(int j=0;j<2;j++) _Tab[i][j]=0;}
  /*!
   * \brief Nadaje wartosc macierzy. 
   *
   * Przypisanie wartosci sinusow i cosinusow dla kata a
   */
  void UstawAlpha(float a);
  
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  void operator *(Wektor2D& Wektor);
  
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
