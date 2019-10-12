#include<stdio.h>


#define ROZMIAR_TABLICY 10
#define PRZYPISZ_ILORAZ 0
#define ZMIEN_ZNAKI 1
#define PRZYPISZ_1 3
#define I_DO_WYPISANIA 3
#define J_DO_WYPISANIA 7


  int tablica_glowna[ROZMIAR_TABLICY][ROZMIAR_TABLICY];

  int przypisanie_wartosci_tablicy(int funkcja);
  int wypisz_tablice();



int main(){
  
  int x = 0,y=0;



  przypisanie_wartosci_tablicy( PRZYPISZ_1);

  while(x != '4'){
   if(x != '\n'){
    printf("\n");
  printf("Proste menu:\n");
printf("Wybierz czesc programu ktora ma sie wykonac - uzywajac klawiatury wprowadz:\n");
    printf(" 1 aby przypisac wartosc iloczynu tablicy\n");
    printf(" 2 aby przypisacprzeciwny znak kazdemu elementowi z tablicy tablicy(domyslnie kazdy wyraz tablicy ma wartosc 1)\n");
    printf(" 3 aby wykonac dwie poprzednie funkcje tablicy\n");
    printf(" 4 aby zakonczyc dzialanie programu\n");
    printf("\n");
   }
    x = getchar();
    /* scanf("%d", &x);*/
    switch(x){

 case '1':
  przypisanie_wartosci_tablicy(PRZYPISZ_ILORAZ);
  printf("Zawartosc tablicy:\n");
  wypisz_tablice();
  break;

 case '2':
  przypisanie_wartosci_tablicy(ZMIEN_ZNAKI);
  printf("Zawartosc tablicy po zmianie znakow:\n");
  wypisz_tablice();
  break;

 case '3':
  przypisanie_wartosci_tablicy(PRZYPISZ_ILORAZ);
  printf("Zawartosc tablicy:\n");
  wypisz_tablice();

  printf ("\n\n");

  przypisanie_wartosci_tablicy(ZMIEN_ZNAKI);
  printf("Zawartosc tablicy po zmianie znakow:\n");
  wypisz_tablice();
  break;

 case '4':
  printf("Program zakonczyl swoje dzialanie\n"); 
  break;
    }
  }
}

int przypisanie_wartosci_tablicy(int funkcja){
  int i, j;
  for(i = 0; i < ROZMIAR_TABLICY; i++){
    for(j = 0; j < ROZMIAR_TABLICY; j++){
      switch(funkcja){
      case PRZYPISZ_ILORAZ:
	tablica_glowna[i][j] = ((i)*(j));
	  break;

      case ZMIEN_ZNAKI:
	tablica_glowna[i][j] *= -1;
	break;
   
     case PRZYPISZ_1:
        tablica_glowna[i][j] = 1;
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
