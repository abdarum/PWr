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

double Objekt_Graficzny::Max_X() const
{
  std::vector<double> tmp;
  for(int i=0;i<Rozmiar();++i)
    tmp.push_back(Wartosc_Glob(i)[0]);
  std::sort(tmp.begin(),tmp.end());
  return tmp.back();
}

double Objekt_Graficzny::Min_X() const
{
  std::vector<double> tmp;
  for(int i=0;i<Rozmiar();++i)
    tmp.push_back(Wartosc_Glob(i)[0]);
  std::sort(tmp.begin(),tmp.end());
  return tmp.front();
}

double Objekt_Graficzny::Max_Y() const
{
  std::vector<double> tmp;
  for(int i=0;i<Rozmiar();++i)
    tmp.push_back(Wartosc_Glob(i)[1]);
  std::sort(tmp.begin(),tmp.end());
  return tmp.back();
}

double Objekt_Graficzny::Min_Y() const
{
  std::vector<double> tmp;
  for(int i=0;i<Rozmiar();++i)
    tmp.push_back(Wartosc_Glob(i)[1]);
  std::sort(tmp.begin(),tmp.end());
  return tmp.front();
}
