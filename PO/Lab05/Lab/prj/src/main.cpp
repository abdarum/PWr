#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Bryla.hh"
#include "lacze_do_gnuplota.hh"


using namespace std;

void WyswietlMenu();

int main()
{
  char              Znak;
  Bryla             Pr; 
  Macierz3x3 Macierz(1);
  Wektor3D Wek;  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  
                              // rysunku bryły
 
  //  cout<<Pr;
  // Ustawienie wartosci wierzcholkow bryły
  // Pr.Ustaw(10,10,160,10,160,110,10,110);
  
  /*  cout<<"przed "<< endl;
  int a,Ind;
  cin>>a;
  cin>>Ind;  
  Wek.Ustaw_Wsp(a,Ind);
  cout<<Wek<<endl;
  cout<<"po "<< endl; */
  //  double Wspolrzedne[24]={2,2,0,12,2,0,12,7,0,2,7,0,2,2,10,12,2,10,12,7,10,2,7,10};
  // double Wspolrzedne[12]={2,3,3,  22,3,3,  2,18,3,  10,10,20};

  double Wspolrzedne[12]={1,1,1, -1,-1,1,   -1,1,-1,  1,-1,-1 };
 
  Pr.Ustaw(Wspolrzedne);

  /*
  double a;
  char os;
  int count;
  
  while(os!='.')
    if(os!='.')
      {      

	cin>>os;
	cin>>a;
	Macierz.Macierz_Obrotu(Macierz3x3(a,os));
	cout<<Macierz3x3(a,os);
	cout<< Macierz;
	assert(!cin.fail());
      }
  */
  /*
  cin>>count;
  Pr.ObrocOKat(Macierz,count);
  cout<<Pr;
  cout<<"po "<< endl; 
  */
  
    
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
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresX(-5,5);
  Lacze.UstawZakresY(-5,5);
  Lacze.UstawZakresZ(-5,5);

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
	  Macierz.Macierz_Jednostkowa();
	  cout<< Macierz;
	  char os;
	  double a; 
	  int count;
	  a=0; count=0; os='q';
	  cout<<" Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach"<<endl;
	  while(os != '.')
	    {
	      cin.clear();
	      a=0; count=0; os='q';
	      cin>>os;
	      if(os != '.')
		{
		  cin>>a;
		  if((os!='x' && os!='y' && os!='z' && os!='.') || cin.fail())
		    {
		      cout<<":( Bledne oznaczenie osi. Dopuszczalne znaki to: x y z ."<<endl;
		      cout<<":( Sprobuj jeszcze raz."<<endl;
		      cin.ignore(256,'\n');
		    }
		  else
		    {
		      assert(os!='.');
		      Macierz.Macierz_Obrotu(Macierz3x3(a,os));
		    }
		}
	    }
	  cout<<" Ile razy operacja obrotu ma byc powtorzona?"<<endl;
	  cin>>count;
	  Pr.ObrocOKat(Macierz,count);	  

	  break;      
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
	
	case 's':
	  cout<<Pr.PoleBoku()<<endl;
	  //	  Pr.DlugosciBokow();
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
  cout<<"  o - obrot bryły o zadany kat"<<endl;
  cout<<"  t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"  r - wyswietlenie macierzy rotacji"<<endl;
  cout<<"  p - przesuniecie bryły o zadany wektor"<<endl;
  cout<<"  w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"  s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"  m - wyswietl menu"<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
}

