/*

Program: przetwarzanie_obrazow.c ver. 2.2
Program przetwarza obrazy w formacie ppm
Praca Kornela Stefańczyka nr 235420

Sprawozdanie znajduje sie na koncu pliku po programie.

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "odczyt_zapis_obrazu.h"
#include "przetwarzanie.h"
#include "opcje.h"


int main(int argc,char **argv){

  int i,bledy_opcji;
  w_opcje *opcje;
  obraz_struct obraz;

  int odczytano = 0;
  opcje = (w_opcje *) malloc(sizeof(w_opcje));
  bledy_opcji=przetwarzaj_opcje(argc,argv,opcje);
  obraz.rgbw=opcje->rgbw; /* przypisanie ktore kolory maja byc edytowane */
  odczytano = czytaj(opcje->plik_we,&obraz);
  fclose(opcje->plik_we);
  if((opcje->rgbw).bw==1)
    zrob_czarno_bialy(&obraz);

  if(bledy_opcji!=W_OK){
    fprintf(stderr,"Blad - %d\n",bledy_opcji);
    switch(bledy_opcji){

    case B_NIEPOPRAWNAOPCJA:
      fprintf(stderr,"Niepoprawnie wpisano opcje\n");
      break;

    case B_BRAKNAZWY:
      fprintf(stderr,"Nie podano nazwy pliku wejsciowego\n");
      break;

    case B_BRAKWARTOSCI:
      fprintf(stderr,"Brak lub zly format wartosci parametru\n");
      break;

    case B_BRAKPLIKU:
      fprintf(stderr,"Nie udalo sie otworzyc pliku wejsciowego\n");
      break;
    }
  }
  else{

    if(opcje->negatyw==1){
      negatyw(&obraz);    
    }
    
    if(opcje->progowanie==1){
      progowanie(&obraz,opcje->w_prog);    
    }
    
    if(opcje->progowanie_czerni==1){
      progowanie_czerni(&obraz,opcje->c_prog); 
    }
    
    if(opcje->progowanie_bieli==1){
      progowanie_bieli(&obraz,opcje->b_prog);
    }
    
    if(opcje->zmiana_poziomow==1){
      zmiana_poziomow(&obraz,opcje->poz_czerni,opcje->poz_bieli);
    }
    
    if(opcje->konturowanie==1){
      konturowanie(&obraz);
    }
  
  
    if(opcje->rozmywanie_poziome==1){
      rozmywanie_poziome(&obraz);    
    }
    
    
    if(opcje->rozmywanie_pionowe==1){
      rozmywanie_pionowe(&obraz);    
    }
    
    if(opcje->rozciaganie_histogramu==1){
      rozciaganie_histogramu(&obraz);
    }
    
  } /* koniec if(bledy_opcji!=W_OK) */

  zapisz(opcje->plik_wy,&obraz);
  fclose(opcje->plik_wy);
  
  if(opcje->wyswietlenie==1){
    if(opcje->zapisz==1){
    wyswietl(opcje->nazwa_pliku);    
    }
    else
      fprintf(stderr,"Aby wyswietlic plik musisz go zapiszac\n");
  }

  zwolnij_obraz(&obraz);
  free(opcje);

  return 0;
}


/************** SPRAWOZDANE ****************/
/*

Funkcje zostaly podzielone na moduly ze wzgledu na rodzaje dzialan:
- przetwarzanie odpowiada za funkcje zwiazane z przetwarzaniem obrazu 
- odczyt_zapis_obrazu funkcja odpowiedzialna za otwieranie i zapis 
   obrazu
- funkcje obslugi opcji wywolanych w programu

Program byl pisany fragmentami:

- pierwszym krokiem bylo stworzenie struktur, podzielenie programu 
   na moduly i sprawdzenie komunikacji modulow miedzy soba. Bylo to
   robione na pliku przetwarzania obrazow 1. 

- kolejnym krokiem bylo stworzenie alokowanej tablicy dla 
   przetwarzania szarych obrazow. Gdy to sie udalo zrobilem inne 
   funkcje, ktorych nie bylo w pierwszej wersji programu.

- kolejnym etapem bylo przerobic funkcje "opcje.c" - wyciagajac z 
   niej plik naglowkowy, dodac poszczegolne litery opcji ktore dodalem

- ostatnim etapem pracy z czarnobialymi plikami bylo testowanie 
    programu, wychwycenie powstalych bledow. Gdy wszystko dzialalo 
    po mojej mysli mialem pewnosc, że przy kolorowych obrazach nie
    bede mial tych problemow
    albo przynajmniej bede wiedzial gdzie sa bledy.

- pierwszy etap pracy nad kolorowym obrazem zaczal sie od edycji
   struktur, aby pomiescily trzy tablice dla kolorow + 1 tablice dla
   funkcji konwersji do czarnoblialego obrazu. 

- gdy tablice dzialaly zaczalem zmieniac funkcje z pliku
   "przetwarzanie.c" tak, aby dzialaly dla kolorowych obrazow.
   Majac zamiar zrobic edycje wybranych kolorow dodalem strukture 
   zawierajaca flagi dla konwersji poszczegolnych kolorow. Wiec 
   funkcje tworzylem tak aby dzialal kazdy kolor osobno.

- gdy funkcje w pelni dzialaly przystapilem do dopisania opcji m.
   

  Program byl testowany na kazdym etapie wiele razy, aby miec punkt 
  odniesienia do dzialajacego fragmentu. Na koniec wszystko zostalo 
  jeszcze raz przetestowane.

  Program zaklada, ze jezeli uzytkownik ma zamiar konwertowac obraz do
  szarosci to w zapisie pliku da rozszerzenie ".pgm". Program zaklada
  rowniez, ze aby wyswietlic plik musi on byc zapisany.

*/


