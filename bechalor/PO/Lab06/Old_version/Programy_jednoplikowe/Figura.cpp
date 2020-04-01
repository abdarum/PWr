
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>

#define WYMIAR_WEKTORA 2

/*!
 * \file
 *
 * \brief Definicja kalsy typu Wektor2D
 *
 * Plik zawiera deklaracje klasy Wektor2D i przeci±¿eñ operatorów
 * cout i cin dla klasy Wektor2D
 */


/*!
 *\brief Modeluje informacje dotyczace wektora
 *
 * Modeluje zestaw informacji dotyczacych wektora.
 * Udostêpnia tak¿e metody umozliwiaj±ce aktualizowanie wartosci 
 * a tak¿e zwracanie ich.
 */
class Wektor2D {
  double _wart[WYMIAR_WEKTORA];
  static int _laczna_liczba_utworzonych;
  static int _aktualna_liczba_istniejacych;
  void Aktualizuj_Statystyki(){Wektor2D::_laczna_liczba_utworzonych++; Wektor2D::_aktualna_liczba_istniejacych++;}
  
public:
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D zerami
   */    
  Wektor2D() {Aktualizuj_Statystyki(); Zeroj_Wektor();}
  /*!
   *  \brief Inicjalizyje zmienna typu Wektor2D wartosciami 
   *
   *  param[in] x_new - inicjalizuje pierwsza wspó³rzêdn± wartosci± x_new
   *  param[in] y_new - inicjalizuje drug± wspó³rzêdn± wartosci± y_new
   */    
  Wektor2D(double x_new, double y_new) {Aktualizuj_Statystyki(); _wart[0]=x_new;
 _wart[1]=y_new;}
  /*!
   * \brief Destruktor
   *
   * Po usuniêciu zmiennej zmniejsza dekrementuje liczbê aktualnie istniej±cych objektów
   */
  ~Wektor2D(){Wektor2D::_aktualna_liczba_istniejacych--;}
  /*!
   *  \brief Ustawia pierwsza wspolrzedno wektora na x_new
   */
  void Ustaw_X(double x_new){_wart[0]=x_new;}
  /*!
   *  \brief Ustawia druga wspolrzedna wektora na y_new
   */
  void Ustaw_Y(double y_new){_wart[1]=y_new;}
  /*!
   *  \brief Ustawia  wartosc wspó³rzêdnej wektora Ind na warto¶æ wart_new
   *  \param[in] wart_new - warto¶æ która ma byæ nadana wybranej wspó³rzêdnej wektora
   *  \param[in] Ind - wspó³rzêdna dla której warto¶æ ma byæ zmieniona
   *  Ind dla pierwszej wspó³rzêdnej 0, drugiej 1 itd.
   */
  void Ustaw_Wsp(double wart_new, int Ind){assert(Ind<WYMIAR_WEKTORA); _wart[Ind]=wart_new;}
  /*!
   *  \brief Ustawia  wspolrzedne wektora na odpowiednio x_new, y_new 
   */
  void Ustaw(double x_new, double y_new){_wart[0]=x_new; _wart[1]=y_new;}
  /*!
   * \brief Zwraca wartosc pierwszej wspolrzednej
   */
  double Zroc_X(){return _wart[0];}
  /*!
   * \brief Zwraca wartosc drugiej wspolrzednej
   */
  double Zwroc_Y(){return _wart[1];}
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma byæ dodany 
   */
  Wektor2D operator+ (Wektor2D Wek){for(int i=0;i<WYMIAR_WEKTORA;++i) Wek[i]+=_wart[i]; return Wek; }
  /*!
   * \brief Przeciarzenie operatra dodawania wektorów
   * 
   * \param[in] Wek Wektor jaki ma byæ dodany 
   */
  Wektor2D& operator+= (const Wektor2D& Wek){*this=*this+Wek; return *this; }
  /*!
   * \brief Przeciarzenie operatra mno¿enia wektora przez liczbê
   * 
   * \param[in] Liczba przez jak± wektor ma byæ przemno¿ony 
   */
  Wektor2D operator* (const double &Liczba) const {Wektor2D Wek=*this; for(int i=0;i<WYMIAR_WEKTORA;++i) Wek[i]*=Liczba; return Wek; }
  /*!
   * \brief Przeciarzenie operatra mno¿enia wektorów
   * 
   * \param[in] Liczba przez jak± wektor ma byæ przemno¿ony 
   */
  Wektor2D& operator*= (const double& Liczba){*this=*this*Liczba; return *this; }
  /*!
   * \brief Przeciarzenie operatra indeksowania do zwracania wartosci
   */
  double operator[] (int Ind)const { return _wart[Ind];}
  /*!
   * \brief Przeciarzenie operatra indeksowania do przypisania  wartosci
   */
  double &operator[] (int Ind) { return _wart[Ind];}
  /*!
   * \brief Funkcja wypisuje do strumienia punkty w odpowiednim formacie
   */
  void WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const;
  /*!
   * \brief Funkcja zeruje warto¶ci wektora
   */
  void Zeroj_Wektor(){for(int i=0;i< WYMIAR_WEKTORA;++i) _wart[i]=0;}
  /*!
   * \brief Funkcja zwraca liczbê istniej±cych objektów 
   */
  static  int Ile_Istnieje(){return _aktualna_liczba_istniejacych;}
  /*!
   * \brief Funkcja zwraca  ³±czn± liczbê utworzonych objektów  
   */
  static int Ile_Utworzono(){return _laczna_liczba_utworzonych;}
  /*!
   * \brief Funkcja wypisuje statystyki ile utworzono objektów a ile teraz istnieje
   */
  static void Wyswietl_Statystyki(){
    std::cout<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "<<_laczna_liczba_utworzonych<<std::endl;
    std::cout<<"      Ilosc istniejacych obiektow klasy Wektor2D: "<<_aktualna_liczba_istniejacych<<std::endl;  }
};

/*!
 *\brief Wczytuje wspó³rzêdne wektora
 *
 * Wspó³rzêdne s± pobierane w kolejno¶ci x , y
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 *\brief Wyswietla wspó³rzêdne wektora
 *
 * Wspó³rzêdne s± zwracane w kolejno¶ci x (znak tabulacji) y
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);


/*************************************************************/

class Figura {
  std::vector<Wektor2D> _figura;
public:
  Figura(){_figura.reserve(5);}
  void  Ustaw_Wartosci(Wektor2D Wart[4]){for(int i=0;i<4;++i) _figura.push_back(Wart[i]);}
  Wektor2D Zwroc(int Ind){return _fig[Ind}
  int Size(){return _figura.size();}
  
};

class Kwadrat: public Figura
{
  double odl[2];
  std::vector<Figura> _kwadrat; 
public:
  float Oblicz_Pole()
  {
    for(int k=0;k<_kwadrat.size();i++)
      for(int i=0;i<_kwadrat[k].Size();i+=2)
	odl[i/2]=(sqrt(pow(_kwadrat[k].Zwroc()[i%2]-_kwadrat[k].Zwroc()[i%2+1],2)+pow((_kwadrat[k].Zwroc()[i%2]-_kwadrat[k].Zwroc()[i%2+1],2)));

  }

  
};

/*************************************************************/

int main()
{


}


/*************************************************************/

void Wektor2D::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< _wart[i];
  StrmWy<<std::endl;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    std::cin>>Wek[i];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    Strm<<std::setw(16)<<std::fixed<<std::setprecision(10)<< Wek[i];
  return Strm;
}
