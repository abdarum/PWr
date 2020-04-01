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


/*
  Definicja przeciazen operatorow
*/ 
Symbol operator + (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1);
Symbol operator * (Symbol Arg1, Symbol Arg2);
Symbol operator / (Symbol Arg1, Symbol Arg2);



void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}

int main()
{
  //  Symbol wynik_fun, wynik_alg, wynik_ope;
  //  Symbol y, x;

  /*
  cout<<"Podaj liczby w formacie x y \n gdzie x jest pierwsza liczba uzyta do operacji a y druga"<<endl;
 
  cout << "Podaj x";
  cin >> x ;
  cout << "Podaj y";
  cin >> y;
  */


  //  x=a,y=c;

  //  Symbol z;
  //  z=c;
  //  cout<<"Uzyte parametry to:x="<<x<<" i y="<<y<<endl;
  
  //  cout << "Dodaj: " << Dodaj(y,x); << endl;
  
  //  cout << "Operator -: " <<operator - (x,y) << endl;
  
  //  cout << "-: " << x-y << endl;
  
  //  cout<<"oryginalna wartosc "<<z<<" przeciwna "<<-z<<endl;
  
  cout<<"a+d   "<<a+d<<endl;
  cout<<"a-b   "<<a-b <<endl;
  cout<<"a+(b+c)  "<<a+(b+c) <<endl;
  cout<<"c-(d-a)  "<<c-(d-a) <<endl;

  
  /* czesc ktora sie tutaj znajdowala w oryginalnym pliku usunalem 
     aby nie powstawaly niepotrzebne bledy podczas kompilacji */
  
}


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/*         *** FUNKCJE ***         */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za dodawanie dwóch argumentow. Wynik dodawania */
/*   jest taki jak w tabelce dostarczonej do zadania.               */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol Dodaj(Symbol Arg1, Symbol Arg2) 
{
  return TabliczkaDodawania[Arg2][Arg1];
}

/*     EDYTOWAC OPIS  */

/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za dodawanie dwóch argumentow. Wynik dodawania */
/*   jest taki jak w tabelce dostarczonej do zadania.               */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
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
  return TabliczkaDodawania[Arg2][Arg1];
}

Symbol operator - (Symbol Arg1)
{
  return ZnajdzPrzeciwny(Arg1);
}

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za odejmowanie dwóch argumentow.          */
/*   Odejmowanie jest dodawaniem elementow przeciwnych. Elementy    */
/*   przeciwne dla siebie to a i b oraz c i d. Arg2 jest zmieniany  */
/*   na przeciwny. Wynik jest taki jak w tabelce dodawania.         */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol operator - (Symbol Arg1, Symbol Arg2)
{
  return Arg1+(-Arg2);
}
