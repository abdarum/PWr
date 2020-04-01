#ifndef PRZESZKODA
#define PRZESZKODA

#include "Objekt_Graficzny.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy Przeszkoda
 *
 * Plik zawiera kalse Przeszkoda
 */

/*!
 *\brief Modeluje informacje dotyczace Przeszkoda
 *
 * Modeluje zestaw informacji dotyczacych przeszkód.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Przeszkoda: public Objekt_Graficzny {

public:
  Przeszkoda(){Objekt_Graficzny();}
  /*!
   * \brief Inicjalizacja zmiennej typu ZbiorWierzcholkow wartosciami
   *
   * \param[in] Wspolrzedne_Wierzcholkow ustawia parametry wspolrzednych
   *                        wierzcholkow. Należy podać je w kolejności:
   *                        WspX_Wierzch1 WspY_Wierzch1 WspX_Wierzch2 ...
   * \param[in] Wspolrzedne_Globalne Współrzędne globalne 
   * \param[in]  Kat_Obrotu Kąt obrotu o jaki obrócić wierzchołki względem 
   *                        domyślego położenia
   */
 
  Przeszkoda(std::vector<double> Wspolrzedne_Wierzcholkow){ Objekt_Graficzny::Ustaw(Wspolrzedne_Wierzcholkow);}
  /*!
   * \brief Inicjalizacja zmiennej typu Przeszkoda wartosciami
   *
   * Każdy wierzchołek jest oreślony jako wektor
   *
   * \param[in] Wierzcholki ustawia parametry wspolrzednych
   */
  Przeszkoda(std::vector<Wektor2D> Wierzcholki){Objekt_Graficzny::Ustaw(Wierzcholki);}
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;



};

#endif
