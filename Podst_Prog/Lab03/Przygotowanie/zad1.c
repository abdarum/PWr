#include<stdio.h>


#define ROZMIAR_TABLICY 10
#define PRZYPISZ_ILORAZ 0
#define ZMIEN_ZNAKI 1
#define I_DO_WYPISANIA 3
#define J_DO_WYPISANIA 7


  int tablica_glowna[ROZMIAR_TABLICY][ROZMIAR_TABLICY];

  int przypisanie_wartosci_tablicy(int funkcja);
  int wypisz_tablice();



int main(){

  przypisanie_wartosci_tablicy(PRZYPISZ_ILORAZ);
  wypisz_tablice();
  printf ("\n\n\n");

  przypisanie_wartosci_tablicy(ZMIEN_ZNAKI);
  wypisz_tablice();
}


int przypisanie_wartosci_tablicy(int funkcja){
  int i, j;
  for(i = 0; i < ROZMIAR_TABLICY; i++){
    for(j = 0; j < ROZMIAR_TABLICY; j++){
      switch(funkcja){
      case PRZYPISZ_ILORAZ:
	tablica_glowna[i][j] = ((i+1)*(j+1));
	  break;

      case ZMIEN_ZNAKI:
	tablica_glowna[i][j] *= -1;
	break;
      }
    }
  }
  return 0;
}


int wypisz_tablice(){
  int i,j;
  for(i = 0; i < I_DO_WYPISANIA; i++){
    for(j = 0; j < J_DO_WYPISANIA; j++){
      printf("%4d", tablica_glowna[i][j]);
    }
    printf("\n");
  }
  return 0;
}
