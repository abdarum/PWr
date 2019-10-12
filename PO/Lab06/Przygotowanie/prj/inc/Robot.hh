#ifndef ROBOT_HH
#define ROBOT_HH

#include "Macierz2x2.hh"
#include "Objekt_Graficzny.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

#define LICZBA_PUNKTOW 6
/*!
 * \file
 * \brief Definicja klasy Robot
 *
 * Plik zawiera kalse Robot
 */


/*!
 *\brief Modeluje informacje dotyczace prostokąta
 *
 * Modeluje zestaw informacji dotyczacych prostokąta.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Robot
{
  Wektor2D _wierzcholki[LICZBA_PUNKTOW];
  double _kat_obrotu;
  void Domyslne_Wartosci();
  Wektor2D _wsp_globalne;
public:
  /*!
   * \brief Inicjalizacja Robota w pozycji podstawowej
   */
  Robot(){Domyslne_Wartosci(); _kat_obrotu=0; _wsp_globalne=Wektor2D();}
  /*!
   * \brief Inicjalizacja Robota w pozycji podstawowej
   */
  Robot(Wektor2D Wsp_globalne){Domyslne_Wartosci(); _kat_obrotu=0; _wsp_globalne=Wsp_globalne;}
  /*!
   * \brief Zwraca współrzędne wierzchołka Ind
   */
  Wektor2D Wartosc(int Ind) const{return _wierzcholki[Ind];}
  /*!
   * \brief Zwraca kąt obrotu Robora
   */
  double Kat_Obrotu() const{return _kat_obrotu;}
  /*!
   * \brief Zwraca współrzędne globalne robota
   */
  Wektor2D Wsp_Globalne() const{return _wsp_globalne;}
  /*!
   * \brief Ustawia współrzędne globalne robota
   */
  void Ustaw_Wsp_Globalne(Wektor2D Wsp_Globalne){ _wsp_globalne=Wsp_Globalne;}
  /*!
   * \brief Obraca prostakat o kat a
   *
   * \param[in] a kąt o jaki obrócić prostokąt
   */
  void ObrocOKat(double a);
  /*!
   * \brief Zapisuje wspolrzedne do pliku w formacie zgodnym z Gnuplotem 
   *
   * Funkcja jest niewielką modyfikacją funkcji "PrzykladZapisuWspolrzednychDoPliku" z pliku main dostarczonego w folderze zalazek
   */
  bool ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku);
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  Wektor2D operator[] (int Ind)const { return _wierzcholki[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  Wektor2D &operator[] (int Ind) { return _wierzcholki[Ind];}

};

/*!
 * \brief Wyswietla współrzędne wierzchołków względem siebie
 *
 * Uwzględnia kąt a nie uwzględnia przesunięcia. 
 */
std::ostream& operator << (std::ostream &Strm, const Robot  &Rob);

#endif
