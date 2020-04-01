#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <fstream>
#include <vector>
#include <limits>
#include <cmath>
#include <iostream>
#include "Wektor2D.hh"

/*!
 * \file
 *
 * \brief Deklaracja klasy typu ZbiorWierzcholkow
 *
 * Plik zawiera deklaracje klasy ZbiorWierzcholkow
 */

/*!
 *\brief Modeluje informacje dotyczace zbioru wierzchołkow
 *
 * Modeluje zestaw informacji dotyczacych zbioru wierzchołków.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class ZbiorWierzcholkow {
  std::vector<Wektor2D> _zb_wierzcholkow;

  public:
  /*!
   * \brief Inicjalizacja zmiennej typu ZbiorWierzcholkow  
   */
  ZbiorWierzcholkow(){ _zb_wierzcholkow.reserve(6); }
  /*!
   * \brief Inicjalizacja zmiennej typu ZbiorWierzcholkow wartosciami
   *
   * \param[in] Wspolrzedne_Wierzcholkow ustawia parametry wspolrzednych
   *                        wierzcholkow. Należy podać je w kolejności:
   *                        WspX_Wierzch1 WspY_Wierzch1 WspX_Wierzch2 ...
   */
  ZbiorWierzcholkow(std::vector<double> Wspolrzedne_Wierzcholkow){ZbiorWierzcholkow(); Ustaw(Wspolrzedne_Wierzcholkow);}
  /*!
   * \brief Inicjalizacja zmiennej typu ZbiorWierzcholkow wartosciami
   *
   * Każdy wierzchołek jest oreślony jako wektor
   *
   * \param[in] Wierzcholki ustawia parametry wspolrzednych
   *                        wierzcholkow. 
   */
  ZbiorWierzcholkow(std::vector<Wektor2D> Wierzcholki){ ZbiorWierzcholkow(); Ustaw(Wierzcholki);}
 /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wspolrzedne_Wierzcholkow ustawia parametry wspolrzednych
   *                        wierzcholkow. Należy podać je w kolejności:
   *                        WspX_Wierzch1 WspY_Wierzch1 WspX_Wierzch2 ...
   */
  void Ustaw(std::vector<double> Wspolrzedne_Wierzcholkow){for(unsigned int i=0;i<Wspolrzedne_Wierzcholkow.size();i+=2) _zb_wierzcholkow.push_back(Wektor2D(Wspolrzedne_Wierzcholkow[i],Wspolrzedne_Wierzcholkow[i+1]));}
  /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wierzcholek Wierzchołek, który ma być dodany na koniec
   *                           powinien być typu Wektor2D
   */
  void Ustaw(Wektor2D Wierzcholek){ ZbiorWierzcholkow(); _zb_wierzcholkow.push_back(Wierzcholek);}
  /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wierzcholki Wierzchołki, które mają być kolejno dodane
   *                           powinny być typu Wektor2D
   */
  void Ustaw(std::vector<Wektor2D> Wierzcholki){ ZbiorWierzcholkow(); _zb_wierzcholkow.insert(_zb_wierzcholkow.end(),Wierzcholki.begin(),Wierzcholki.end());}
  /*!
   * /brief Znajdz długości przeciwległych bokow
   */
  //  void DlugosciBokow() const;
  /*!
   * \brief Zwraca liczbę istniejących wierzchołków 
   */
  int Rozmiar() const{return _zb_wierzcholkow.size();}
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  Wektor2D operator[] (int Ind)const { return _zb_wierzcholkow[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  Wektor2D &operator[] (int Ind) { return _zb_wierzcholkow[Ind];}
  /*!
   * \brief Usuwa wybraną ilość elementów od końca
   *
   * \param[in] Liczba_elementow Ile ostatnich elementów usunąć
   */
  void Usun_Elementy(int Liczba_elementow){for(int i=0;i<Liczba_elementow;++i)_zb_wierzcholkow.pop_back();}
  /*!
   * \brief Usuwa wszystkie elementy 
   */
  void Usun_Elementy(){_zb_wierzcholkow.clear();}
  /*!
   * \brief Zwraca współrzędne wierzchołka Ind
   */
  Wektor2D Wartosc(int Ind) const{return _zb_wierzcholkow[Ind];}
  /*!
   * \brief Zapisuje wspolrzedne do pliku w formacie zgodnym z Gnuplotem 
   *
   * Funkcja jest niewielką modyfikacją funkcji "PrzykladZapisuWspolrzednychDoPliku" z pliku main dostarczonego w folderze zalazek
   */
  bool ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku) const;
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;

};

/*!
 * \brief Wyswietla współrzędne ZbiorWierzcholkow
 */
std::ostream& operator << (std::ostream &Strm, const ZbiorWierzcholkow &Zb_Wierzch);


#endif
