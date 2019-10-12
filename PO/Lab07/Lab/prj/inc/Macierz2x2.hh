#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include "Wektor2D.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

#define ROZMIAR_MACIERZY 2

/*!
 * \file
 * \brief Definicja klasy Macierz2x2
 *
 * Plik zawiera kalse Macierz2x2
 */


/*!
 *\brief Modeluje informacje dotyczace macierzy ktora jest uzywana do obrotu figury
 *
 * Modeluje zestaw informacji dotyczacych obrotu figury.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Macierz2x2 {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  double _Tab[2][2];
  public:
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 0
   */ 
  Macierz2x2() { Zeroj_Macierz();}
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 
   *  gdzie a jest katem podanym w stopniach
   */ 
  Macierz2x2(double a){ UstawAlpha(a);}
  /*!
   * \brief Nadaje wartosc macierzy. 
   *
   * Przypisanie wartosci sinusow i cosinusow dla kata a
   */
  void UstawAlpha(double a);  
  /*!
   *  \brief Nadajae  wartosc 0 wszystkim elementom tablicy
   */ 
  void Zeroj_Macierz() { for(int i=0;i<ROZMIAR_MACIERZY;i++) for(int j=0;j<ROZMIAR_MACIERZY;j++) _Tab[i][j]=0;} 
  /*!
   *  \brief Opreracja nadaje wartość macierzy jednostkowej
   */ 
  void Macierz_Jednostkowa(){Zeroj_Macierz(); for(int i=0;i<ROZMIAR_MACIERZY;++i) _Tab[i][i]=1; }  
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  Wektor2D operator *(Wektor2D Wektor) const;
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  Macierz2x2 operator *(Macierz2x2& Mac) const;
  /*!
   * \brief Funkcja do zwracania wartosci
   */
  double Wartosc(int Ind_x,int Ind_y)const { return _Tab[Ind_x][Ind_y];}
  /*!
   * \brief Funkcja do przypisania  wartosci
   */
  double &Wartosc (int Ind_x,int Ind_y) {return _Tab[Ind_x][Ind_y];}


  /*!
   *  \brief Modyfikuje wartości, co umożliwia wykonanie kilku obrotów pod rząd
   *
   *  \param[in] a - Kąt o jaki macierz ma być obrócona w stopniach
   */ 
  Macierz2x2 Macierz_Obrotu(double a);
  /*!
   *  \brief Modyfikuje wartości, co umożliwia wykonanie kilku obrotów pod rząd
   *   
   *  \param[in] Mac - Macierz o którą ma obrócić obecną macierz 
   */ 
  void Macierz_Obrotu(Macierz2x2 Mac){ *this=*this*Mac;}


  friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);
  friend std::istream& operator >> (std::istream &Strm,  Macierz2x2 &Mac);
  
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
std::istream& operator >> (std::istream &Strm,  Macierz2x2 &Mac);

#endif
