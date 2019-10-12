#include "Sciezka.hh"

void Sciezka::Jedz_Prosto(Robot& Rob,double dlugosc)
{
  Wektor2D Wektor(1,0);
  Wektor=Macierz2x2(Rob.Kat_Obrotu())*Wektor;

  Wektor*=dlugosc;
  _punkty.push_back(_punkty.back()+Wektor);
  Rob.Ustaw_Wsp_Globalne(_punkty.back());

}

void Sciezka::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for (std::vector<Wektor2D>::const_iterator it = _punkty.begin() ; it != _punkty.end(); ++it)
    StrmWy<<*it<<std::endl; 
}

void Sciezka::Animacja_Sciezki(const Robot& Rob,double dlugosc,int microseconds,std::ostream& StrmWy)
{
  Wektor2D tmp(0,0);
  Wektor2D Wektor(1,0);
  double odl=0;
  Wektor=Macierz2x2(Rob.Kat_Obrotu())*Wektor;
  if(_punkty.size()>1) tmp=*(_punkty.rbegin() - 1); else tmp=*_punkty.rbegin(); 
  Wektor*=dlugosc;

  if(_punkty.size()>1)
    {
      for (std::vector<Wektor2D>::const_iterator it = _punkty.begin() ; it !=(_punkty.end()-1); ++it)
	StrmWy<<*it<<std::endl; 
      odl=(sqrt(pow((tmp[0]-_punkty.back()[0]),2)+pow((tmp[1]-_punkty.back()[1]),2)));
      while(odl>std::numeric_limits<double>::epsilon())
	{
	  if(odl>dlugosc)
	    tmp.WyswietlWspolrzedneFormatGnuplot(StrmWy); 
	  else
	    _punkty.back().WyswietlWspolrzedneFormatGnuplot(StrmWy); 
	  odl=(sqrt(pow((tmp[0]-_punkty.back()[0]),2)+pow((tmp[1]-_punkty.back()[1]),2)));
	  tmp+=Wektor;
	  usleep(microseconds);
	}
    }
  else
    StrmWy<<_punkty.back()<<std::endl; 
   
}

/*
std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez)
{
  for (std::vector<Wektor2D>::iterator it = Sciez._punkty.begin() ; it != Sciez._punkty.end(); ++it)
    std::cout<<*it<<std::endl; 
  return Strm;
}
*/
