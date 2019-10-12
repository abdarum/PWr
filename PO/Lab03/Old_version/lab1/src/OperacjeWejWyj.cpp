#include "OperacjeWejWyj.hh"
//struct WyrazenieAlgeb;
//  !!!  Jak zrobic zeby tablica symboli dzialala wszedzie?  !!!
//       WyrazenieAlgeb "nie zostala zdeklarowana" mimo ze zrobilem 
//         to w pliku naglowkowym
//       Jak zaimplementowac koniec strumienia - Ctrl + D?
//       Czy dzialanie to kazda nowa linijka np enter lub r
//       czy musi byc konstrukcja (cos)(znak)(cos)(=lub inne)(cos) ?



//Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};

bool WczytajSymbol(Symbol& Arg)
{
  Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
  char* ptrZnak;
  char* const tabSymboli="eabcd";
  char tmpZnak='x';
  cin>>tmpZnak;
  ptrZnak=strchr(tabSymboli,tmpZnak);
  if(ptrZnak==nullptr)
    return false;
  Arg=TablicaSymboli[(ptrZnak-tabSymboli)/sizeof(char)];
  return true;
}


void WypiszSymbol(Symbol Arg)
{
  char* tabSymboli="eabcd";
  cout<<tabSymboli[Arg];
}

void WyswietlWynik(WyrazenieAlgeb Dzialania)
{
  cout<<"Odczytano wyrazenie: ";
  cout<<Dzialania.Arg1<<" "<<Dzialania.ZnakDzialania;
  cout<<Dzialania.Arg2<<" = "<<Dzialania.WczytanyWynikDzialania;
  if (Dzialania.WynikiRowne)
    cout<<"   Wynik poprawny"<< endl;
  else
    cout<<"   Wynik niepoprawny. Wlasciwy wynik to: "<<Dzialania.PrawidlowyWynikDzialania<<endl;
}


bool WczytajRownanie(WyrazenieAlgeb & Dzialania)
{
  char ZnakRownosci;
  Zeruj(Dzialania);
  
  cin>>Dzialania.Arg1;
  if ( cin.fail( ) )
    {
      cerr<<"Blad skladni wyrazenia. Niepoprawny pierwszy argument"<<endl;
      return 0;
    }
  cin.clear( );

  cin>>Dzialania.ZnakDzialania;
  if(Dzialania.ZnakDzialania!='+'||'-'||'*'||'/')
    {
      cerr<<"Blad skladni wyrazenia. Niedozwolony znak operatora"<<endl;
      return 0;
    }

  cin>>Dzialania.Arg2;
  if ( cin.fail( ) )
    {
      cerr<<"Blad skladni wyrazenia. Niepoprawny drugi argument"<<endl;
      return 0;
    }
  cin.clear( );

  cin>>ZnakRownosci;
  if(ZnakRownosci!='=')
    {
      cerr<<"Blad skladni wyrazenia. Brak znaku '='"<<endl;
      return 0;
    }

  cin>>Dzialania.WczytanyWynikDzialania;
  if ( cin.fail( ) )
    {
      cerr<<"Blad skladni wyrazenia. Niepoprawny argument wyniku"<<endl;
      return 0;
    }
  cin.clear( );

  return 1;
}


ostream& operator << (ostream& wyj,Symbol Arg)
{
  char* tabZnakow="eabcd";
  wyj<<tabZnakow[Arg];
  return wyj;
}


istream& operator >> (istream& wej,Symbol& Arg)
{
  Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
  char* ptrZnak;
  char* tabSymboli="eabcd";
  char tmpZnak='x';

  if (wej.fail( )) return wej;
  wej>>tmpZnak;
  if ((ptrZnak=strchr(tabSymboli,tmpZnak)))
    { 
      Arg=TablicaSymboli[(ptrZnak-tabSymboli)/sizeof(char)];
    }
  else
    {
      wej.unget( );
      wej.setstate(ios::failbit);
    }
  return(wej);
}
