
#include "przetwarzanie.h"


/****************************/
/*                          */
/*        NEGATYW           */
/*                          */
/****************************/

/* Funkcja tworzy negatyw obrazu */ 
void negatyw(obraz_struct *obraz){
 
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;

  if((obraz->rgbw).bw==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tablica[i][j] = (obraz->szarosci - tablica[i][j]);
      }
    }
  }

  if((obraz->rgbw).r==1){  
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	red[i][j] = (obraz->szarosci - red[i][j]);
      }
    }
  }

  if((obraz->rgbw).g==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	green[i][j] = (obraz->szarosci - green[i][j]);
      }
    }
  }
     
  if((obraz->rgbw).b==1){
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	blue[i][j] = (obraz->szarosci - blue[i][j]);
      }
    }
  }

}/* koniec negatyw */








/****************************/
/*                          */
/*      KONTUROWANIE        */
/*                          */
/****************************/

/* Funkcja uwydatnia kontury */
void konturowanie(obraz_struct *obraz){

  int tmp_tab[obraz->wymy][obraz->wymx];
  int i,j;
  
  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;
 

  if((obraz->rgbw).bw==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = tablica[i][j];
      }
    }   

    for(i=1;i<(obraz->wymy-1);i++){
      for(j=1;(j<obraz->wymx-1);j++){
	tablica[i][j] = (abs(tmp_tab[i+1][j]-tmp_tab[i][j])+abs(tmp_tab[i][j+1]-tmp_tab[i][j]));
      }
    }
  }

  if((obraz->rgbw).r==1){  
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = red[i][j];
      }
    }   

    for(i=1;i<(obraz->wymy-1);i++){
      for(j=1;(j<obraz->wymx-1);j++){
	red[i][j] = (abs(tmp_tab[i+1][j]-tmp_tab[i][j])+abs(tmp_tab[i][j+1]-tmp_tab[i][j]));
      }
    }
  }


  if((obraz->rgbw).g==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = green[i][j];
      }
    }   

    for(i=1;i<(obraz->wymy-1);i++){
      for(j=1;(j<obraz->wymx-1);j++){
	green[i][j] = (abs(tmp_tab[i+1][j]-tmp_tab[i][j])+abs(tmp_tab[i][j+1]-tmp_tab[i][j]));
      }
    }
  }

  if((obraz->rgbw).b==1){
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = blue[i][j];
      }
    }   

    for(i=1;i<(obraz->wymy-1);i++){
      for(j=1;(j<obraz->wymx-1);j++){
	blue[i][j] = (abs(tmp_tab[i+1][j]-tmp_tab[i][j])+abs(tmp_tab[i][j+1]-tmp_tab[i][j]));
      }
    }
  }
}/* koniec konturowanie */







/****************************/
/*                          */
/*    ZMIANA POZIOMOW       */
/*                          */
/****************************/
    
/* Funkcja zmiany poziomow - nalezy podac wartosc w procentach */
void zmiana_poziomow(obraz_struct *obraz,int czern,int biel){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  if(((0<=biel)&&(biel<=100)&&(0<=czern)&&(czern<=100))==0){
    fprintf(stderr,"Niepoprawna wartosc parametru biel lub czern\n");
  }
  else{
    tablica=(int(*)[obraz->wymx]) obraz->tablica;
    red=(int(*)[obraz->wymx]) obraz->red;
    green=(int(*)[obraz->wymx]) obraz->green;
    blue=(int(*)[obraz->wymx]) obraz->blue;
    
    biel=(obraz->szarosci*biel)/100; 
    czern=(obraz->szarosci*czern)/100;
    
    if((obraz->rgbw).bw==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(tablica[i][j] <= czern) tablica[i][j] = 0;
	  else if(tablica[i][j] < biel) tablica[i][j] = (((tablica[i][j]-czern)*(obraz->szarosci))/(biel-czern));
	  else tablica[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).r==1){  
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(red[i][j] <= czern) red[i][j] = 0;
	  else if(red[i][j] < biel) red[i][j] = (((red[i][j]-czern)*(obraz->szarosci))/(biel-czern));
	  else red[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).g==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(green[i][j] <= czern) green[i][j] = 0;
	  else if(green[i][j] < biel) green[i][j] = (((green[i][j]-czern)*(obraz->szarosci))/(biel-czern));
	  else green[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).b==1){
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(blue[i][j] <= czern) blue[i][j] = 0;
	  else if(blue[i][j] < biel) blue[i][j] = (((blue[i][j]-czern)*(obraz->szarosci))/(biel-czern));
	  else blue[i][j] = obraz->szarosci;
	}
      }
    }
  }
}/* koniec zmiana poziomow */
  

  





