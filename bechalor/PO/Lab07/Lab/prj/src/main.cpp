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
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  Scena Scena_programu(Lacze);
  Wektor2D _domyslne_wartosci_wektora_globalnego=Wektor2D(0,0);
  double Predkosc_Robota=0.5;  
                              // rysunku bryły
  Wektor2D Wek; 
  double a,dlugosc,szybkosc;
  unsigned int wybrany_robot=0,tmp_wybrany_robot=0;    
  Wektor2D dodaj_R=Wektor2D(0,0);


  //  std::cout<<"Liczba Sciezek: "<<Scena_programu.Ile_Sciezek()<<std::endl;

  // [wybrany_robot]
  
  Scena_programu.Wybierz_Robota(1);  
  Objekt_Graficzny::Wsp_Glob(_domyslne_wartosci_wektora_globalnego);
  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
    return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

  
  WyswietlMenu();
  cout<<endl;

  // Menu:
  while(Znak!='k')
    {
      if(!cin){	
	cin.clear();
	cin.ignore(256,'\n');
      }

      cout<<" Twoj wybor? (m - menu) > ";
      cin>>Znak;
      cout<<endl;
      switch(Znak)
	{
	case 'R':
	  cout<<" Podaj docelowe wspolrzedne robota: x y > ";
	  cin>>dodaj_R;	  
	  Scena_programu.Dodaj_Robota(dodaj_R,0);
	  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  break;
	
	case 'P':
	  Scena_programu.Dodaj_Robota_Menu();
	  if (!Scena_programu.ZapisWspolrzednychDoPlikuFormatGnuplot("robot.dat")) 
	    return 1;
	  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
	  
	  break;
	
	case 'z':
	  cout<<"Podaj predkosc robota."<<endl<<"Predkosc: ";
	  cin>>Predkosc_Robota;
	  break;

	case 'o':
	  cout<<"Podaj wartosc kata obrotu robota w stopniach."<<endl<<"Kat obrotu:  ";
	  cin>>a;
	  Scena_programu.ObrocOKat(a);
	  if(!Scena_programu.Animacja_Obrotu_FormatGnuplot(Lacze,"robot.dat"))
	    return 1;
	  break;

	case 'j':
	  cout<<"Podaj dlugosc drogi ruchu robota na wprost."<<endl<<"Dlugosc drogi: ";
	  cin>>dlugosc;
	  Scena_programu.Jedz_Prosto(dlugosc);

	  if(!Scena_programu.Animacja_Sciezki_FormatGnuplot(Lacze,"robot.dat",Predkosc_Robota))
	    return 1;
	  //	  cout<<"Laczna dlugosc sciezki: "<<Scena_programu.Sciez.Laczna_Dlugosc_Sciezki()<<endl;
	  break;	 

	case 's':
	  Scena_programu.Wybierz_Robota_Menu();
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

    
  //cin>>Znak; // <-- gnuplot wyłacza się wraz z programem - utrzymanie działania
}


void WyswietlMenu()
{
  Wektor2D::Wyswietl_Statystyki();
  cout<<endl;
  cout<<"  R - dodaj robota"<<endl;
  cout<<"  P - dodaj przeszkode"<<endl;

  cout<<"  z - zmiana szybkosci ruchu robota"<<endl;
  cout<<"  o - obrot robota"<<endl;
  cout<<"  j - jazda na wprost"<<endl;
  cout<<"  s - selekcja robota"<<endl;
  cout<<endl;
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

