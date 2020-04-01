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


double Robot::Promien() const   
{
  std::vector<double> odl;
  Wektor2D Wektor_Zerowy;
  for(int i=0;i<Objekt_Graficzny::Rozmiar();++i)
    odl.push_back(Wektor_Zerowy.Odleglosc_Wektorow(Objekt_Graficzny::Wartosc_Glob(i)));
  std::sort(odl.begin(),odl.end());
  return odl.back();
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




/*
bool Robot::Okregi_sie_przecinaja(Robot &R2,const Wektor2D &Obecne_Polozenie) const
{
  double Odleglosc_Robotow=0;
  Odleglosc_Robotow=Obecne_Polozenie.Odleglosc_Wektorow(R2.Wektor_Translacji());
  if(Promien()+R2.Promien()<=Odleglosc_Robotow)
    return true;
  else
    return false;
}
*/


//////////////// Nie dziala na wskaznikach ///////////////////

bool Robot::Okregi_sie_przecinaja(const std::shared_ptr<Objekt_Graficzny> &R2,const Wektor2D &Obecne_Polozenie) const
{
  double Odleglosc_Robotow=0;
  Odleglosc_Robotow=Obecne_Polozenie.Odleglosc_Wektorow(R2->Wektor_Translacji());
  if(Promien()+R2->Promien()<=Odleglosc_Robotow)
    return true;
  else
    return false;
}




bool Robot::Punkt_Nalezy_Do_Prostokata(const std::shared_ptr<Objekt_Graficzny> &Pr,const Wektor2D &Obecne_Polozenie) const
{
  if( (Obecne_Polozenie[0] >= Pr->Min_X()-Promien()) && (Obecne_Polozenie[0] <= Pr->Min_X()+Promien()) )
    if( (Obecne_Polozenie[1] >= Pr->Min_Y()-Promien()) && (Obecne_Polozenie[1] <= Pr->Min_Y()+Promien()) )
      return true;
  return false;
}



bool Robot::Kolizja(const  std::list<std::shared_ptr<Objekt_Graficzny>> &objekty,const Wektor2D &Obecne_Polozenie) const
{
  for(const std::shared_ptr<Objekt_Graficzny> &wsk : objekty ) 
        
    if( &(*wsk) != this ){
      if( wsk->Rodzaj_Obiektu() == Ob_Robot )
	{
	  //	  if(Okregi_sie_przecinaja(*wsk,Obecne_Polozenie) )
	  if(Okregi_sie_przecinaja(wsk,Obecne_Polozenie) )
	    return true;
	}
      else 
	
	if( wsk->Rodzaj_Obiektu() == Ob_Przeszkoda )
	  if (Punkt_Nalezy_Do_Prostokata(wsk,Obecne_Polozenie) )
	    std::cout<<" !!! Kolizja !!! "<<std::endl;
	    return true;

      
    }
  return false;
}
