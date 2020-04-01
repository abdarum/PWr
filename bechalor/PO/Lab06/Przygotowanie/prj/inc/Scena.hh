#ifndef SCENA_HH
#define SCENA_HH

#include "Robot.hh"
#include "Prostokat.hh"
#include "Sciezka.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera kalse Scena
 */


/*!
 *\brief Modeluje informacje dotyczace Sceny
 *
 * Modeluje zestaw informacji dotyczacych wszystkich objektów występujących na
 *  scenie.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Scena
{
public:
  std::vector<Prostokat> _przeszkody;
  Robot Rob;
  Sciezka Sciez;
  //  std::vector<Prostokat> _przeszkody;
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Scena(){Rob=Robot();Sciez=Sciezka();_przeszkody.push_back(Prostokat(2,10,12,10,12,20,2,20));_przeszkody.push_back(Prostokat(-12,10,-22,10,-22,20,-12,20));}
  /*!
   * \brief Zapisuje wspolrzedne do pliku w formacie zgodnym z Gnuplotem 
   *
   * Funkcja jest niewielką modyfikacją funkcji "PrzykladZapisuWspolrzednychDoPliku" z pliku main dostarczonego w folderze zalazek
   */
  bool ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku);


  // friend std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);
};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif
