#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"


using namespace std;

void WyswietlMenu();

int main()
{
  char                  Znak;
  Prostokat             Pr; 
  Wektor2D Wek;  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  
  // Ustawienie wartosci wierzcholkow prostokata
  //  Pr.Ustaw(10,10,160,10,160,110,10,110);
  Pr.Ustaw(2,2,12,2,12,7,2,7);
  


   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.UstawZakresX(-30,30);
  Lacze.UstawZakresY(-30,30);

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
	  
	case 'o':
	  float a; 
	  int count;
	  cout<<" Podaj wartosc kata obrotu w stopniach"<<endl;
	  cin>>a;
	  cout<<" Ile razy operacja obrotu ma byc powtorzona?"<<endl;
	  cin>>count;
	  Pr.ObrocOKat(a,count);
	  break;      
	 
	case 'p':
	  cout<<"Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb";
	  cout<<endl<<" tzn. wspolrzednej x oraz wspolrzednej y."<<endl;
	  cin>>Wek;
	  Pr.PrzesunOWektor(Wek);
	  break;

	case 'w':
	  cout<<Pr;
	  if (!Pr.ZapisWspolrzednychDoPlikuFormatGnuplot("prostokat.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  break;
	
	case 's':
	  Pr.DlugosciBokow();
	  break;

	case 'm':
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
//cin>>Znak; // <-- gnuplot wyłacza się wraz z programem - utrzymanie działania
}


void WyswietlMenu()
{
  cout<<endl;
  cout<<"  o - obrot prostokata o zadany kat"<<endl;
  cout<<"  p - przesuniecie prostokata o zadany wektor"<<endl;
  cout<<"  w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"  s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"  m - wyswietl menu"<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
}
