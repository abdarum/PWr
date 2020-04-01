#include "WyrazenieAlgeb.hh"



Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
Symbol TabliczkaDodawania[5][5] = {{e, a, b, c, d},
				   {a, d, e, b, c},
				   {b, e, c, d, a},
				   {c, b, d, a, e},
				   {d, c, a, e, b}};
Symbol TabliczkaMnozenia[5][5] = {{e, e, e, e, e},
				  {e, a, b, c, d},
				  {e, b, a, d, c},
				  {e, c, d, b, a},
				  {e, d, c, a, b}};


/********************************************************************/
/*  Flaga ktora zatrzymuje wykonywanie obliczen po wystapieniu      */
/*    niedozwolonej operacji                                        */
/********************************************************************/
bool bledy=0; 

Symbol ZnajdzPrzeciwny(Symbol Arg1) 
{
  Symbol tmpSymb=TablicaSymboli[0];
  int Ind;
  for(Ind=0;Ind<ILOSC_SYMBOLI;++Ind,tmpSymb=TablicaSymboli[Ind])
    {
      if (tmpSymb+Arg1==e)
	return tmpSymb;
    }
  assert(0);
  return e;
}


Symbol ZnajdzOdwrotny(Symbol Arg1) 
{
  Symbol tmpSymb=TablicaSymboli[0];
  int Ind;
  for(Ind=0;Ind<ILOSC_SYMBOLI;++Ind,tmpSymb=TablicaSymboli[Ind])
    {
      if (tmpSymb*Arg1==a)
	return tmpSymb;
    }
  assert(0);
  return a;
}


bool WczytajSymbol(Symbol& Arg)
{
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


void ZerujBledy()
{
  bledy=0;
  //  Clear( IStrm );
}

void Zeruj(WyrazenieAlgeb& Dzialania)
{
  Dzialania.Arg1=e;
  Dzialania.ZnakDzialania='~';
  Dzialania.Arg2=e;
  Dzialania.WczytanyWynikDzialania=e;
  Dzialania.PrawidlowyWynikDzialania=e;
  Dzialania.WynikiRowne=false;
}


void WykonajDzialania(WyrazenieAlgeb & Dzialania)
{
  switch (Dzialania.ZnakDzialania)
    {
    case '+':
      Dzialania.PrawidlowyWynikDzialania=Dzialania.Arg1+Dzialania.Arg2;
      ZerujBledy();
      break;
    case '-':
      Dzialania.PrawidlowyWynikDzialania=Dzialania.Arg1-Dzialania.Arg2;
      ZerujBledy();      
      break;
    case '*':
      Dzialania.PrawidlowyWynikDzialania=Dzialania.Arg1*Dzialania.Arg2;
      ZerujBledy();      
      break;
    case '/':
      Dzialania.PrawidlowyWynikDzialania=Dzialania.Arg1/Dzialania.Arg2;
      ZerujBledy();      
      break;
    }
  if (Dzialania.WczytanyWynikDzialania==Dzialania.PrawidlowyWynikDzialania)
    Dzialania.WynikiRowne=true;
  else
    Dzialania.WynikiRowne=false;   
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


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/* *** PRZECIAZENIE OPERATOROW *** */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


Symbol operator + (Symbol Arg1)
{
  return Arg1;
}


Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  if(bledy==0)
    return TabliczkaDodawania[Arg2][Arg1];
  else
    {
      return e;
    }
}


Symbol operator - (Symbol Arg1)
{
  if(!bledy)
    return ZnajdzPrzeciwny(Arg1);
 else
   {
     bledy=0;
     return e;
   }
}


Symbol operator - (Symbol Arg1, Symbol Arg2)
{
  if(!bledy)
    return Arg1+(-Arg2);
  else
    {
      return e;
    }
}


Symbol operator * (Symbol Arg1, Symbol Arg2)
{
  if(!bledy)
    return TabliczkaMnozenia[Arg2][Arg1];
  else
    {
      return e;
    }
}


Symbol operator / (Symbol Arg1, Symbol Arg2)
{
  if(Arg2!=e)
    return Arg1*ZnajdzOdwrotny(Arg2);
  else
    {
      cerr<<"Nie mozna dzielic przez element neutralny"<<endl;
      bledy=1;
      return e;
    }
}


Symbol operator ^ (Symbol Arg1, Symbol Arg2)
{
  return(Arg2*Arg1*Arg1*Arg2+Arg2/Arg1-Arg1);
}


ostream& operator << (ostream& wyj,Symbol Arg)
{
  char* tabZnakow="eabcd";
  wyj<<tabZnakow[Arg];
  return wyj;
}


istream& operator >> (istream& wej,Symbol& Arg)
{
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

