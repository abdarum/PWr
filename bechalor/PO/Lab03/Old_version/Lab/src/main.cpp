#include <iostream>
#include <cstring>
#include <cassert>
#include "WyrazenieAlgeb.hh"
#include "Statystyka.hh"
#include "Symbol.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  Statystyka       Stat;
  WyrazenieAlgeb   Wyrazenie;
  char ZnakRownosci;

  Zeruj(Stat);
  Zeruj(Wyrazenie);

  cout << "Start sprawdzianu testu arytmetyki symboli" << endl<<endl;

  while(!cin.eof())  
    {
      cin>>Wyrazenie;
      if(!cin.eof())
	++Stat.WszystkieDzialania;     
      if(!cin.fail())
	{
	  ++Stat.PoprawnyZapis;
	  WykonajDzialania(Wyrazenie,Stat);
	  cout<<Wyrazenie;
	}
    }
  
  cout<<Stat<<endl;
  
}

