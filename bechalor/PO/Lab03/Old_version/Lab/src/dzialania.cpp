/*
  Kornel Stefanczyk
  Nr albumu: 235420
*/

typedef struct{
  unsigned int wszystkie_dzialania;
  unsigned int poprawny_zapis;
  unsigned int poprawny_wynik;
  float procent_wynikow;
  unsigned int ilosc_dodaj_odejmij;
  unsigned int ilosc_moz_dziel;
  //  unsigned int 
} Statystyka;

/*
typedef struct{
  Symbol Arg1;
  char dzialanie;
  Symbol Arg2;
  Symbol WczytanyWynikDzialania; 
  Symbol PrawidlowyWynikDzialania;
} Dzialania;
*/

#include <cstring>
#include <cassert>
#include <iostream>

#define ILOSC_SYMBOLI 5

using namespace std;

bool bledy=0;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/
enum Symbol {e, a, b, c, d};
Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
Symbol TabliczkaDodawania[5][5] = {{e, a, b, c, d},{a, d, e, b, c},{b, e, c, d, a},{c, b, d, a, e},{d, c, a, e, b}};
Symbol TabliczkaMnozenia[5][5] = {{e, e, e, e, e},{e, a, b, c, d},{e, b, a, d, c},{e, c, d, b, a},{e, d, c, a, b}};


/*
Definicja struktury przechowujacej dane wejsciowe
*/
typedef struct{
  Symbol Arg1;
  char dzialanie;
  Symbol Arg2;
  Symbol WczytanyWynikDzialania; 
  Symbol PrawidlowyWynikDzialania;
} Dzialania;

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel
*/
Symbol Dodaj(Symbol Arg1, Symbol Arg2);
Symbol ZnajdzOdwrotny(Symbol Arg1);
Symbol ZnajdzPrzeciwny(Symbol Arg1);
void WypiszSymbol(Symbol Arg);
bool WczytajSymbol(Symbol& Arg);
istream& operator>>(istream& wej,Symbol& Arg);  
/*
  Definicja przeciazen operatorow
*/ 
Symbol operator ^ (Symbol Arg1, Symbol Arg2);
Symbol operator + (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1);
Symbol operator * (Symbol Arg1, Symbol Arg2);
Symbol operator / (Symbol Arg1, Symbol Arg2);
ostream& operator << (ostream& wyj,Symbol Arg);
istream& operator>>(istream& wej,Symbol& Arg);

int main()
{
  Symbol y, x;

  cout<<"podaj x: ";
  cin>>x;
  cout<<"podaj y: ";
  cin>>y;

 
  cout <<x<< "-"<<y<<"= " << x*y << endl;

  
  
  /*
  cout<<endl<<"a+d      "<<a+d<<endl;
  bledy=0;
  cout<<"a-b      "<<a-b <<endl;
  bledy=0;
  cout<<"a+(b+c)  "<<a+(b+c) <<endl;
  bledy=0;
  cout<<"c-(d-a)  "<<c-(d-a) <<endl<<endl<<endl;
  bledy=0;
  

  cout<<"c+a*b-d       "<< c+a*b-d  <<endl;
  bledy=0;
  cout<<"(d-b)/(d+b)   "<< (d-b)/(d+b)  <<endl;
  bledy=0;
  cout<<"b-c/(c*(a+b)) "<< b-c/(c*(a+b)) <<endl;
  bledy=0;
  cout<<"d-b-c-a*b     "<< d-b-c-a*b   <<endl<<endl<<endl;
  bledy=0;
  */


  /*
  x=d^b;
  y=a^c; 
  
  cout<<endl<<"d^b  "<< x <<endl;
  bledy=0;
  cout<<endl<<"a^c  "<< y <<endl<<endl;
  bledy=0;
  */

  /*
  cout<<endl<<"d^b  "<< d^b <<endl;
  bledy=0;
  cout<<endl<<"a^c  "<< a^c <<endl<<endl;
  bledy=0;
  */

}


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/*         *** FUNKCJE ***         */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za dodawanie dwóch argumentow. Wynik dodawani a*/
/*   jest taki jak w tabelce dostarczonej do zadania.               */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol Dodaj(Symbol Arg1, Symbol Arg2) 
{
  return TabliczkaDodawania[Arg2][Arg1];
}

/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za znalezienie i zwrocenie elementu przeciwnego*/
/*   do elementu podanego jako Arg1                                 */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
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

/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za znalezienie i zwrocenie elementu odwrotnego */
/*   do elementu podanego jako Arg1                                 */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
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


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/* *** PRZECIAZENIE OPERATOROW *** */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dodawanie dwóch argumentow. Wynik      */
/*   dodawania jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  if(bledy==0)
    return TabliczkaDodawania[Arg2][Arg1];
  else
    {
      return e;
    }
}

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za zwrocenie wartosci przeciwnej dla      */
/*   argumentu przy ktorym stoi.                                    */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
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

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za odejmowanie dwóch argumentow.          */
/*   Odejmowanie jest zrealizowane jako dodawanie elementu          */
/*   przeciwnego.                                                   */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator - (Symbol Arg1, Symbol Arg2)
{
  if(!bledy)
    return Arg1+(-Arg2);
  else
    {
      return e;
    }
}


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za mnozenie dwóch argumentow. Wynik       */
/*    mnozenia jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator * (Symbol Arg1, Symbol Arg2)
{
  if(!bledy)
    return TabliczkaMnozenia[Arg2][Arg1];
  else
    {
      return e;
    }
}


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dzielenie dwóch argumentow. Dzieleni  */
/*    jest realizowane poprzez pomnozenie przez liczbe odwrotna.    */
/* Arg2 nie moze byc e                                              */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
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


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za potegowanie.                           */
/* Arg2 nie moze byc e                                              */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator ^ (Symbol Arg1, Symbol Arg2)
{
  return(Arg2*Arg1*Arg1*Arg2+Arg2/Arg1-Arg1);
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


ostream& operator << (ostream& wyj,Symbol Arg)
{
  char* tabZnakow="eabcd";
  wyj<<tabZnakow[Arg];
  return wyj;
}

/*
istream& operator>>(istream& wej,Symbol& Arg)
{
  char* ptrZnak;
  char* tabSymboli="eabcd";
  char tmpZnak='x';
  wej>>tmpZnak;
  ptrZnak=strchr(tabSymboli,tmpZnak);
  Arg=TablicaSymboli[(ptrZnak-tabSymboli)/sizeof(char)];
  return(wej);
  //  Arg=tabZnakow[ptrZnak-tabZnakow];
}
*/



istream& operator>>(istream& wej,Symbol& Arg)
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
