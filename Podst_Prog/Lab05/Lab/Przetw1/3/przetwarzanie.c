#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include "przetwarzanie.h"

/* Funkcja tworzy negatyw obrazu */ 
void negatyw(obraz_struct *obraz){
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  int i,j;

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
       tablica[i][j] = (obraz->szarosci - tablica[i][j]);
    }
  }
}


/* Funkcja uwydatnia kontury */
void konturowanie(obraz_struct *obraz){
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  int i,j;

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      tablica[i][j] = (abs(tablica[i+1][j]-tablica[i][j])+abs(tablica[i][j+1]-tablica[i][j]));
    }
  }
}
    
/* Funkcja zmiany poziomow - nalezy podac wartosc w procentach */
void zmiana_poziomow(obraz_struct *obraz,int czern,int biel){
  int i,j;
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
   
  biel=(obraz->szarosci*biel)/100; 
  czern=(obraz->szarosci*czern)/100;
    

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      if(tablica[i][j] <= czern) tablica[i][j] = 0;
      else if(tablica[i][j] < biel) tablica[i][j] = (((tablica[i][j]-czern)*(obraz->szarosci))/(biel-czern));
      else tablica[i][j] = obraz->szarosci;
    }
  }
}

/* Rozciąganie histogramu */
void rozciaganie_histogramu(obraz_struct *obraz){
  int i,j; 
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
   
  /* Szukanie najmniejszej i największej wartosci */
  int max=0, min=obraz->szarosci;
  /*  printf("przed min - %3d | max - %3d\n",min,max); */
  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      if(tablica[i][j]>max) max=tablica[i][j];
      if(tablica[i][j]<min) min=tablica[i][j];
    }
  }


  /*  printf("po    min - %3d | max - %3d\n",min,max); */
  
  /* Rozciąganie histogramu */
  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      tablica[i][j]=(((tablica[i][j]-min)*obraz->szarosci)/(max-min));
    }
  }
}

/* Progowanie */
void progowanie(obraz_struct *obraz,int prog){
  int i,j;
  prog=(obraz->szarosci*prog)/100; 
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
    

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      if(tablica[i][j] <= prog) tablica[i][j] = 0;
      else tablica[i][j] = obraz->szarosci;
    }
  }
}


/* Polprogowanie czerni */
void progowanie_czerni(obraz_struct *obraz,int prog){
  int i,j;
  prog=((obraz->szarosci)*prog)/100;
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
    

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      if(tablica[i][j] <= prog) tablica[i][j] = 0;
    }
  }
}

/* Polprogowanie bieli */
void progowanie_bieli(obraz_struct *obraz,int prog){
  int i,j;
  prog=(obraz->szarosci*prog)/100;
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
    

  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      if(tablica[i][j] > prog) tablica[i][j] = obraz->szarosci;
    }
  }
}


/* Rozmywanie poziome */
void rozmywanie_poziome(obraz_struct *obraz){
  int i,j;
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
    
  int tmp_tab[obraz->wymy][obraz->wymx];
  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      tmp_tab[i][j] = tablica[i][j];
    }
  } 

  for(i=0;i<obraz->wymy;i++){
    for(j=1;j<(obraz->wymx-1);j++){
      tablica[i][j] =(tmp_tab[i][j-1]+tmp_tab[i][j]+tmp_tab[i][j+1])/3;
    }
  }
}


/* Rozmywanie pionowe */
void rozmywanie_pionowe(obraz_struct *obraz){
  int i,j;
  int (*tablica)[obraz->wymx];
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
    
  int tmp_tab[obraz->wymy][obraz->wymx];
  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      tmp_tab[i][j] = tablica[i][j];
    }
  } 

  for(i=1;i<(obraz->wymy-1);i++){
    for(j=0;j<obraz->wymx;j++){
      tablica[i][j] =(tmp_tab[i-1][j]+tmp_tab[i][j]+tmp_tab[i+1][j])/3;
    }
  }
}

	
