/*

Program: przeciecia_zera.c ver. 1.1
Program oblicza przecięcia zera
Praca Kornela Stefańczyka nr 235420

Sprawozdanie znajduje sie na koncu pliku po programie.

*/

#include<stdio.h>

#define KONIEC_OKRESU 99
#define KONIEC_STRUMIENIA 99

/* dane pomocnicze do określania znaku danej  */
#define PLUS 1
#define MINUS 0

/* Przedaial w ktorym moze sie zawierac wczytana dana */
#define MIN_DANA -10
#define MAX_DANA 10

/* Przedaial w ktrym moze się zawierac liczba przeciec */
#define MIN_OKRES 8
#define MAX_OKRES 14

int znak_liczby, znak_starej_liczby;

int main(){

  int licznik = 0; /* dana licznika - 99 liczb oznacza okres 10 sekund  */
  int dana = 0;    /* dana liczbowa która wczytujemy  */
  int przec = 0;   /* liczba przeciec w pojedynczym okresie  */
 

  int okresl_znak_liczby(int dana); 


  znak_liczby = znak_starej_liczby = 0;
									    
  /* Petla bedzie sie wykonywala dopoki wczytana dana nie bedzie rowna znakowi konca danych - liczby 99 */
while(dana != KONIEC_STRUMIENIA){

    scanf("%d", &dana);
 /* Pomijanie liczb nie zawierajacych się w przedziale od -10 do 10  */
    if(MIN_DANA <= dana && dana <= MAX_DANA){

      okresl_znak_liczby(dana);
/* Bada czy nastapilo przeciecie  */
     if(znak_starej_liczby != znak_liczby){
/* Odn1 Ponizszy komentarz jest pozostaloscia po wstepnym testowaniu programu*/
	/*	printf("przeciecie\n");
	znak_starej_liczby = znak_liczby;
	*/

/* Bada czy przeciecie nie nastapilo poimedzy dwoma okresami, jesli tak to je odrzuca  */
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

/*                       *** SPRAWOZDANIE ***                              */

/* Program byl testowany podczas pisania. 

1. Najpierw powstala funkcja znak liczby. Gdy ta funkcja byla gotowa zmodyfikowalem program tak zeby wypisywal na wyjscie znak liczby ktora wpisalem na klawiaturze. Jezeli byl plus to na wyjsciu pokazywala sie zgodnie z deklaracja 1. Gdy liczba byla ujemna to na wyjsciu otrzymywalismy 0. W razie gdy liczba byla rowna 0 program wypisywal taki znak jaki miala poprzednia liczba. 

2. Gdy okreslanie znaku dzialalo napisalem czesc odpowiedzialna za sprawdzanie czy wczytana liczba nie jest rowna 99. Pozniej przyszedl czas na napisanie czesci odpowiedzialnej za badanie czy nastapilo przeciecie (mechanizm polega na sprawdzeniu czy znak liczby jest inny od poprzedniej). Odn1 to czesc programu ktora wypisywala kazde przeciecie. Dodalem rowniez warunek odpowiedzialny za sprawdzanie czy przeciecie nie nastapilo pomiedzy okresami czasu i wtedy je odrzucalo.

3. Ostatnia czesc programu(badanie okresu) byla sprawdzona na plikach ktore byly zamieszczone na stronie internetowej kursu. Ten test rowniez przebiegl pomyslnie.

Koniec
*/
