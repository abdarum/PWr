#include "Sciezka.hh"

void Sciezka::Jedz_Prosto(Robot& Rob,double dlugosc)
{
  if(Rob.Wektor_Translacji().Odleglosc_Wektorow(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1))>std::numeric_limits<double>::epsilon()&&Objekt_Graficzny::Rozmiar()==1)
    Objekt_Graficzny::Wartosc_Lok(0,Rob.Wektor_Translacji());

  //Obroc wektor jednostkowy o kat o przemnoz przez dlugosc obrotu
  Wektor2D Wektor(1,0);
  Wektor=Macierz2x2(Rob.Kat())*Wektor;
  Wektor*=dlugosc;

  //Ustaw wierzcholek jako ostatni + wektor przesuniecia 
  //Ustaw to tez jako wektor translacji
  Objekt_Graficzny::Ustaw(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1)+Wektor);
  Rob.Wektor_Translacji(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1));

}

void Sciezka::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{

  for(int i=0;i<Objekt_Graficzny::Rozmiar();++i){
    Objekt_Graficzny::Wartosc_Glob(i).WyswietlWspolrzedneFormatGnuplot(StrmWy);
  }
}

void Sciezka::Przygotuj_Animacje_Sciezki(Robot& Rob,const  std::list<std::shared_ptr<Objekt_Graficzny>> &objekty,double dlugosc)
{

  //Zerowanie parametrów dotyczących animacji
  _obecny_punkt=0;
  Objekt_Graficzny::Koniec_Animacji(false);
  _punkty_posrednie.clear();
  Rob.Wektor_Translacji(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-2));
  //Parametry potrzebne do utworzenia punktów pośrednich
  Wektor2D tmp(0,0);
  Wektor2D Wektor(1,0);
  double odl=0;
  Wektor=Macierz2x2(Rob.Kat())*Wektor;
  Wektor*=dlugosc;

  
  //Jezeli jest więcej punktów ścieżki niż jeden
  if(Objekt_Graficzny::Rozmiar()>1)
    {
      //Dodaj pierwszy punkt
      _punkty_posrednie.push_back(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-2));
      odl=Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1).Odleglosc_Wektorow(_punkty_posrednie.back());
      
      //Jeżeli odległość miedzy nimi jest większa niż odległość zadana
      for(;odl>dlugosc;)
	{
	  //Dodaj punkt przesuniety o długość do punktów pośrednich
	  
	  if(Rob.Kolizja(objekty,_punkty_posrednie.back()+Wektor))
	    {
	      //	      std::cout<<"Kolizja"<<std::endl;
	      
	      Rob.Wektor_Translacji(_punkty_posrednie.back());
	      odl=0;
	      Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1,_punkty_posrednie.back());
	      }
	  else
	  
	    {
	      _punkty_posrednie.push_back(_punkty_posrednie.back()+Wektor);
	      odl=Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1).Odleglosc_Wektorow(_punkty_posrednie.back());
	    }
	}
      //Dodaj końcowy punkt
      _punkty_posrednie.push_back(Objekt_Graficzny::Wartosc_Lok(Objekt_Graficzny::Rozmiar()-1));
    } 

 
}

void Sciezka::Animacja_Sciezki_Z_Robotem(std::ostream& StrmWy,Robot& Rob)
{
for(int i=0;i<Objekt_Graficzny::Rozmiar()-1;++i)
       Objekt_Graficzny::Wartosc_Glob(i).WyswietlWspolrzedneFormatGnuplot(StrmWy);
 if(_obecny_punkt<_punkty_posrednie.size())
   {   
     (_punkty_posrednie[_obecny_punkt]+Wsp_Glob()).WyswietlWspolrzedneFormatGnuplot(StrmWy);     
     StrmWy<<std::endl;
     Rob.Wektor_Translacji(_punkty_posrednie[_obecny_punkt]);
     Rob.WyswietlWspolrzedneFormatGnuplot(StrmWy);
     //     std::cout<<_punkty_posrednie[_obecny_punkt]<<'\t';
     
     
     //     std::cout<<_obecny_punkt<<std::endl;
     _obecny_punkt++;
   }
 else
   {
     Objekt_Graficzny::Koniec_Animacji(true);
     Objekt_Graficzny::Wartosc_Glob(Objekt_Graficzny::Rozmiar()-1).WyswietlWspolrzedneFormatGnuplot(StrmWy);
     StrmWy<<std::endl;
     Rob.WyswietlWspolrzedneFormatGnuplot(StrmWy);
   }
}


std::ostream& operator << (std::ostream &Strm, const Sciezka  &Sciez)
{
  Sciez.Wyswietl();
  return Strm;
}

