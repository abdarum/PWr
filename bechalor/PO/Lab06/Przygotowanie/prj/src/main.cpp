#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "Scena.hh"
#include "Macierz2x2.hh"
#include "lacze_do_gnuplota.hh"


using namespace std;

int Wektor2D::_laczna_liczba_utworzonych;
int Wektor2D::_aktualna_liczba_istniejacych;
  

void WyswietlMenu();


int main()
{
  char              Znak;
  Scena Scena_programu;
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  
                              // rysunku bryły
 
  Wektor2D::Wyswietl_Statystyki();


  double a,dlugosc;
    
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
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,0);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.UstawZakresX(-30,30);
  Lacze.UstawZakresY(-30,30);

  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("prostokat.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku


  cin>>a;
  Scena_programu.Rob.ObrocOKat(a);
  cin>>dlugosc;
  Scena_programu.Sciez.Jedz_Prosto(Scena_programu.Rob,dlugosc);
 
  Scena_programu.Rob.WyswietlWspolrzedneFormatGnuplot(std::cout);
  
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("prostokat.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku


  cin>>a;
  Scena_programu.Rob.ObrocOKat(a);
  cin>>dlugosc;
  Scena_programu.Sciez.Jedz_Prosto(Scena_programu.Rob,dlugosc);
 
  Scena_programu.Rob.WyswietlWspolrzedneFormatGnuplot(std::cout);
  
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("prostokat.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  
    
  cin>>Znak;


  /*
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
	  
	case 't':
	  Pr.ObrocOKat(Macierz,1);	  
	  break;

	case 'r':
	  cout<<Macierz;
	  break;	 

	case 'p':
	  cout<<"Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb";
	  cout<<endl<<" tzn. wspolrzednej x, wspolrzednej y oraz wspolrzednej z."<<endl;
	  cin>>Wek;
	  Pr.PrzesunOWektor(Wek);
	  break;
	 
	case 'w':
	  cout<<Pr;
	  if (!Pr.ZapisWspolrzednychDoPlikuFormatGnuplot("prostokat.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
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
    */
//cin>>Znak; // <-- gnuplot wyłacza się wraz z programem - utrzymanie działania
}


void WyswietlMenu()
{
  cout<<endl;
  cout<<"  o - obrot bryły o zadany kat"<<endl;
  cout<<"  t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"  r - wyswietlenie macierzy rotacji"<<endl;
  cout<<"  p - przesuniecie bryły o zadany wektor"<<endl;
  cout<<"  w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"  s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"  m - wyswietl menu"<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
}

