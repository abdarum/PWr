#include "Robot.hh"


void Robot::Animacja_Obrotu_Robota(std::ostream& StrmWy,double a)
{
  Wektor2D tmp;
  if(Objekt_Graficzny::Koniec_Animacji()!=true)
    {
      if(Objekt_Graficzny::Kat()-_poprzedni_kat>a)
	{
	  Objekt_Graficzny::Usun_Elementy();
	  Objekt_Graficzny::Ustaw(Domyslne_Wartosci);
	  for(int i=0;i<Objekt_Graficzny::Rozmiar();++i)
	    {    
	      tmp=Macierz2x2(_poprzedni_kat)*Objekt_Graficzny::Wartosc_Lok(i);
	      Objekt_Graficzny::Wartosc_Lok(i,tmp);
	    }
	  WyswietlWspolrzedneFormatGnuplot(StrmWy);
	  _poprzedni_kat+=a;
	}
      else
	{
	  Objekt_Graficzny::Koniec_Animacji(true);
	  _poprzedni_kat=Objekt_Graficzny::Kat();
	  Objekt_Graficzny::Usun_Elementy();
	  Objekt_Graficzny::Ustaw(Domyslne_Wartosci);
	  for(int i=0;i<Objekt_Graficzny::Rozmiar();++i)
	    {    
	      tmp=Macierz2x2(_poprzedni_kat)*Objekt_Graficzny::Wartosc_Lok(i);
	      Objekt_Graficzny::Wartosc_Lok(i,tmp);
	    }
	  WyswietlWspolrzedneFormatGnuplot(StrmWy);
	} 
    }
}


void Robot::ObrocOKat(double a)
{
  Wektor2D tmp;
  _poprzedni_kat=Objekt_Graficzny::Kat();
  Objekt_Graficzny::Koniec_Animacji(false);

  Objekt_Graficzny::Usun_Elementy();
  Objekt_Graficzny::Ustaw(Domyslne_Wartosci);
  Objekt_Graficzny::Kat(Objekt_Graficzny::Kat()+a);
  Objekt_Graficzny::Kat(fmod(Objekt_Graficzny::Kat(),360.0));
  for(int i=0;i<Objekt_Graficzny::Rozmiar();++i)
    {    
      tmp=Macierz2x2(Objekt_Graficzny::Kat())*Objekt_Graficzny::Wartosc_Lok(i);
      // Objekt_Graficzny::Wartosc_Lok(i,Macierz2x2(Objekt_Graficzny::Kat())*(Objekt_Graficzny::Wartosc_Lok(i)));
      Objekt_Graficzny::Wartosc_Lok(i,tmp);
    }
}

std::ostream& operator << (std::ostream &Strm, const Robot &Rob)
{
  for(int i=0;i<Rob.Rozmiar();++i)
    std::cout<<(Rob.Wartosc_Glob(i)+Rob.Wektor_Translacji())<<std::endl; 
  return Strm;
}


void Robot::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<(Objekt_Graficzny::Rozmiar()+1);++i){
    (Wektor_Translacji()+Objekt_Graficzny::Wartosc_Glob(i>=Objekt_Graficzny::Rozmiar()?(i%Objekt_Graficzny::Rozmiar())+1:i)).WyswietlWspolrzedneFormatGnuplot(StrmWy);
  }

}

bool Robot::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku)
{
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
