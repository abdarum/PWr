
#include "Scena.hh"

Scena::Scena(PzG::LaczeDoGNUPlota &Lacze): Fab()
{
  //  Scena_programu.Rob[0].Wektor_Translacji(Wektor2D(25,25));
  
  
  //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "robot.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Punktowy,0);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.UstawZakresX(0,300);
  Lacze.UstawZakresY(0,200);

  Ustaw_Objekty();
}

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
      /*
      if((*it)->Rodzaj_Obiektu() == Ob_Robot)
	{
	  std::shared_ptr<Robot> Dodany_Robot;
	  Dodany_Robot=std::dynamic_pointer_cast<Robot>(*it); 
	  Dodany_Robot->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  std::cout<<"Robot"<<std::endl;
	}
      if((*it)->Rodzaj_Obiektu() == Ob_Sciezka)
	{
	  std::cout<<"Sciezka"<<std::endl;
	  (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	}
      if((*it)->Rodzaj_Obiektu() == Ob_Przeszkoda)
	{
	  (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	  std::cout<<"Przeszkoda"<<std::endl;
	}
*/
      //std::cout<<(*it)->Rodzaj_Obiektu_Nazwa()<<std::endl;
      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
      StrmPlikowy<<std::endl<<std::endl;
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
      for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
	{   
	  
	  if((*it)->Rodzaj_Obiektu() == Ob_Robot)
	    {
	      std::shared_ptr<Robot> Dodany_Robot_if;
	      Dodany_Robot_if=std::dynamic_pointer_cast<Robot>(*it); 
	      if(*it!=Obecny_Robot)
		Dodany_Robot_if->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Sciezka)
	    {
	      if(*(std::prev(it))!=Obecny_Robot)
		(*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Przeszkoda)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
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


bool Scena::Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,double dlugosc,int microseconds)
{
  std::ofstream  StrmPlikowy;

  std::shared_ptr<Robot> Dodany_Robot;
  std::shared_ptr<Sciezka> Dodana_Sciezka;
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  Dodana_Sciezka=std::dynamic_pointer_cast<Sciezka>(Obecna_Sciezka);   
 
  (*Dodana_Sciezka).Przygotuj_Animacje_Sciezki(*(Dodany_Robot),Ob_List,dlugosc);

  while(!(*Dodana_Sciezka).Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }


 ////////////////////////////////////////////////////////////////

      for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
	{   
	  
	  if((*it)->Rodzaj_Obiektu() == Ob_Robot)
	    {
	      std::shared_ptr<Robot> Dodany_Robot_if;
	      Dodany_Robot_if=std::dynamic_pointer_cast<Robot>(*it); 
	      if(*it!=Obecny_Robot)
		Dodany_Robot_if->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Sciezka)
	    {
	      if(*(std::prev(it))!=Obecny_Robot)
		(*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Przeszkoda)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  StrmPlikowy<<std::endl;
	}
///////////////////////////////////////////////////////////////////

 
      (*Dodana_Sciezka).Animacja_Sciezki_Z_Robotem(StrmPlikowy,*Dodany_Robot);
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

      for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
	{   
	  
	  if((*it)->Rodzaj_Obiektu() == Ob_Robot)
	    {
	      if(*it!=Obecny_Robot)
		(*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Sciezka)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Przeszkoda)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
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


bool Scena::Animacja_Obrotu_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,int microseconds,double a)
{
  std::ofstream  StrmPlikowy;
  std::shared_ptr<Robot> Dodany_Robot;
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  
  while(!(*Dodany_Robot).Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }


 ////////////////////////////////////////////////////////////////

      for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it) 
	{   
	  
	  if((*it)->Rodzaj_Obiektu() == Ob_Robot)
	    {
	      if(*it!=Obecny_Robot)
		(*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Sciezka)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  if((*it)->Rodzaj_Obiektu() == Ob_Przeszkoda)
	    {
	      (*it)->WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
	    }
	  StrmPlikowy<<std::endl;
	}
      
///////////////////////////////////////////////////////////////////
      
            
      (*Dodany_Robot).Animacja_Obrotu_Robota(StrmPlikowy,a);
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    }
  return !StrmPlikowy.fail();
}


void Scena::Dodaj_Robota(Wektor2D Wsp_Globalne, double Kat_Obrotu)
{
  std::shared_ptr<Robot> Dodany_Robot;
  std::shared_ptr<Sciezka> Dodana_Sciezka;
  Ob_List.push_back(Fab.UtworzObiekt(Ob_Robot));
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Ob_List.back()); 
  Dodany_Robot->ID_Robota(Ile_Robotow());  
  Dodany_Robot->Wektor_Translacji(Wsp_Globalne);
  Dodany_Robot->ObrocOKat(Kat_Obrotu);

  Ob_List.push_back(Fab.UtworzObiekt(Ob_Sciezka));
  Ob_List.back()->Usun_Elementy();
  Ob_List.back()->Ustaw(Wsp_Globalne);

}


void Scena::Dodaj_Robota_Menu()
{
  std::cout<<" Podaj docelowe wspolrzedne przeszkody (lewy gorny rog)";
  std::cout<<std::endl<<" oraz jej szerokosc i dlugosc: x y sz wys > "<<std::endl;
  double dodaj_P_lx=0,dodaj_P_ly=0,dodaj_P_sz=0,dodaj_P_dl=0;
  double _P_x_min=0,_P_x_max=0,_P_y_min=0,_P_y_max=0;
  std::cin>>dodaj_P_lx;
  std::cin>>dodaj_P_ly;
  std::cin>>dodaj_P_sz;
  std::cin>>dodaj_P_dl;
  
  _P_x_min=dodaj_P_lx;
  _P_x_max=dodaj_P_lx + dodaj_P_sz;
  _P_y_min=dodaj_P_ly - dodaj_P_dl;
  _P_y_max=dodaj_P_ly;
  Dodaj_Przeszkode(std::vector<double>{_P_x_min,_P_y_max,  _P_x_max,_P_y_max,   _P_x_max,_P_y_min,   _P_x_min,_P_y_min});
 
}

void Scena::Wybierz_Robota(unsigned int Indeks_Robota){
  bool znaleziony_robot=false;
  for(const std::shared_ptr<Objekt_Graficzny> &wsk : Ob_List )
    {   
      if((wsk->Rodzaj_Obiektu()) == Ob_Robot)
	{
	  if(Indeks_Robota == wsk->ID_Robota())
	    {
	      Obecny_Robot=wsk;
	      znaleziony_robot=true;
	    }
	}
      else if(znaleziony_robot==true)
	{
	  Obecna_Sciezka=wsk;
	  znaleziony_robot=false;
	  //  Obecna_Sciezka->WyswietlWspolrzedneFormatGnuplot(std::cout);
	}
    }
}

void Scena::Wybierz_Robota_Menu(){
  unsigned int wybrany_robot(0);
  
  std::shared_ptr<Robot> Dodany_Robot_tmp;
  std::shared_ptr<Robot> Dodany_Robot;
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  
  /*
    std::cout<<"!!! Test funkcji Wybierz_Robota_Menu() w Scena.hh"<<std::endl;
    std::cout<<"Liczba robotów: "<<Ile_Robotow()<<std::endl;
    for(std::list<std::shared_ptr<Objekt_Graficzny>>::iterator it=Ob_List.begin(); it != Ob_List.end(); ++it)       
    if((*it)->Rodzaj_Obiektu() == Ob_Robot)
    {
    std::shared_ptr<Robot> TMP_PTR;
    TMP_PTR=std::dynamic_pointer_cast<Robot>(*it); 
    std::cout<<"Robot "<<(*TMP_PTR).ID_Robota()<<std::endl;
    std::cout<<"Wektor translacji: "<<(*TMP_PTR).Wektor_Translacji()<<std::endl;
    //	  (*TMP_PTR).WyswietlWspolrzedneFormatGnuplot(std::cout);
    std::cout<<std::endl;
    }
  */
  
  
  std::cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<std::endl<<std::endl;
  std::cout<<"  Robot "<<(*Dodany_Robot).ID_Robota()<<". Wspolrzedne: (";
  std::cout<<Zwroc_Obecnego_Robota().Wektor_Translacji();
  std::cout<<")"<<std::endl<<std::endl<<std::endl<<"\t0 - zaniechaj zmiany selekcji";
  std::cout<<std::endl<<std::endl;
  
  
  for(const std::shared_ptr<Objekt_Graficzny> &wsk : Ob_List )
    if((wsk->Rodzaj_Obiektu()) == Ob_Robot)
      {
	Dodany_Robot_tmp=std::dynamic_pointer_cast<Robot>(wsk); 
	
	std::cout<<"  Robot "<<(*Dodany_Robot_tmp).ID_Robota()<<". Wspolrzedne: (";
	std::cout<<(*Dodany_Robot_tmp).Wektor_Translacji();
	std::cout<<")"<<std::endl;
      }
  
  std::cout<<std::endl<<"Podaj numer robota, dla ktorego maja byc wykonane operacje sterowania"<<std::endl<<std::endl<<"Wprowadz numer robota lub 0 > ";
  std::cin>>wybrany_robot;
  if(!std::cin || (wybrany_robot>Ile_Robotow()))
    {
      std::cout<<"Wybrano niepoprawna opcje."<<std::endl<<"Podany zostal indeks nieistniejacego robota lub znak"<<std::endl;
    }
  else
    {
      if(wybrany_robot!=0) ;
      Wybierz_Robota(wybrany_robot);
      Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
      std::cout<<std::endl<<"  Robot "<<(*Dodany_Robot).ID_Robota()<<"."<<" Wspolrzedne: (";
      std::cout<<Zwroc_Obecnego_Robota().Wektor_Translacji();
      std::cout<<")"<<std::endl;
    }
}


void Scena::Dodaj_Przeszkode(std::vector<double> Wspolrzedne_Wierzcholkow)
{
  Ob_List.push_back(Fab.UtworzObiekt(Ob_Przeszkoda));
  Ob_List.back()->Usun_Elementy();
  Ob_List.back()->Ustaw(Wspolrzedne_Wierzcholkow);

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


unsigned int Scena::Ile_Robotow()
{
  int Ile(0);
  for(const std::shared_ptr<Objekt_Graficzny> &wsk : Ob_List )
    if((wsk->Rodzaj_Obiektu()) == Ob_Robot) Ile++;
  return Ile;
}

unsigned int Scena::Ile_Przeszkod()
{
int Ile(0);
 for(const std::shared_ptr<Objekt_Graficzny> &wsk : Ob_List )
   if((wsk->Rodzaj_Obiektu()) == Ob_Przeszkoda) 
     Ile++; 
 return Ile;
}

unsigned int Scena::Ile_Sciezek()
{
  int Ile(0);
  for(const std::shared_ptr<Objekt_Graficzny> &wsk : Ob_List )
    if((wsk->Rodzaj_Obiektu()) == Ob_Sciezka) Ile++;
  return Ile;
}


void Scena::Jedz_Prosto(double dlugosc)
{
  std::shared_ptr<Robot> Dodany_Robot;
  std::shared_ptr<Sciezka> Dodana_Sciezka;
  
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  Dodana_Sciezka=std::dynamic_pointer_cast<Sciezka>(Obecna_Sciezka);   
  (*Dodana_Sciezka).Jedz_Prosto(*Dodany_Robot,dlugosc);
}

void Scena::ObrocOKat(double a)
{
  std::shared_ptr<Robot> Dodany_Robot;
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  (*Dodany_Robot).ObrocOKat(a);
}

Robot& Scena::Zwroc_Obecnego_Robota()
{
  std::shared_ptr<Robot> Dodany_Robot;
  Dodany_Robot=std::dynamic_pointer_cast<Robot>(Obecny_Robot);   
  return *Dodany_Robot; 
}
