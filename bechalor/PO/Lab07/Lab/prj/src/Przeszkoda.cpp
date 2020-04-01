#include "Przeszkoda.hh"


void Przeszkoda::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<(Objekt_Graficzny::Rozmiar()+1);++i){
    Objekt_Graficzny::Wartosc_Glob(i%Objekt_Graficzny::Rozmiar()).WyswietlWspolrzedneFormatGnuplot(StrmWy);
  }
}
