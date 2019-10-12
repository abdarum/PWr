#ifndef ROBOT_HH
#define ROBOT_HH

#include "Macierz2x2.hh"
#include "Przeszkoda.hh"
#include "Objekt_Graficzny.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>  
#include <cmath>
#include <memory>
#include <list>


/*!
 * \file
 * \brief Definicja klasy Robot
 *
 * Plik zawiera kalse Robot
 */


/*!
 *\brief Modeluje informacje dotyczace Robota
 *
 * Modeluje zestaw informacji dotyczacych Robota.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Robot: public Objekt_Graficzny 
{
  std::vector<double> Domyslne_Wartosci{2,0,7,0,0,-10,-10,-10,-10,10,0,10};
  //  std::vector<double> Domyslne_Wartosci{2,0,  15,0,  10,10, 7,10,  0,15,  -10,10,  -15,0,  -10,-10,   0,-15, 7,-10,  10,-10   };
  Wektor2D _wektor_translacji;
  double _poprzedni_kat;
public:
  /*!
   * \brief Inicjalizacja Robota w pozycji podstawowej
   */
  Robot(){Objekt_Graficzny(); Objekt_Graficzny::Ustaw(Domyslne_Wartosci); _wektor_translacji=Wektor2D();_poprzedni_kat=0;}
  /*!
   * \brief Inicjalizacja Robota w pozycji podstawowej z ustawieniem wektora 
   *          translacji
   */
  Robot(Wektor2D Wsp_Globalne,double Kat_Obrotu){Objekt_Graficzny(); Objekt_Graficzny::Ustaw(Domyslne_Wartosci); _wektor_translacji=Wsp_Globalne; Objekt_Graficzny::Kat(Kat_Obrotu);
    if(abs(Kat_Obrotu)>std::numeric_limits<double>::epsilon()) ObrocOKat(0);}
  /*!
   * \brief Zwraca współrzędne globalne robota
   */
  Wektor2D Wektor_Translacji() const{return _wektor_translacji;}
  /*!
   * \brief Ustawia współrzędne globalne robota
   */
  void Wektor_Translacji(Wektor2D Wsp_Globalne){ _wektor_translacji=Wsp_Globalne;}
  /*!
   * \brief Zwraca promień wokół robota
   */
  double Promien() const;
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
   * \brief Funkcja wypisuje kolejne punkty posrednie do strumienia tworząc 
   *         animację obrotu robota
   *
   * \param[in] a - kat przeskoku
   */ 
  void Animacja_Obrotu_Robota(std::ostream& StrmWy,double a=1);
  //void Animacja_Obrotu_Robota(std::ostream& StrmWy,Robot& Rob);
  /*!
   * \brief Zwraca tryb pracy w którym pracuje Obiekt_Graficzny
   */
  virtual Tryb_Pracy Rodzaj_Obiektu(){return Ob_Robot;}
  /*!
   * \brief Zwraca tryb pracy w którym pracuje Obiekt_Graficzny
   */
  virtual std::string Rodzaj_Obiektu_Nazwa() const {return "Robot";}


  /*!
   * \brief Okręgi się przecinają.
   *
   * \retval true - Okręgi się przecinają 
   * \retval false - Okręgi się nie przecinają 
   */
  bool Okregi_sie_przecinaja(const std::shared_ptr<Objekt_Graficzny> &R2,const Wektor2D &Obecne_Polozenie) const;
  //bool Okregi_sie_przecinaja(Robot &R2,const Wektor2D &Obecne_Polozenie) const;

  /*!
   * \brief Punk zawiera się w prostokącie.
   *
   * \retval true - Punkt zawiera się w prostokącie 
   * \retval false - Punkt nie zawiera się w prostokącie
   */
  bool Punkt_Nalezy_Do_Prostokata(const std::shared_ptr<Objekt_Graficzny> &Pr,const Wektor2D &Obecne_Polozenie) const;
  /*!
   * \brief Okręgi się przecinają.
   *
   * \retval true - Objekty się przecinają 
   * \retval false - Objekty się nie przecinają 
   */
bool Kolizja(const  std::list<std::shared_ptr<Objekt_Graficzny>> &objekty,const Wektor2D &Obecne_Polozenie) const;

};

/*!
 * \brief Wyswietla współrzędne wierzchołków względem siebie
 *
 * Uwzględnia kąt a nie uwzględnia przesunięcia. 
 */
std::ostream& operator << (std::ostream &Strm, const Robot  &Rob);

#endif
