/*

Program: przetwarzanie_obrazow.c ver. 2.1
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
  obraz.rgbw=opcje->rgbw;
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
      printf("negatyw\n");
      negatyw(&obraz);    
    }
    
    if(opcje->progowanie==1){
      printf("progowanie |prog %d\n",opcje->w_prog);
      progowanie(&obraz,opcje->w_prog);    
    }
    
    if(opcje->progowanie_czerni==1){
      printf("progowanie czerni| prog %d\n",opcje->c_prog);
      progowanie_czerni(&obraz,opcje->c_prog); 
    }
    
    if(opcje->progowanie_bieli==1){
      printf("progowanie bieli |prog %d\n",opcje->b_prog);
      progowanie_bieli(&obraz,opcje->b_prog);
    }
    
    if(opcje->zmiana_poziomow==1){
      printf("zmiana poziomow |czern %d |biel %d\n",opcje->poz_czerni,opcje->poz_bieli);
      zmiana_poziomow(&obraz,opcje->poz_czerni,opcje->poz_bieli);
    }
    
    if(opcje->konturowanie==1){
      printf("konturowanie\n");
      konturowanie(&obraz);
    }
  
  
    if(opcje->rozmywanie_poziome==1){
      printf("rozmywanie poziome\n");
      rozmywanie_poziome(&obraz);    
    }
    
    
    if(opcje->rozmywanie_pionowe==1){
      printf("rozmywanie pionowe\n");
      rozmywanie_pionowe(&obraz);    
    }
    
    if(opcje->rozciaganie_histogramu==1){
      printf("rozciaganie histogramu\n");
      rozciaganie_histogramu(&obraz);
    }
    
  } /* koniec if(bledy_opcji!=W_OK) */

  zapisz(opcje->plik_wy,&obraz);
  fclose(opcje->plik_wy);
  
  if(opcje->wyswietlenie==1){
    printf("wyswietl\n");
    printf("%s\n",opcje->nazwa_pliku);
    wyswietl(opcje->nazwa_pliku);    
  }

  zwolnij_obraz(&obraz);
  free(opcje);

  return 0;
}


/******** SPRAWOZDANE ********/
/*

Funkcje zostaly podzielone na moduly ze wzgledu na rodzaje dzialan:
- przetwarzanie odpowiada za funkcje zwiazane z przetwarzaniem obrazu 
- odczyt_zapis_obrazu funkcja odpowiedzialna za otwieranie i zapis obrazu

*/