/****************************/
/*                          */
/*  ROZCIAGANIE HISTOGRAMU  */
/*                          */
/****************************/

/* Rozciąganie histogramu */
void rozciaganie_histogramu(obraz_struct *obraz){
  int i,j; 
  int max, min;
   
  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;

  max=0;
  min=obraz->szarosci;
   
  if((obraz->rgbw).bw==1){ 
/* Szukanie najmniejszej i największej wartosci */
    max=0;
    min=obraz->szarosci;
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	if(tablica[i][j]>max) max=tablica[i][j];
	if(tablica[i][j]<min) min=tablica[i][j];
      }
    }
    
    /* Rozciąganie histogramu */
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tablica[i][j]=(((tablica[i][j]-min)*obraz->szarosci)/(max-min));
      }
    }
  }
  
  if((obraz->rgbw).r==1){  
    /* Szukanie najmniejszej i największej wartosci */
    max=0;
    min=obraz->szarosci;
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	if(red[i][j]>max) max=red[i][j];
	if(red[i][j]<min) min=red[i][j];
      }
    }
    
    /* Rozciąganie histogramu */
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	red[i][j]=(((red[i][j]-min)*obraz->szarosci)/(max-min));
      }
    }
  }
  
  if((obraz->rgbw).g==1){ 
    /* Szukanie najmniejszej i największej wartosci */
    max=0;
    min=obraz->szarosci;
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	if(green[i][j]>max) max=green[i][j];
	if(green[i][j]<min) min=green[i][j];
      }
    }
    
    /* Rozciąganie histogramu */
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	green[i][j]=(((green[i][j]-min)*obraz->szarosci)/(max-min));
      }
    }
  }    
  
  
  if((obraz->rgbw).b==1){
    /* Szukanie najmniejszej i największej wartosci */
    max=0;
    min=obraz->szarosci;
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	if(blue[i][j]>max) max=blue[i][j];
	if(blue[i][j]<min) min=blue[i][j];
      }
    }
    
    /* Rozciąganie histogramu */
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	blue[i][j]=(((blue[i][j]-min)*obraz->szarosci)/(max-min));
      }
    }
  }
}/* koniec rozciaganie histogramu */







/****************************/
/*                          */
/*       PROGOWANIE         */
/*                          */
/****************************/
/* Progowanie */
void progowanie(obraz_struct *obraz,int prog){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];

  if(((0<=prog)&&(prog<=100))==0){
    fprintf(stderr,"Niepoprawna wartosc parametru prog - progowanie\n");
  }
  else{ 
    tablica=(int(*)[obraz->wymx]) obraz->tablica;
    red=(int(*)[obraz->wymx]) obraz->red;
    green=(int(*)[obraz->wymx]) obraz->green;
    blue=(int(*)[obraz->wymx]) obraz->blue;
    
    prog=(obraz->szarosci*prog)/100; 
  
    
    if((obraz->rgbw).bw==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(tablica[i][j] <= prog) tablica[i][j] = 0;
	  else tablica[i][j] = obraz->szarosci;
	}
      }
    }

    if((obraz->rgbw).r==1){  
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(red[i][j] <= prog) red[i][j] = 0;
	  else red[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).g==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(green[i][j] <= prog) green[i][j] = 0;
	  else green[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).b==1){
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(blue[i][j] <= prog) blue[i][j] = 0;
	  else blue[i][j] = obraz->szarosci;
	}
      }
    }
  }
}
/* koniec progowanie */









/****************************/
/*                          */
/*    PROGOWANIE CZERNI     */
/*                          */
/****************************/

/* Polprogowanie czerni */
void progowanie_czerni(obraz_struct *obraz,int prog){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  if(((0<=prog)&&(prog<=100))==0){
    fprintf(stderr,"Niepoprawna wartosc parametru prog - polprogowanie czerni\n");
  }
  else{ 
    tablica=(int(*)[obraz->wymx]) obraz->tablica;
    red=(int(*)[obraz->wymx]) obraz->red;
    green=(int(*)[obraz->wymx]) obraz->green;
    blue=(int(*)[obraz->wymx]) obraz->blue;
    
    prog=((obraz->szarosci)*prog)/100;
    
    
  
    if((obraz->rgbw).bw==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(tablica[i][j] <= prog) tablica[i][j] = 0;
	}
      }
    }
    
    
    if((obraz->rgbw).r==1){  
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(red[i][j] <= prog) red[i][j] = 0;
	}
      }
    }
    
    if((obraz->rgbw).g==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(green[i][j] <= prog) green[i][j] = 0;
	}
      }
    }
    
    if((obraz->rgbw).b==1){
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(blue[i][j] <= prog) blue[i][j] = 0;
	}
      }
    }
  }
}
/* koniec progowanie czerni */










