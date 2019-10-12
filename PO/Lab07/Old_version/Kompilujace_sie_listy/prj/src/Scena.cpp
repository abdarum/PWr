#include "Scena.hh"



bool Scena::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku)
{
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }

  for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
    {
      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
      StrmPlikowy<<std::endl;
    }
   
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


bool Scena::Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka &Sciezka_Animowana, Robot &Robot_Animowany,double dlugosc,int microseconds)
{
  std::ofstream  StrmPlikowy;
  
  Sciezka_Animowana.Przygotuj_Animacje_Sciezki(Robot_Animowany,Ob_List,dlugosc);

  while(!Sciezka_Animowana.Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }

 ////////////////////////////////////////////////////////////////
      for (std::vector<Robot>::iterator it=Rob.begin(); it != Rob.end(); ++it)
	if(&(*it)!=&Robot_Animowany)
	  {
	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }
      
      for (std::vector<Sciezka>::iterator it=Sciez.begin(); it != Sciez.end(); ++it)
	if(&*it!=&Sciezka_Animowana)
	  {
	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }

      for (std::vector<Przeszkoda>::iterator it=Przeszk.begin(); it != Przeszk.end(); ++it)
	{
	  (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  StrmPlikowy<<std::endl;
	}
 ///////////////////////////////////////////////////////////////////
      Sciezka_Animowana.Animacja_Sciezki_Z_Robotem(StrmPlikowy,Robot_Animowany);
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    }
  return !StrmPlikowy.fail();
}




bool Scena::Animacja_Obrotu_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka &Sciezka_Animowana,Robot &Robot_Animowany,int microseconds,double a)
{
  std::ofstream  StrmPlikowy;
  
  while(!Robot_Animowany.Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }


 ////////////////////////////////////////////////////////////////
      for (std::vector<Robot>::iterator it=Rob.begin(); it != Rob.end(); ++it)
	if(&(*it)!=&Robot_Animowany)
	  {
	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }
      
      for (std::vector<Sciezka>::iterator it=Sciez.begin(); it != Sciez.end(); ++it)
	  {
	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }

      for (std::vector<Przeszkoda>::iterator it=Przeszk.begin(); it != Przeszk.end(); ++it)
	{
	  (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  StrmPlikowy<<std::endl;
	}
 ///////////////////////////////////////////////////////////////////
      
            
      Robot_Animowany.Animacja_Obrotu_Robota(StrmPlikowy,a);
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    }
  return !StrmPlikowy.fail();
}


void Scena::Dodaj_Robota(Wektor2D Wsp_Globalne, double Kat_Obrotu)
{
  Rob.push_back(Robot(Wsp_Globalne, Kat_Obrotu)); 
  Ob_List.push_back(std::make_shared<Robot> (Rob.back()));
  Sciez.push_back(Sciezka());
  Ob_List.push_back(std::make_shared<Sciezka> (Sciez.back()));
}

void Scena::Dodaj_Przeszkode(std::vector<double> Wspolrzedne_Wierzcholkow)
{
  Przeszk.push_back(Przeszkoda(Wspolrzedne_Wierzcholkow)); 
  Ob_List.push_back(std::make_shared<Przeszkoda> (Przeszk.back()));
}

void Scena::Wyswietl_Typy_Objektow()
{
  for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
    std::cout<<(*it)->Rodzaj_Obiektu_Nazwa()<<std::endl;  
}


void Scena::Wyswietl_Wspolrzedne_Objektow()
{
  for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it)
    {
      (*it)->WyswietlWspolrzedneFormatGnuplot(std::cout);
      std::cout<<std::endl;
    }
}


/*
bool Scena::Okregi_sie_przecinaja(Robot &R1,Robot &R2) const
{
  double Odleglosc_Robotow=0;
  Odleglosc_Robotow=R1.Wektor_Translacji().Odleglosc_Wektorow(R2.Wektor_Translacji());
  if(R1.Promien()+R2.Promien()<=Odleglosc_Robotow)
    return true;
  else
    return false;
}



bool Scena::Punkt_Nalezy_Do_Prostokata(Robot &R1,Przeszkoda &Pr) const
{
  if( (R1.Wektor_Translacji()[0] >= Pr.Min_X()-R1.Promien()) && (R1.Wektor_Translacji()[0] <= Pr.Min_X()+R1.Promien()) )
    if( (R1.Wektor_Translacji()[1] >= Pr.Min_Y()-R1.Promien()) && (R1.Wektor_Translacji()[1] <= Pr.Min_Y()+R1.Promien()) )
      return true;
  return false;
}
*/
