#include <iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/
enum Symbol {e, a, b, c, d};
Symbol TabliczkaDodawania[5][5] = {{e, a, b, c, d},{a, d, e, b, c},{b, e, c, d, a},{c, b, d, a, e},{d, c, a, e, b}};
Symbol TabliczkaMnozenia[5][5] = {{e, e, e, e, e},{e, a, b, c, d},{e, b, a, d, c},{e, c, d, b, a},{e, d, c, a, b}};

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
Symbol Dodaj(Symbol Arg1, Symbol Arg2);
Symbol Odejmij(Symbol Arg1, Symbol Arg2);
Symbol Mnoz(Symbol Arg1, Symbol Arg2);
Symbol Dziel(Symbol Arg1, Symbol Arg2);


/*
  Definicja przeciazen operatorow
*/ 
Symbol operator + (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg1, Symbol Arg2);
Symbol operator * (Symbol Arg1, Symbol Arg2);
Symbol operator / (Symbol Arg1, Symbol Arg2);

int main()
{
  Symbol  wynik_fun, y, x;

  cout<<"Podaj liczby w formacie x y \n gdzie x jest pierwsza liczba uzyta do operacji a y druga"<<endl;

  x=c,y=a;
  cout<<"Uzyte parametry to:x="<<x<<" i y="<<y<<endl;
  wynik_fun=Odejmij(y,x);
  cout << "Odejmij: " << wynik_fun << endl;


  wynik_fun=operator - (y,x);
  cout << "Operator -: " << wynik_fun << endl;

  wynik_fun=y-x;
  cout << "-: " << wynik_fun << endl;
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
/********************************************************************/Symbol Dodaj(Symbol Arg1, Symbol Arg2) 
{
  return TabliczkaDodawania[Arg2][Arg1];
}


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za odejmowanie dwóch argumentow. Odejmowanie   */
/*   jest dodawaniem elementow przeciwnych. Elementy przeciwne dla  */
/*   siebie to a i b oraz c i d. Arg2 jest zmieniany na przeciwny   */
/*   Wynik jest taki jak w tabelce dodawania.                       */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol Odejmij(Symbol Arg1, Symbol Arg2)
{
  if(Arg2==a) Arg2=b;
  else  if(Arg2==b) Arg2=a;
  if(Arg2==c) Arg2=d;
  else if(Arg2==d) Arg2=c;
  return TabliczkaDodawania[Arg2][Arg1];
}


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za mnozenie dwóch argumentow. Wynik mnozenia   */
/*   jest taki jak w tabelce dostarczonej do zadania.               */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol Mnoz(Symbol Arg1, Symbol Arg2)
{
  return TabliczkaMnozenia[Arg2][Arg1];
}

/*
Symbol Dziel(Symbol Arg1, Symbol Arg2)
{
  if(Arg2==c) Arg2=d;
  else  if(Arg2==d) Arg2=c;
  return TabliczkaMnozenia[Arg2][Arg1];
}
*/



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
  if(Arg2==a) Arg2=b;
  else  if(Arg2==b) Arg2=a;
  if(Arg2==c) Arg2=d;
  else if(Arg2==d) Arg2=c;
  return TabliczkaDodawania[Arg2][Arg1];
}


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za mnozenie dwóch argumentow. Wynik       */
/*    mnozenia jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol operator * (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaMnozenia[Arg2][Arg1];
}

/*
Symbol operator / (Symbol Arg1, Symbol Arg2)
{
  if(Arg2==c) Arg2=d;
  else  if(Arg2==d) Arg2=c;
  return TabliczkaMnozenia[Arg2][Arg1];
}
*/
