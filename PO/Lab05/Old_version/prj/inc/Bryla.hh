#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <fstream>
#include <limits>
#include <cmath>
#include <iostream>
#include "Macierz2x2.hh"

#define LICZBA_PUNKTOW 8
/*!
 * \file
 *
 * \brief Deklaracja klasy typu Bryla
 *
 * Plik zawiera deklaracje klasy Bryla
 */

/*!
 *\brief Modeluje informacje dotyczace polozenia bryły
 *
 * Modeluje zestaw informacji dotyczacych polozenia bryły.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Bryla {
  Wektor3D _bryla[LICZBA_PUNKTOW];

  public:
  /*!
   * \brief Inicjalizacja zmiennej typu Bryla zerami 
   */
  Bryla(){ for(int i=0; i<LICZBA_PUNKTOW ; ++i) _bryla[i]=Wektor3D(); }
  
  /*!
   * \brief Inicjalizacja zmiennej typu Bryla wartosciami
   *
   * \param[in] Wart[]  ustawia parametry wszystkich współrzędnych
   *    wierzcholkow bryły. Kolejność jest istotna - dane zapisane w
   *    tablicy to odpowiednio x1, y1, x2, x2 ... Powinny one być podane w
   *    tablicy typu double o liczbie elenentów równej 3*LICZBA_PUNKTOW.
   */
  Bryla(double Wart[LICZBA_PUNKTOW*3]){Bryla(); Ustaw(Wart);}
  /*!
   * \brief Inicjalizacja zmiennej typu Bryla wartosciami
   *
   * \param[in] Wart[]  ustawia parametry wszystkich współrzędnych
   *    wierzcholkow bryły. Kolejność jest istotna - dane zapisane w
   *    tablicy to odpowiednio wektory z położeniami poszczególnych punktów.
   *    Powinny one być podane w tablicy typu Wektor3D o liczbie elenentów 
   *    równej LICZBA_PUNKTOW.
   */
  Bryla(Wektor3D Wart[LICZBA_PUNKTOW]){Bryla(); Ustaw(Wart);}
  /*!
   * \brief Ustawia wartości zmiennej typu Bryla wartosciami współrzędnych Wierzchołków
   *
   * \param[in] Wart[]  ustawia parametry wszystkich współrzędnych
   *    wierzcholkow bryły. Kolejność jest istotna - dane zapisane w
   *    tablicy to odpowiednio x1, y1, x2, x2 ... Powinny one być podane w
   *    tablicy typu double o liczbie elenentów równej 3*LICZBA_PUNKTOW.
   */
  void Ustaw(double Wart[LICZBA_PUNKTOW*3]); 
  /*!
   * \brief Ustawia wartości zmiennej typu Bryla wartosciami współrzędnych Wierzchołków
   *
   * \param[in] Wart[]  ustawia parametry wszystkich współrzędnych
   *    wierzcholkow bryły. Kolejność jest istotna - dane zapisane w
   *    tablicy to odpowiednio wektory z położeniami poszczególnych punktów.
   *    Powinny one być podane w tablicy typu Wektor3D o liczbie elenentów 
   *    równej LICZBA_PUNKTOW.
   */
  void Ustaw(Wektor3D Wart[LICZBA_PUNKTOW]);
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
   * \brief Przesuwa Bryla o wektor
   *
   * \param[in] Wek - Wektor o jaki maja byc przesuniete wierzcholki bryły
   */
  void PrzesunOWektor(Wektor3D const Wek);
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  Wektor3D operator[] (int Ind)const { return _bryla[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  Wektor3D &operator[] (int Ind) { return _bryla[Ind];}
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
std::ostream& operator << (std::ostream &Strm, const Bryla &Pr);


#endif
