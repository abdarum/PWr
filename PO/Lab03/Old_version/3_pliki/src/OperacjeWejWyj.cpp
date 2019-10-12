#include "OperacjeWejWyj.hh"

//  !!!  Jak zrobic zeby tablica symboli dzialala wszedzie?  !!!

//Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};

bool WczytajSymbol(Symbol& Arg)
{
  Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
  char* ptrZnak;
  char* tabSymboli="eabcd";
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
