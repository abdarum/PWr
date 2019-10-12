#ifndef OBJEKT_GRAFICZNY_HH
#define OBJEKT_GRAFICZNY_HH

#include "ZbiorWierzcholkow.hh"
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
  ZbiorWierzcholkow _wsp_lokalne;
  static  Wektor2D _wsp_globalne;
  bool _koniec_animacji;
  double _kat;
public:
  /*!
   * \brief Inicjalizacja Obiektu graficznego
   */
  Objekt_Graficzny(){_kat=0; _wsp_lokalne=ZbiorWierzcholkow(); _wsp_globalne=Wektor2D();}
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
 
  Objekt_Graficzny(std::vector<double> Wspolrzedne_Wierzcholkow,const Wektor2D &Wspolrzedne_Globalne,const double &Kat_Obrotu){ _wsp_lokalne.Ustaw(Wspolrzedne_Wierzcholkow); _wsp_globalne=Wspolrzedne_Globalne; _kat=Kat_Obrotu;}
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
  Objekt_Graficzny(std::vector<Wektor2D> Wierzcholki,const Wektor2D &Wspolrzedne_Globalne,const double &Kat_Obrotu){_wsp_lokalne.Ustaw(Wierzcholki); _wsp_globalne=Wspolrzedne_Globalne; _kat=Kat_Obrotu;}
  /*!
   * \brief Zwraca liczbę istniejących wierzchołków 
   */
  int Rozmiar() const{return _wsp_lokalne.Rozmiar();}
  /*!
   * \brief Zwraca ustawiony kąt obrotu 
   */
  double Kat() const{return _kat;}
  /*!
   * \brief Ustawia kąt obrotu 
   */
  void Kat(const double &Kat_Obrotu) {_kat=Kat_Obrotu;}
 /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wspolrzedne_Wierzcholkow ustawia parametry wspolrzednych
   *                        wierzcholkow. Należy podać je w kolejności:
   *                        WspX_Wierzch1 WspY_Wierzch1 WspX_Wierzch2 ...
   */
  void Ustaw(std::vector<double> Wspolrzedne_Wierzcholkow){_wsp_lokalne.Ustaw(Wspolrzedne_Wierzcholkow);}
  /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wierzcholek Wierzchołek, który ma być dodany na koniec
   *                           powinien być typu Wektor2D
   */
  void Ustaw(Wektor2D Wierzcholek){ ZbiorWierzcholkow(); _wsp_lokalne.Ustaw(Wierzcholek);}
  /*!
   * \brief Dodaje kolejne wierzchołki
   *
   * \param[in] Wierzcholki Wierzchołki, które mają być kolejno dodane
   *                           powinny być typu Wektor2D
   */
  void Ustaw(std::vector<Wektor2D> Wierzcholki){ _wsp_lokalne.Ustaw(Wierzcholki);}
  /*!
   * \brief Ustawia współrzędne globalne 
   */
  static void Wsp_Glob(const Wektor2D &Wspolrzedne_Globalne){ _wsp_globalne=Wspolrzedne_Globalne;}
  /*!
   * \brief Ustawia współrzędne globalne 
   */
  static Wektor2D Wsp_Glob(){return _wsp_globalne;}
  /*!
   * \brief Usuwa wybraną ilość elementów od końca
   *
   * \param[in] Liczba_elementow Ile ostatnich elementów usunąć
   */
  void Usun_Elementy(int Liczba_elementow){_wsp_lokalne.Usun_Elementy(Liczba_elementow);}
  /*!
   * \brief Usuwa wszystkie elementy 
   */
  void Usun_Elementy(){_wsp_lokalne.Usun_Elementy();}
  /*!
   * \brief Zwraca lokalne współrzędne wierzchołka Ind
   */
  Wektor2D Wartosc_Lok(int Ind) const{return _wsp_lokalne[Ind];}
  /*!
   * \brief Ustawia lokalną wartosc wierzcholka nr Ind
   *
   * \param[in] Ind Wierzchołek, którego wartość ma być zmieniona
   * \param[in] Wek Wektor na jaki ma być zmieniony wierzchołek
   */
  void Wartosc_Lok(int Ind,const Wektor2D &Wek){_wsp_lokalne[Ind]=Wek;}
  /*!
   * \brief Zwraca globalne współrzędne wierzchołka Ind
   */
  Wektor2D Wartosc_Glob(int Ind) const{return _wsp_lokalne[Ind]+_wsp_globalne;}
  /*!
   * \brief Ustawia globalne wartosc wierzcholka nr Ind
   *
   * \param[in] Ind Wierzchołek, którego wartość ma być zmieniona
   * \param[in] Wek Wektor na jaki ma być zmieniony wierzchołek
   */
  void Wartosc_Glob(int Ind,Wektor2D Wek){_wsp_lokalne[Ind]=(Wek-_wsp_globalne);}
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   *
   * Wartość zwracana z uwzględnieniem położenia globalnego
   */
  Wektor2D operator[] (int Ind)const { return _wsp_lokalne[Ind]+_wsp_globalne;}
  /*!
   * \brief Funkcja wypisuje do strumienia właściwości klasy
   */
  void Wyswietl() const{std::cout<<this;}
  /*!
   * \brief Funkcja informuje czy nastąpił koniec animacji
   *
   * \retval true - Jeżeli nastąpił koniec animacji
   * \retval false - Jeżeli jeszcze nie nastąpił koniec animacji
   */
  bool Koniec_Animacji(){return _koniec_animacji;}
  /*!
   * \brief Funkcja ustawia flagę końca animacji
   *
   * \retval true - Jeżeli nastąpił koniec animacji
   * \retval false - Jeżeli jeszcze nie nastąpił koniec animacji
   */
  void Koniec_Animacji(bool Nastapil_Koniec){_koniec_animacji=Nastapil_Koniec;}
  /*!
   * \brief Funkcja informuje czy nastąpiła kolizja
   *
   * \retval true - Jeżeli nastąpiła kolizja
   * \retval false - Jeżeli nie nastąpiła kolizja
   */
  virtual bool Kolizja(){return false;}
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  virtual void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;

};


/*!
 * \brief Wyswietla współrzędne wierzchołków ścieżki
 */
std::ostream& operator << (std::ostream &Strm, const Objekt_Graficzny  &Obj_Graf);

#endif
