/*
  Kornel Stefanczyk
  Nr albumu: 235420
*/

#include <cassert>
#include <iostream>

#define ILOSC_SYMBOLI 5

using namespace std;


/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/
enum Symbol {e, a, b, c, d};
Symbol TablicaSymboli[ILOSC_SYMBOLI] = {e, a, b, c, d};
Symbol TabliczkaDodawania[5][5] = {{e, a, b, c, d},{a, d, e, b, c},{b, e, c, d, a},{c, b, d, a, e},{d, c, a, e, b}};
Symbol TabliczkaMnozenia[5][5] = {{e, e, e, e, e},{e, a, b, c, d},{e, b, a, d, c},{e, c, d, b, a},{e, d, c, a, b}};

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
Symbol Dodaj(Symbol Arg1, Symbol Arg2);
Symbol ZnajdzOdwrotny(Symbol Arg1);
Symbol ZnajdzPrzeciwny(Symbol Arg1);

/*
  Definicja przeciazen operatorow
*/ 
Symbol operator + (Symbol Arg1, Symbol Arg2);
Symbol operator + (Symbol Arg1);
Symbol operator - (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1);
Symbol operator * (Symbol Arg1, Symbol Arg2);
Symbol operator / (Symbol Arg1, Symbol Arg2);


int main()
{
  //  Symbol wynik_fun, wynik_alg, wynik_ope;
  //  Symbol y, x;

  //  x=a,y=c;

  //  cout<<"Uzyte parametry to:x="<<x<<" i y="<<y<<endl;
  
  //  cout << "Dodaj: " << Dodaj(y,x); << endl;
  
  //  cout << "Operator -: " <<operator - (x,y) << endl;
  
  //  cout << "-: " << x-y << endl;
  


  cout<<endl<<"a+d      "<<a+d<<endl;
  cout<<"a-b      "<<a-b <<endl;
  cout<<"a+(b+c)  "<<a+(b+c) <<endl;
  cout<<"c-(d-a)  "<<c-(d-a) <<endl<<endl<<endl;

  cout<<"c+a*b-d       "<< c+a*b-d  <<endl;
  cout<<"(d-b)/(d+b)   "<< (d-b)/(d+b)  <<endl;
  cout<<"b-c/(c*(a+b)) "<< b-c/(c*(a+b))  <<endl;
  cout<<"d-b-c-a*b     "<< d-b-c-a*b   <<endl;

  
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
/*   do elementu podanego jako Arg1. W razie braku takiego argumentu*/
/*   funkcja zwroci element neutralny tzn. e.                       */
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
/* Przeciazenie odpowiada za zwrocenie wartosci elementu przy ktorym*/
/*   stoi + (Wartosc argumentu sie nie zmienia).                    */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1)
{
  return Arg1;
}

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dodawanie dwóch argumentow. Wynik      */
/*   dodawania jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDodawania[Arg2][Arg1];
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
  return ZnajdzPrzeciwny(Arg1);
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
  return Arg1+(-Arg2);
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
  return TabliczkaMnozenia[Arg2][Arg1];
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
      return e;
    }
}