/****************************/
/*                          */
/*    PROGOWANIE BIELI      */
/*                          */
/****************************/

/* Polprogowanie bieli */
void progowanie_bieli(obraz_struct *obraz,int prog){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  if(((0<=prog)&&(prog<=100))==0){
    fprintf(stderr,"Niepoprawna wartosc parametru prog - polprogowanie bieli\n");
  }
  else{ 
    tablica=(int(*)[obraz->wymx]) obraz->tablica;
    red=(int(*)[obraz->wymx]) obraz->red;
    green=(int(*)[obraz->wymx]) obraz->green;
    blue=(int(*)[obraz->wymx]) obraz->blue;
    
    prog=(obraz->szarosci*prog)/100;
    
    if((obraz->rgbw).bw==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(tablica[i][j] > prog) tablica[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).r==1){  
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(red[i][j] > prog) red[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).g==1){ 
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(green[i][j] > prog) green[i][j] = obraz->szarosci;
	}
      }
    }
    
    if((obraz->rgbw).b==1){
      for(i=0;i<obraz->wymy;i++){
	for(j=0;j<obraz->wymx;j++){
	  if(blue[i][j] > prog) blue[i][j] = obraz->szarosci;
	}
      }
    }
  }    
}
/* koniec progowanie bieli */








/****************************/
/*                          */
/*   ROZMYWANIE POZIOME     */
/*                          */
/****************************/

/* Rozmywanie poziome */
void rozmywanie_poziome(obraz_struct *obraz){
  int i,j;
    
  int tmp_tab[obraz->wymy][obraz->wymx];

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;


  if((obraz->rgbw).bw==1){ 
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

  if((obraz->rgbw).r==1){  
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = red[i][j];
      }
    } 
    
    for(i=0;i<obraz->wymy;i++){
      for(j=1;j<(obraz->wymx-1);j++){
        red[i][j] =(tmp_tab[i][j-1]+tmp_tab[i][j]+tmp_tab[i][j+1])/3;
      }
    } 
  }

  if((obraz->rgbw).g==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = green[i][j];
      }
    } 
    
    for(i=0;i<obraz->wymy;i++){
      for(j=1;j<(obraz->wymx-1);j++){
        green[i][j] =(tmp_tab[i][j-1]+tmp_tab[i][j]+tmp_tab[i][j+1])/3;
      }
    } 
  }
     
  if((obraz->rgbw).b==1){
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = blue[i][j];
      }
    } 
    
    for(i=0;i<obraz->wymy;i++){
      for(j=1;j<(obraz->wymx-1);j++){
        blue[i][j] =(tmp_tab[i][j-1]+tmp_tab[i][j]+tmp_tab[i][j+1])/3;
      }
    } 
  }
}
/* koniec rozmywanie poziome */









/****************************/
/*                          */
/*   ROZMYWANIE PIONOWE     */
/*                          */
/****************************/

/* Rozmywanie pionowe */
void rozmywanie_pionowe(obraz_struct *obraz){
  int i,j;
    
  int tmp_tab[obraz->wymy][obraz->wymx];

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx];
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];
 
  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;

  if((obraz->rgbw).bw==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = tablica[i][j];
      }
    } 
    
    for(i=1;i<(obraz->wymy-1);i++){
      for(j=0;j<obraz->wymx;j++){
	tablica[i][j]=(tmp_tab[i-1][j]+tmp_tab[i][j]+tmp_tab[i+1][j])/3;
      }
    } 
  }

  if((obraz->rgbw).r==1){  
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = red[i][j];
      }
    } 
    
    for(i=1;j<(obraz->wymy-1);i++){
      for(j=0;j<obraz->wymx;j++){
        red[i][j]=(tmp_tab[i-1][j]+tmp_tab[i][j]+tmp_tab[i+1][j])/3;
      }
    } 
  }

  if((obraz->rgbw).g==1){ 
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = green[i][j];
      }
    } 
    
    for(i=1;j<(obraz->wymy-1);i++){
      for(j=0;j<obraz->wymx;j++){
        green[i][j]=(tmp_tab[i-1][j]+tmp_tab[i][j]+tmp_tab[i+1][j])/3;
      }
    } 
  }

  if((obraz->rgbw).b==1){
    for(i=0;i<obraz->wymy;i++){
      for(j=0;j<obraz->wymx;j++){
	tmp_tab[i][j] = blue[i][j];
      }
    } 
    
    for(i=1;j<(obraz->wymy-1);i++){
      for(j=0;j<obraz->wymx;j++){
        blue[i][j] =(tmp_tab[i-1][j]+tmp_tab[i][j]+tmp_tab[i+1][j])/3;
      }
    } 
  }
}
/* koniec rozmywanie pionowe */

	
