#include "odczyt_zapis_obrazu.h"

int czytaj(FILE *plik_we,obraz_struct *obraz){
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;
  wyzeruj_obraz(obraz);

  /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien być P3 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ((buf[0]!='P') || (buf[1]!='3') || koniec) {  /* Czy jest magiczne "P3"? */
    fprintf(stderr,"Blad: To nie jest plik PPM\n");
    return(0);
  }

  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
	koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (znak=='#' && !koniec);   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
  if (fscanf(plik_we,"%d %d %d",&(obraz->wymx),&(obraz->wymy),&(obraz->szarosci))!=3) {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }

  /* alokowanie panieci */
  obraz->red=malloc(obraz->wymx*obraz->wymy*sizeof(int));
  int (*red)[obraz->wymx];
  red=(int(*)[obraz->wymx]) obraz->red;
  obraz->green=malloc(obraz->wymx*obraz->wymy*sizeof(int));
  int (*green)[obraz->wymx];
  green=(int(*)[obraz->wymx]) obraz->green;
  obraz->blue=malloc(obraz->wymx*obraz->wymy*sizeof(int));
  int (*blue)[obraz->wymx];
  blue=(int(*)[obraz->wymx]) obraz->blue;

  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm */
  for (i=0;i<obraz->wymy;i++) {
    for (j=0;j<obraz->wymx;j++) {
      if ((fscanf(plik_we,"%d %d %d",&red[i][j],&green[i][j],&blue[i][j]))!=3){
	fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
	return(0);
      } 
    }
  }
  /*  printf("koniec odczyt\n"); */
  /*
  (obraz->rgbw).r=1;
  (obraz->rgbw).g=1;
  (obraz->rgbw).b=1;
  (obraz->rgbw).bw=0;
  */
  return obraz->wymx*obraz->wymy;   /* Czytanie zakonczone sukcesem    */
}                       /* Zwroc liczbe wczytanych pikseli */



int zapisz(FILE *plik_wy,obraz_struct *obraz){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx]; 
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];

  if((obraz->rgbw).bw==1) 
    tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;
    
  if((obraz->rgbw).r || (obraz->rgbw).g || (obraz->rgbw).b){
    fprintf (plik_wy, "P3\n");
  }

  if((obraz->rgbw).bw==1){ 
    fprintf (plik_wy, "P2\n");
  }
  
   
  fprintf (plik_wy,"%d %d \n",obraz->wymx,obraz->wymy);
  fprintf (plik_wy,"%d \n",obraz->szarosci);

  if((obraz->rgbw).bw==1){
    for (i=0;i<obraz->wymy;i++) {
      for (j=0;j<obraz->wymx;j++) {
	fprintf(plik_wy,"%d ",tablica[i][j]); 
      }
      fprintf (plik_wy,"\n");
    }
  }

  if((obraz->rgbw).r || (obraz->rgbw).g|| (obraz->rgbw).b){ 
    for (i=0;i<obraz->wymy;i++) {
      for (j=0;j<obraz->wymx;j++) {
	fprintf(plik_wy,"%d %d %d ",red[i][j],green[i][j],blue[i][j]);       }
      fprintf (plik_wy,"\n");
    }
  }
  return 0;
}


/* Konwersja do szarosci */
void zrob_czarno_bialy(obraz_struct *obraz){
  int i,j;

  int (*tablica)[obraz->wymx];
  int (*red)[obraz->wymx]; 
  int (*green)[obraz->wymx];
  int (*blue)[obraz->wymx];


/* Alokowanie tablicy, ktora bedzie obrazem czarnobialym */
  obraz->tablica=malloc(obraz->wymx*obraz->wymy*sizeof(int));

  tablica=(int(*)[obraz->wymx]) obraz->tablica;
  red=(int(*)[obraz->wymx]) obraz->red;
  green=(int(*)[obraz->wymx]) obraz->green;
  blue=(int(*)[obraz->wymx]) obraz->blue;
  
  for(i=0;i<obraz->wymy;i++){
    for(j=0;j<obraz->wymx;j++){
      tablica[i][j] = (red[i][j]+green[i][j]+blue[i][j])/3;
    }
  }
}

/* Zeruj strukture */
void wyzeruj_obraz(obraz_struct *obraz){
  obraz->red=NULL;
  obraz->green=NULL;
  obraz->blue=NULL;
  obraz->tablica=NULL;

  obraz->wymx=0;
  obraz->wymy=0;
  obraz->szarosci=0;
  
}


void zwolnij_obraz(obraz_struct *obraz){
  free(obraz->red);
  free(obraz->green);
  free(obraz->blue);

  if((obraz->rgbw).bw==1)
    free(obraz->tablica);
}

/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}

