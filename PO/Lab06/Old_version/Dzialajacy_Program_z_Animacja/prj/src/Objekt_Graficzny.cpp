#include "Objekt_Graficzny.hh"

void Objekt_Graficzny::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<(_wsp_lokalne.Rozmiar()+1);++i)
    (_wsp_lokalne[i%_wsp_lokalne.Rozmiar()]+_wsp_globalne).WyswietlWspolrzedneFormatGnuplot(StrmWy);
}



std::ostream& operator << (std::ostream &Strm, const Objekt_Graficzny  &Obj_Graf)
{
  std::cout<<"Wierzcholki lokalne:   ";
  for(int i=0;i<Obj_Graf.Rozmiar();++i)
    std::cout<<(i==0?"":"                       ")<<Obj_Graf[i]<<std::endl;
  std::cout<<"Wspolrzedne globalne:  "<<Obj_Graf.Wsp_Glob()<<std::endl;
  std::cout<<"Kat obrotu:            "<<"    "<<Obj_Graf.Kat()<<std::endl;
  return Strm;
}
