#ifndef SCIEZKA_HH
#define SCIEZKA_HH

#include "Robot.hh"
#include <unistd.h>
#include <fstream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy Sciezka
 *
 * Plik zawiera kalse Sciezka
 */


/*!
 *\brief Modeluje informacje dotyczace Ścieżki
 *
 * Modeluje zestaw informacji dotyczacych ścieżki.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Sciezka
{
  std::vector<Wektor2D> _punkty;
public:
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Sciezka(){_punkty.push_back(Wektor2D(0,0));}
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   *
   * \param[in] Rob - kalsa robot z której pobierany jest kąt
   * \param[in] dlugosc - długość jaką ma jechac robot
   */
  void Jedz_Prosto(Robot &Rob,double dlugosc);
  /*!
   * \brief Funkcja wypisuje punkty w formacie gnuplot
   *
   * \param[in] StrmWy - strumień do którego mają być wypisane wierzchołki
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;
  /*!
   * \brief Funkcja wypisuje cyklicznie punkty tworząc animację
   *
   * \param[in] Rob - kalsa robot z której pobierany jest kąt
   * \param[in] dlugosc - długość kroku, ma duży wpływ na prędkość animacji
   * \param[in] StrmWy - strumień do którego mają być wypisane wierzchołki
   */
  void Animacja_Sciezki(const Robot& Rob,double dlugosc,int microseconds,std::ostream& StrmWy);

  // friend std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);
};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif


