#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "Scena.hh"
#include "Macierz2x2.hh"
#include "lacze_do_gnuplota.hh"


#include "Objekt_Graficzny.hh"


using namespace std;

Wektor2D Objekt_Graficzny::_wsp_globalne;
int Wektor2D::_laczna_liczba_utworzonych=0;
int Wektor2D::_aktualna_liczba_istniejacych=0;
  

void WyswietlMenu();


int main()
{
  char              Znak;
  Scena Scena_programu;
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  Wektor2D _domyslne_wartosci_wektora_globalnego=Wektor2D(0,0);
  double Predkosc_Robota=0.5;  
                              // rysunku bryły
  Wektor2D Wek; 
  double a,dlugosc,szybkosc;
  int wybrany_robot=0;    


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

  Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",&(Scena_programu.Rob[0]),Predkosc_Robota);

 
  //  Scena_programu.Wyswietl_Wspolrzedne_Objektow();
  //  Scena_programu.Sciez[0].WyswietlWspolrzedneFormatGnuplot(std::cout);
  //  cout<<Zb_Wierzch<<endl;

  /*   
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku


  cin>>a;
  Scena_programu.Rob.ObrocOKat(a);
  if(!Scena_programu.Animacja_Obrotu_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez,Scena_programu.Rob))
    return 1;
  cin>>dlugosc;
  Scena_programu.Sciez.Jedz_Prosto(Scena_programu.Rob,dlugosc);
 
  
  //  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
  if(!Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez,Scena_programu.Rob))
    return 1;
  Wektor2D::Wyswietl_Statystyki();


  cin>>a;
  Scena_programu.Rob.ObrocOKat(a);
  if(!Scena_programu.Animacja_Obrotu_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez,Scena_programu.Rob))
    return 1;
  cin>>dlugosc;
  Scena_programu.Sciez.Jedz_Prosto(Scena_programu.Rob,dlugosc);

  if(!Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez,Scena_programu.Rob))
    return 1;
  Wektor2D::Wyswietl_Statystyki();

    
  cin>>Znak;
  */

  /* 
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  */  

  // [wybrany_robot]
  /*
  
  Objekt_Graficzny::Wsp_Glob(_domyslne_wartosci_wektora_globalnego);
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  
  WyswietlMenu();
  cout<<endl;

  // Menu:
  while(Znak!='k')
    {
      cout<<" Twoj wybor? (m - menu) > ";
      cin>>Znak;
      cout<<endl;
      switch(Znak)
	{
	  
	case 'z':
	  cout<<"Podaj predkosc robota."<<endl<<"Predkosc: ";
	  cin>>Predkosc_Robota;
	  break;

	case 'o':
	  cout<<"Podaj wartosc kata obrotu robota w stopniach."<<endl<<"Kat obrotu:  ";
	  cin>>a;
	  Scena_programu.Rob[wybrany_robot].ObrocOKat(a);
	  if(!Scena_programu.Animacja_Obrotu_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez[wybrany_robot],Scena_programu.Rob[wybrany_robot]))
	    return 1;
	  break;

	case 'j':
	  cout<<"Podaj dlugosc drogi ruchu robota na wprost."<<endl<<"Dlugosc drogi: ";
	  cin>>dlugosc;
	  Scena_programu.Sciez[wybrany_robot].Jedz_Prosto(Scena_programu.Rob[wybrany_robot],dlugosc);

	  //	  if(!Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Sciez[wybrany_robot],Scena_programu.Rob[wybrany_robot],Predkosc_Robota))
	  if(!Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",Scena_programu.Rob[wybrany_robot],Predkosc_Robota))

	    return 1;
	  cout<<"Laczna dlugosc sciezki: "<<Scena_programu.Sciez[wybrany_robot].Laczna_Dlugosc_Sciezki()<<endl;
	  break;	 

	case 't':
	  cout<<"Aktualny całkowity wektor translacji"<<endl<<"wzgledem poczatkowego polozenia sceny: "<<Objekt_Graficzny::Wsp_Glob();
	  cout<<endl<<"Wpisz wspolrzedne wektora lokalnej translacji rysunku sceny."<<endl<<"Podaj wartosci: x y > ";
	  cin>>Wek;
	  Objekt_Graficzny::Wsp_Glob(Objekt_Graficzny::Wsp_Glob()+Wek);
	  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  break;


	case 'p':
	  Objekt_Graficzny::Wsp_Glob(_domyslne_wartosci_wektora_globalnego);
	  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  
	  break;

	case 'w':
	  WyswietlMenu();
	  break;

	case 'k':
	  cout<<"Koniec dzialania program"<<endl;
	  break;

	default:
	  cout<<"Wybrano niepoprawna opcje. Prosze wybrac jeszcze raz."<<endl;
	}
      cout<<endl;
    }
  */   
//cin>>Znak; // <-- gnuplot wyłacza się wraz z programem - utrzymanie działania
}


void WyswietlMenu()
{
  Wektor2D::Wyswietl_Statystyki();
  cout<<endl;
  cout<<"  z - zmiana szybkosci ruchu robota"<<endl;
  cout<<"  o - obrot robota"<<endl;
  cout<<"  j - jazda na wprost"<<endl;
  cout<<"  t - zadaj translacje na rysunku"<<endl;
  cout<<"  p - powrot do pierwotnego ustawienia rysunku"<<endl;
  cout<<"  w - wyswietl menu"<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
  /*
  cout<<"  o - obrot bryły o zadany kat"<<endl;
  cout<<"  t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"  r - wyswietlenie macierzy rotacji"<<endl;
  cout<<"  p - przesuniecie bryły o zadany wektor"<<endl;
  cout<<"  w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"  s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"  m - wyswietl menu"<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
  */
}

