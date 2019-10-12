#include <iostream>
#include <cstring>
#include <cassert>
#include "WyrazenieAlgeb.hh"
#include "OperacjeWejWyj.hh"
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
  //  Symbol           x, y;    // To tylko przykladowe definicje zmiennych
  Statystyka       Stat;
  WyrazenieAlgeb   Wyrazenie;
  char ZnakRownosci;

  Zeruj(Wyrazenie);
  /*
  cout<<"Podaj Arg1: ";
  cin>>Wyrazenie.Arg1;
  cout<<"Podaj znak dzialania: ";
  cin>>Wyrazenie.ZnakDzialania;
  cout<<"Podaj Arg2: ";
  cin>>Wyrazenie.Arg2;
  cout<<"Podaj wynik: ";
  cin>>Wyrazenie.WczytanyWynikDzialania;
  */


  cin>>Wyrazenie.Arg1;
  cin>>Wyrazenie.ZnakDzialania;
  cin>>Wyrazenie.Arg2;
  cin>>ZnakRownosci;
  cin>>Wyrazenie.WczytanyWynikDzialania;

  WykonajDzialania(Wyrazenie,Stat);

  cout<<cin.fail()<<endl;
  cout<<"Arg1: "<<Wyrazenie.Arg1<<endl;
  cout<<"Znak dzialania: "<<Wyrazenie.ZnakDzialania<<endl;
  cout<<"Arg2: "<<Wyrazenie.Arg2<<endl;
  cout<<"Wynik: "<<Wyrazenie.WczytanyWynikDzialania<<endl;
  cout<<"Poprawny wynik: "<<Wyrazenie.PrawidlowyWynikDzialania<<endl;
  cout<<"Byly rowne? "<<Wyrazenie.WynikiRowne<<endl;


  cout << "Start sprawdzianu testu arytmetyki symboli" << endl;
}

