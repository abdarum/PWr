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

#define END 0 /* Symbol ktory jest wywolywany jako koniec programu */

typedef struct{
  int **tablica;
  int wymx, wymy, szarosci;
}obraz_struct

;
void odczytaj_plik(){

	  printf("Podaj nazwe pliku:\n");
	  scanf("%s",nazwa);
	  plik=fopen(nazwa,"r");
	  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
	  fclose(plik);

}


int main(){

  int wybor;
  int i;

  int odczytano = 0;
  FILE *plik;
  FILE *tmp_file;
  /*!!!!!!!!!!!!!!!!!!!!!!!*/

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  plik=fopen(nazwa,"r");
  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
  fclose(plik);



  return 0;
}


/******** SPRAWOZDANE ********/
/*

Funkcje zostaly podzielone na moduly ze wzgledu na rodzaje dzialan:
- przetwarzanie odpowiada za funkcje zwiazane z przetwarzaniem obrazu 
- odczyt_zapis_obrazu funkcja odpowiedzialna za otwieranie i zapis obrazu

*/
