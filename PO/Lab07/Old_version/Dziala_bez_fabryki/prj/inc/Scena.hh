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
#include <list>
#include <memory>

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
void Ustaw_Objekty(){
  Dodaj_Przeszkode(std::vector<double>{20,90,70,90,70,150,20,150});
  Dodaj_Przeszkode(std::vector<double>{200,150,250,150,250,100,200,100});
  Dodaj_Przeszkode(std::vector<double>{150,40,250,40,250,20,150,20});
  Dodaj_Robota(Wektor2D(25,25),0); 
  Dodaj_Robota(Wektor2D(125,75),225); 
  Dodaj_Robota(Wektor2D(150,150),45); 
};
public:
  std::list<std::shared_ptr<Objekt_Graficzny>> Ob_List;
  std::vector<Robot> Rob;
  std::vector<Sciezka> Sciez;
  std::vector<Przeszkoda> Przeszk;
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Scena(){Ustaw_Objekty();}
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Scena(PzG::LaczeDoGNUPlota &Lacze);
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
  //  bool Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota  Lacze,const char *sNazwaPliku,Robot *Robot_Animowany,double dlugosc=0.25,int microseconds=40000);

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
  /*!
   * \brief Dodaje Robota wraz ze ścieżką. 
   *   
   * \param[in] Wsp_Globalne - Współrzędne robota względem obecnej sceny
   * \param[in] Kat_Obrotu   - Kąt o jaki ma być obrócony Robot względem sceny
   */
  void Dodaj_Robota(Wektor2D Wsp_Globalne, double Kat_Obrotu);
  /*!
   * \brief Dodaje Przeszkodę. 
   *   
   * \param[in] Wspolrzedne_Wierzcholkow - Wspolrzedne wierzcholkow Przeszkody
   * kolejno X1, Y1, X2, Y2 ...
   */
  void Dodaj_Przeszkode(std::vector<double> Wspolrzedne_Wierzcholkow);
  /*!
   * \brief Wyswietla typt wszystkich dodanych objektów. 
   */
  void Wyswietl_Typy_Objektow();
  /*!
   * \brief Wyswietla współrzędne wszystkich dodanych objektów. 
   */
  void Wyswietl_Wspolrzedne_Objektow();
  /*!
   * \brief Zwraca liczbę Robotów w scenie. 
   */
  unsigned int Ile_Robotow(){return Rob.size();}
  /*!
   * \brief Zwraca liczbę Przeszkód w scenie. 
   */
  unsigned int Ile_Przeszkod(){return Przeszk.size();}
  /*!
   * \brief Zwraca liczbę Robotów w scenie. 
   */
  unsigned int Ile_Sciezek(){return Sciez.size();}
  /*!
   * \brief Okręgi się przecinają.
   *
   * \retval true - Okręgi się przecinają 
   * \retval false - Okręgi się nie przecinają 
   */
  bool Okregi_sie_przecinaja(Robot &R1,Robot &R2) const;
  /*!
   * \brief Punk zawiera się w prostokącie.
   *
   * \retval true - Punkt zawiera się w prostokącie 
   * \retval false - Punkt nie zawiera się w prostokącie
   */
  bool Punkt_Nalezy_Do_Prostokata(Robot &R1,Przeszkoda &Pr) const;
  /*!
   * \brief Okręgi się przecinają.
   *
   * \retval true - Okręgi się przecinają 
   * \retval false - Okręgi się nie przecinają 
   */
  bool Kolizja(Robot &R1,const std::shared_ptr<Objekt_Graficzny>& _wsk) const;

};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif


