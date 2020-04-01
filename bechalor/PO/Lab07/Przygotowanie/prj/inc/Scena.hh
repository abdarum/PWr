#ifndef SCENA_HH
#define SCENA_HH

#include "lacze_do_gnuplota.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include "ZbiorWierzcholkow.hh"
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
void Ustaw_Przeszkody(){
Przeszk.push_back(Przeszkoda(std::vector<double>{20,90,70,90,70,150,20,150}));
Przeszk.push_back(Przeszkoda(std::vector<double>{200,150,250,150,250,100,200,100}));
Przeszk.push_back(Przeszkoda(std::vector<double>{150,40,250,40,250,20,150,20}));
};
public:
  std::vector<Robot> Rob;
  std::vector<Sciezka> Sciez;
  std::vector<Przeszkoda> Przeszk;
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Scena(){Rob.push_back(Robot());Sciez.push_back(Sciezka()); Ustaw_Przeszkody();}
  /*!
   * \brief Zapisuje wspolrzedne do pliku w formacie zgodnym z Gnuplotem 
   *
   * \param[in] sNazwaPliku - Nazwa pliku do którego mają być  wypisane 
   *                          wierzchołki
   */
  bool ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku);
  /*!
   * \brief Animacja ścieżki wyświetlanej Gnuplotem 
   *   
   * \param[in] sNazwaPliku - Nazwa pliku do którego mają być  wypisane 
   *                          wierzchołki
   * \param[in] Robot_Animowany - Robot, który ma być animowany wraz ze ścieżką
   * \param[in] microseconds - długość trwania klatki w animacji
   * \param[in] dlugosc - długość kroku animacji
   */
  bool Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota  Lacze,const char *sNazwaPliku,Sciezka &Sciezka_Animowana,Robot &Robot_Animowany,double dlugosc=0.25,int microseconds=40000);
  /*!
   * \brief Animacja obrotu robota wyświetlana Gnuplotem 
   *   
   * \param[in] sNazwaPliku - Nazwa pliku do którego mają być  wypisane 
   *                          wierzchołki
   * \param[in] Robot_Animowany - Robot, który ma być animowany wraz ze ścieżką
   * \param[in] microseconds - długość trwania klatki w animacji
   * \param[in] a - kąt kroku animacji
   */
  bool Animacja_Obrotu_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka &Sciezka_Animowana,Robot &Robot_Animowany,int microseconds=40000,double a=1);

  // friend std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);
};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif


