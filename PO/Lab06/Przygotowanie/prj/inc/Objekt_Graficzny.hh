#ifndef OBJEKT_GRAFICZNY_HH
#define OBJEKT_GRAFICZNY_HH

#include "Wektor2D.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy Objekt_Graficzny
 *
 * Plik zawiera kalse Objekt_Graficzny
 */


/*!
 *\brief Modeluje informacje dotyczace Objekt_Graficzny
 *
 * Modeluje zestaw informacji dotyczacych wszystkich objektów występujących na
 *  scenie.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class  Objekt_Graficzny
{
  Wektor2D _wsp_lokalne;
  Wektor2D _wsp_globalne;
  double _kat;
public:
  /*!
   * \brief Inicjalizacja Obiektu graficznego
   */
  Objekt_Graficzny(){_kat=0; _wsp_lokalne=Wektor2D(); _wsp_globalne=Wektor2D();}


  // friend std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);
};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif
