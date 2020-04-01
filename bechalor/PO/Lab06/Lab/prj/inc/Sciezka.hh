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
class Sciezka: public Objekt_Graficzny
{
  std::vector<Wektor2D> _punkty_posrednie;
  unsigned int _obecny_punkt;
public:
  /*!
   * \brief Funkcja odpowiada obliczenie punktu docelowego ruchu
   */
  Sciezka(){Objekt_Graficzny();Objekt_Graficzny::Ustaw(std::vector<double>{0,0});_obecny_punkt=0;}
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
 
  Sciezka(std::vector<double> Wspolrzedne_Wierzcholkow,const Wektor2D &Wspolrzedne_Globalne,const double &Kat_Obrotu){Objekt_Graficzny(Wspolrzedne_Wierzcholkow,Wspolrzedne_Globalne,Kat_Obrotu);_obecny_punkt=0;}
  // Objekt_Graficzny(std::vector<double> Wspolrzedne_Wierzcholkow,Wektor2D Wspolrzedne_Globalne,double Kat_Obrotu){ _wsp_lokalne=ZbiorWierzcholkow(Wspolrzedne_Wierzcholkow); _wsp_globalne=Wspolrzedne_Globalne; _kat=Kat_Obrotu;}
  /*!
   * \brief Inicjalizacja zmiennej typu ZbiorWierzcholkow wartosciami
   *
   * Każdy wierzchołek jest oreślony jako wektor
   *
   * \param[in] Wierzcholki ustawia parametry wspolrzednych
   *                        wierzcholkow. 
   * \param[in] Wspolrzedne_Globalne Współrzędne globalne 
   * \param[in]  Kat_Obrotu Kąt obrotu o jaki obrócić wierzchołki względem 
   *                        domyślego położenia
   */
  Sciezka(std::vector<Wektor2D> Wierzcholki,const Wektor2D &Wspolrzedne_Globalne,const double &Kat_Obrotu){Objekt_Graficzny(Wierzcholki,Wspolrzedne_Globalne,Kat_Obrotu);_obecny_punkt=0;}
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
   * \brief Funkcja przygotowuje punkty pod animację
   *
   * \param[in] Rob - kalsa robot z której pobierany jest kąt
   * \param[in] dlugosc - długość kroku, ma duży wpływ na prędkość animacji
   */
  void Przygotuj_Animacje_Sciezki(Robot& Rob,double dlugosc=1);
  /*!
   * \brief Funkcja wypisuje kolejne punkty posrednie do strumienia tworząc 
   *         animację robota i ścieżki
   *
   * \param[in] StrmWy - strumień do którego mają być wypisane wierzchołki
   * \param[in] Rob - Robot, którego ścieżka będzie animowana
   * \param[in] Ind - Numer punktu tymczasowego
   */
  void Animacja_Sciezki_Z_Robotem(std::ostream& StrmWy,Robot& Rob);
  /*!
   * \brief Funkcja zwraca łączną długość ścieżki
   */
  double Laczna_Dlugosc_Sciezki(){
    double dlugosc=0;
    for(int i=0;i<(Objekt_Graficzny::Rozmiar()-1);++i)
      dlugosc+=Objekt_Graficzny::Wartosc_Lok(i).Odleglosc_Wektorow(Objekt_Graficzny::Wartosc_Lok(i+1));
    return dlugosc;
  }
};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
//std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez);

#endif
