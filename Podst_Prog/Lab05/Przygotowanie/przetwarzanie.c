
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "przetwarzanie.h"

/* Funkcja tworzy negatyw obrazu */ 
void negatyw(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]){

  int i,j;

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
       obraz_wyj[i][j] = (MAX_SKALA_SZAROSCI - obraz_wej[i][j]);
    }
  }
}


/* Funkcja uwydatnia kontury */
void konturowanie(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]){
  int i,j;

  for(i=0;i<y;i++){
    for(j=0;j<y;j++){
      obraz_wyj[i][j] = (abs(obraz_wej[i+1][j]-obraz_wej[i][j])+abs(obraz_wej[i][j+1]-obraz_wej[i][j]));
    }
  }
}
    
/* Funkcja zmiany poziomow - nalezy podac wartosc w procentach */
void zmiana_poziomow(int x,int y,int obraz_wej[][MAX],int obraz_wyj[][MAX],int biel,int czern,int skala){
  
  biel=(skala*biel)/100;
  czern=(skala*czern)/100;
    

  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      if(obraz_wej[i][j] <= czern) obraz_wyj[i][j] = 0;
      else if(obraz_wej[i][j] < biel) obraz_wyj[i][j] = (((obraz_wej[i][j]-czern)*(skala))/(biel-czern));
      else obraz_wyj[i][j] = skala;
    }
  }
}

/* Rozciąganie histogramu */
void rozciaganie_histogramu(int x,int y,int obraz_wej[][MAX],int obraz_wyj[][MAX],int skala){
  
  /* Szukanie najmniejszej i największej wartosci */
  int max=0, min=skala;
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      if(obraz_wej[i][j]>max) max=obraz_wej[i][j];
      if(obraz_wej[i][j]<min) min=obraz_wej[i][j];
    }
  }

  /* Rozciąganie histogramu */
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      obraz_wyj[i][j]=(((obraz_wej[i][j]-min)*skala)/(max-min));
    }
  }
}

