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



int main(int argc,char *argv[]){

  int wybor;
  int i;
  obraz_struct obraz;
  char nazwa[100];

  int odczytano = 0;
  FILE *plik;
  FILE *tmp_file;
  /*!!!!!!!!!!!!!!!!!!!!!!!*/

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  /*
  nazwa={kubus.pgm}; */
  plik=fopen(nazwa,"r");
  odczytano = czytaj(plik,&obraz);
  fclose(plik);
  double gamma_tmp;
  printf("podaj wartosc gamma:\n");
  scanf("%f", &gamma_tmp);
  gamma(&obraz, gamma_tmp);



  tmp_file=fopen("tmp.pgm","wr");
  zapisz(tmp_file,&obraz);
  fclose(tmp_file);
  char tmp[]="tmp.pgm";
  wyswietl(tmp); 
  return 0;
}


/******** SPRAWOZDANE ********/
/*

Funkcje zostaly podzielone na moduly ze wzgledu na rodzaje dzialan:
- przetwarzanie odpowiada za funkcje zwiazane z przetwarzaniem obrazu 
- odczyt_zapis_obrazu funkcja odpowiedzialna za otwieranie i zapis obrazu

*/
