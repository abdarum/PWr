/*

Program: przeciecia_zera.c ver. 1.0
Program oblicza przecięcia zera
Praca Kornela Stefańczyka nr 235420

 */

#include<stdio.h>

#define KONIEC_OKRESU 99
#define KONIEC_STRUMIENIA 99

#define PLUS 1
#define MINUS 0 /* dane pomocnicze do określania znaku danej  */


#define MIN_DANA -10 /* Przedaial w ktorym moze sie zawierac wczytana dana */
#define MAX_DANA 10

#define MIN_OKRES 8 /* Przedaial w ktrym moze się zawierac liczba przeciec */
#define MAX_OKRES 14

int znak_liczby, znak_starej_liczby;

int main(){

  int licznik = 0; /* dana licznika - 99 liczb oznacza okres 10 sekund  */
  int dana = 0; /* dana liczbowa która wczytujemy  */
  int przec = 0; /* liczba przeciec w pojedynczym okresie  */
  int laczna_liczba_przeciec = 0; /* suma przeciec z calego programu */


  int okresl_znak_liczby(int dana); 

/* program nie bedzie liczyl przeciecia gdy pierwsza liczba jest dodatnia */
  znak_liczby = znak_starej_liczby = 0;
									    

while(dana != KONIEC_STRUMIENIA){

    scanf("%d", &dana);
 /* Pomijanie liczb nie zawierajacych się w przedziale od -10 do 10  */
    if(MIN_DANA <= dana && dana <= MAX_DANA){

      okresl_znak_liczby(dana);
      
/* Bada czy nastapilo przeciecie  */
      if(znak_starej_liczby != znak_liczby){
	/*	printf("przeciecie\n");
	znak_starej_liczby = znak_liczby;
	*/
/* bada czy przeciecie nie nastapilo poimedzy dwoma okresami, jesli tak to je odrzuca  */
if(licznik != 0) przec++;
 


      }
    }
 /* Bada czy nastapil okres 99 co odpowiada 10 sekundom  */ 
      if(licznik < KONIEC_OKRESU){
	  licznik++; 
	  znak_starej_liczby = znak_liczby;

	  }    
/* Gdy okres jest pelen(licznik == 99) program wyswietla dane koncowe */
/* Gdy liczba przeciec zawiera sie w podanym przedziale wypisije ta liczbe  */  
else    
  if((MIN_OKRES <= przec) && (przec <= MAX_OKRES)){
	printf("Liczba przeciec w okresie  wynosi: %d\n", przec);
	laczna_liczba_przeciec += przec;
	przec = 0;
	licznik = 0;
	} 
/* Gdy liczba przeciec nie zawiera sie w podanym przedziale wypisuje blad  */
  else{
    printf("Blad! Liczba przeciec: %d nie zawiera sie w odpowiednim przedziale.\n", przec);
    przec = 0;
    licznik = 0;

   }
  }

 printf("Program wczytal znak konca danych tzn 99\n");
}

 /* Część programu odpowiedzialna za sprawdzenie znaku i przypisanej  do niej stalej PLUS lub MINUS  */

int okresl_znak_liczby(int dana){

  if(dana >= 0)   
    if(dana == 0)
    znak_liczby = znak_starej_liczby;
  else znak_liczby = PLUS;
 else znak_liczby = MINUS;

  return 0;

}
