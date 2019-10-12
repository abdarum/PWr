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

#define MAX 512          /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024     /* Dlugosc buforow pomocniczych */
#define END 0 /* Symbol ktory jest wywolywany jako koniec programu */


int main() {
  int obraz[MAX][MAX] ;
  int tmp[MAX][MAX]; 
  int wymx,wymy,odcieni,biel,czern;
  int wybor;
  int i;

  int odczytano = 0;
  FILE *plik;
  FILE *tmp_file;
  char nazwa[100];
  char nazwa_nowa[100];
  /*!!!!!!!!!!!!!!!!!!!!!!!*/

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  plik=fopen(nazwa,"r");
  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
  fclose(plik);

  wybor=-1;
  while(wybor!=END){
  while((plik==NULL) && (wybor!=END)) {      
      printf("\nPlik ktory podales nie istnieje. Podaj inny plik lub zakoncz program.\n");
      printf("Jezeli chcesz wybrac inny plik wcisnij 1.\nJesli chcesz zakonczyc program wcisnij 0.\n\n\t");    
      scanf("%d",&wybor);
      switch(wybor){
        case 1:
	  printf("Podaj nazwe pliku:\n");
	  scanf("%s",nazwa);
	  plik=fopen(nazwa,"r");
	  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
	  fclose(plik);
	  break;
        case END:
	  odczytano=-1;
	  break;
      }
  }


  while((odczytano == 0) && (wybor != END)) {      
      printf("\nPlik ktory podales jest pusty. Podaj inny plik lub zakoncz program.\n");
      printf("Jezeli chcesz wybrac inny plik wcisnij 1.\nJesli chcesz zakonczyc program wcisnij 0.\n\n\t");    
     scanf("%d",&wybor);     
      switch(wybor){
        case 1:
	  printf("Podaj nazwe pliku:\n");
	  scanf("%s",nazwa);
	  plik=fopen(nazwa,"r");
	  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
	  fclose(plik);
	  break;
        case END:
	  break;
      }
  }


  /*!!!!!!!!!!!!!!!!!!!!!!*/
 
  /*!!!!!!!!!!!! PROSTE MENU !!!!!!!!!!!!!*/
  i=0;
  while((wybor != END) && (plik != NULL) && (odczytano !=0)){
    printf("\nMenu programu ktory przetwarza obrazy z rozszerzeniem .pgm\n");
    printf("\t1. Negatyw\n");
    printf("\t2. Konturowanie\n");
    printf("\t3. Rozciaganie histogramu\n");
    printf("\t4. Zmiana poziomow\n");
    printf("\t5. Wyswietl obraz\n");
    printf("\t6. Zapisz do pliku\n");
    printf("\t7. Otworz inny plik\n");
    printf("\t0. Zakoncz program\n\n\t");
    scanf("%d%",&wybor);
    printf("\n");
      switch(wybor){

      case 1:  /* NEGATYW */
	if(i==0) negatyw(wymx,wymy,obraz,tmp);
	else negatyw(wymx,wymy,tmp,tmp);	
	tmp_file=fopen("tmp.pgm","wr");
	zapisz(tmp_file,wymx,wymy,odcieni,tmp);
	fclose(tmp_file);
	break;

      case 2:  /* KONTUROWANIE */
	if(i==0) konturowanie(wymx,wymy,obraz,tmp);
	else konturowanie(wymx,wymy,tmp,tmp);
	tmp_file=fopen("tmp.pgm","wr");
	zapisz(tmp_file,wymx,wymy,odcieni,tmp);
	fclose(tmp_file);
	break;

      case 3:  /* ROZCIAGANIE HISTOGRAMU */
	if(i==0) rozciaganie_histogramu(wymx,wymy,obraz,tmp,odcieni);
	else rozciaganie_histogramu(wymx,wymy,tmp,tmp,odcieni);
	tmp_file=fopen("tmp.pgm","wr");
	zapisz(tmp_file,wymx,wymy,odcieni,tmp);
	fclose(tmp_file);
	break;

      case 4:  /* Zmiana poziomów - interfejs użytkownika */
	printf("\n\tFunkcja zmieniajaca skale szarosci.");
	printf("\n\tWartosci nalezy podac w procentach:");
	printf("\n\tnp. 80%% biel i 20%% czern odpowiada napisowi:\n\t80 20 \n\n");
	printf("Podaj nowe parametry skali szarosci: ");
	scanf("%d %d",&biel,&czern);
	if(i==0) zmiana_poziomow(wymx,wymy,obraz,tmp,biel,czern,odcieni);
	else zmiana_poziomow(wymx,wymy,tmp,tmp,biel,czern,odcieni);
	tmp_file=fopen("tmp.pgm","wr");
	zapisz(tmp_file,wymx,wymy,odcieni,tmp);
	fclose(tmp_file);
	break;

 
      case 5: /* Wyswietlenie edytowanego obraza zewnetrznym programem */
	if(i==0){
	  tmp_file=fopen("tmp.pgm","wr");
	  zapisz(tmp_file,wymx,wymy,odcieni,obraz);
	  fclose(tmp_file);
	}
	wyswietl("tmp.pgm");
	break;

      case 6: /* Zapisywanie do pliku - zmiana nazwy z tmp.pgm na podana przez uzytkownika*/
	printf("Podaj nowa nazwe twojego pliku:\n\t ");
	scanf("%s",&nazwa_nowa);
	rename("tmp.pgm",nazwa_nowa);
	break;

      case 7: /* Otwiera inny plik */
	  printf("Podaj nazwe pliku:\n");
	  scanf("%s",nazwa);
	  plik=fopen(nazwa,"r");
	  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
	  fclose(plik);
	  i=0;
	  break;

      case END:
      break;
      }
      if(wybor!=7)  i++;
  }
  }
 return 0;
}


/******** SPRAWOZDANE ********/
/*

Funkcje zostaly podzielone na moduly ze wzgledu na rodzaje dzialan:
- przetwarzanie odpowiada za funkcje zwiazane z przetwarzaniem obrazu 
- odczyt_zapis_obrazu funkcja odpowiedzialna za otwieranie i zapis obrazu

*/
