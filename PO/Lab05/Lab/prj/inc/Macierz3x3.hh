#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

#include "Wektor3D.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

#define ROZMIAR_MACIERZY 3

/*!
 * \file
 *
 * \brief Definicja klasy typu Macierz3x3
 *
 * Plik zawiera deklaracje kalsy Macierz3x3
 */


/*!
 *\brief Modeluje informacje dotyczace macierzy ktora jest uzywana do obrotu bryły
 *
 * Modeluje zestaw informacji dotyczacych obrotu bryły.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Macierz3x3 {
  double _Tab[ROZMIAR_MACIERZY][ROZMIAR_MACIERZY];
  public:
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc poczatkowa 0
   */ 
  Macierz3x3() { Zeroj_Macierz();}
  /*!
   *  \brief Inicjalizuje Macierz nadajac jej wartosc równą value*macierz_jednostkowa
   *
   */ 
  Macierz3x3(double value) { Zeroj_Macierz(); Macierz_Jednostkowa(value); }
  /*!
   * \brief Inicjalizuje macierz nadajac jej wartosc poczatkowa. 
   *
   * \param[in] a wartosc kąta obrotu w stopniach
   * \param[in] os_obrotu informuje która oś ma być obrócona
   *   jest to odpowiednio x, y i z dla układu 3 wymiarowego
   * Przypisanie wartosci sinusow i cosinusow dla kata a
   */
  Macierz3x3(double a,char os_obrotu){ Macierz3x3(); UstawAlpha(a,os_obrotu); }
  /*!
   * \brief Nadaje wartosc macierzy. 
   *
   * \param[in] a wartosc kąta obrotu w stopniach
   * \param[in] os_obrotu informuje która oś ma być obrócona
   *   jest to odpowiednio x, y i z dla układu 3 wymiarowego
   * Przypisanie wartosci sinusow i cosinusow dla kata a
   */
  void UstawAlpha(double a,char os_obrotu);
  /*!
   *  \brief Nadajae  wartosc 0 wszystkim elementom tablicy
   */ 
  void Zeroj_Macierz() { for(int i=0;i<ROZMIAR_MACIERZY;i++) for(int j=0;j<ROZMIAR_MACIERZY;j++) _Tab[i][j]=0;} 
  /*!
   *  \brief Opreracja nadaje wartość macierzy jednostkowej
   */ 
  void Macierz_Jednostkowa(){Zeroj_Macierz(); for(int i=0;i<ROZMIAR_MACIERZY;++i) _Tab[i][i]=1; }  
  /*!
   *  \brief Opreracja nadaje wartość wielokrotności macierzy jednostkowej
   *  
   *  \param[in] value - wartość przez jaką ma być macierz jednostkowa przemnożona 
   */ 
  void Macierz_Jednostkowa(double value){ Zeroj_Macierz(); for(int i=0;i<ROZMIAR_MACIERZY;++i) _Tab[i][i]=value; }  

  /*!
   *  \brief Modyfikuje wartości, co umożliwia wykonanie kilku obrotów pod rząd
   *
   *  \param[in] a - Kąt o jaki macierz ma być obrócona w stopniach
   *  \param[in] os_obrotu - Oś wokół której macierz ma być obrócona
   */ 
  Macierz3x3 Macierz_Obrotu(double a,char os_obrotu);
  /*!
   *  \brief Modyfikuje wartości, co umożliwia wykonanie kilku obrotów pod rząd
   *   
   *  \param[in] Mac - Macierz o którą ma obrócić obecną macierz 
   */ 
  void Macierz_Obrotu(Macierz3x3 Mac){ *this=*this*Mac;}
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  Wektor3D operator *(Wektor3D& Wektor) const;
  /*!
   *  \brief Opreracja mnozenia macierzy przez wektor
   */ 
  Macierz3x3 operator *(Macierz3x3& Mac) const;


  /*!
   * \brief Funkcja do zwracania wartosci
   */
  double Wartosc(int Ind_x,int Ind_y)const { return _Tab[Ind_x][Ind_y];}
  /*!
   * \brief Funkcja do przypisania  wartosci
   */
  double &Wartosc (int Ind_x,int Ind_y) {return _Tab[Ind_x][Ind_y];}


  friend std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac);
  friend std::istream& operator >> (std::istream &Strm,  Macierz3x3 &Mac);
  
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
std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac);
std::istream& operator >> (std::istream &Strm,  Macierz3x3 &Mac);

#endif
