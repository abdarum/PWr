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

/*
bool Scena::Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka &Sciezka_Animowana,Robot &Robot_Animowany,double dlugosc,int microseconds)
{
  std::ofstream  StrmPlikowy;
  
  Sciezka_Animowana.Przygotuj_Animacje_Sciezki(Robot_Animowany,dlugosc);

  while(!Sciezka_Animowana.Koniec_Animacji())
    { 
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
 

 ////////////////////////////////////////////////////////////////
      for (std::vector<Robot>::iterator it=Rob.begin(); it != Rob.end(); ++it)
	//	if(it!=&Robot_Animowany)
	  {
	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }
      
      for(unsigned int i=0;i<Sciez.size();++i)
      //      for (std::vector<Sciezka>::iterator it=Sciez.begin(); it != Sciez.end(); ++it)
	if(&Sciez[i]!=&Sciezka_Animowana)
	  //	if(it!=&Sciezka_Animowana)
	  {
	    Sciez[i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    //	    (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }

      //      for (std::vector<Przeszkoda>::iterator it=Przeszk.begin(); it != Przeszk.end(); ++it)
      for(unsigned int i=0;i<Przeszk.size();++i)
	{
	  //	  (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  Przeszk[i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
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
*/
bool Scena::Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Robot *Robot_Animowany,double dlugosc,int microseconds)
{
  std::ofstream  StrmPlikowy;
  /*
  std::cout<<&Robot_Animowany<<std::endl<<std::endl;
  for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); (it != Ob_List.end()) || (&*it!= &Robot_Animowany); ++it) 
    // (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
    std::cout<<it<<std::endl;
*/

  std::cout<<Robot_Animowany<<std::endl<<std::endl;
  for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it)
    {
      if((*it)->Rodzaj_Obiektu()==Ob_Robot)
	std::cout<<(*it)->Wektor_Translacji()<<std::endl;
      std::cout<<&(*it)<<std::endl;
    }


	  
  std::shared_ptr<Robot> Rob_ptr (Robot_Animowany);
  //  (&Rob_ptr+1)->Przygotuj_Animacje_Sciezki(Robot_Animowany,dlugosc);

  /*
  while(!Sciezka_Animowana.Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }

      for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
	if(it!=&Robot_Animowany || it!=(&Robot_Animowany+1))
	  {
	    (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    StrmPlikowy<<std::endl;
	  }
 

      *(Robot_Animowany+1).Animacja_Sciezki_Z_Robotem(StrmPlikowy,Robot_Animowany);
     
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    } 
  */
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
      
      Sciezka_Animowana.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
      StrmPlikowy<<std::endl;
  
      for(unsigned int i=0;i<Przeszk.size();++i)
	{
	  Przeszk[i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  StrmPlikowy<<std::endl;
	}
            
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
