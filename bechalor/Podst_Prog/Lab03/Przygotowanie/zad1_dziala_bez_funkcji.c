#include<stdio.h>


#define ROZMIAR_TABLICY 10
#define PRZYPISZ_ILORAZ 0
#define ZMIEN_ZNAKI 1
#define I_DO_WYPISANIA 10
#define J_DO_WYPISANIA 10

int main(){

  int tablica_glowna[ROZMIAR_TABLICY][ROZMIAR_TABLICY];
  int i = 0, j = 0; 


  for(i = 0; i < ROZMIAR_TABLICY; i++){
    for(j = 0; j < ROZMIAR_TABLICY; j++){
      tablica_glowna[i][j] = (i+1)*(j+1);
    }
  }

  for(i = 0; i < I_DO_WYPISANIA;i++){
    for(j = 0; j < J_DO_WYPISANIA; j++){
      printf("%4d", tablica_glowna[i][j]);
    }
  printf("\n");
  }

  printf("\n\n\n");

  for(i = 0; i < ROZMIAR_TABLICY; i++){
    for(j = 0; j < ROZMIAR_TABLICY; j++){
      tablica_glowna[i][j] *= -1;
    }
  }

  for(i = 0; i < I_DO_WYPISANIA;i++){
    for(j = 0; j < J_DO_WYPISANIA; j++){
      printf("%4d", tablica_glowna[i][j]);
    }
  printf("\n");
  }
}
