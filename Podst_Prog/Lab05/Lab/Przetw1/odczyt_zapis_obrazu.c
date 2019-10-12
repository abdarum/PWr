#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "odczyt_zapis_obrazu.h"

void allokuj_tablice(int ***tablica,int x,int y){
  int i;  
  int **tablica=(int**)malloc(y*sizeof(int*));
  for(i=0;i<y;i++){
    tablica[i]=(int*)malloc(x*sizeof(int));
  }			    
}

void zwolnij_tablice(int ***tablica,int x,int y){
  int i;
  for(int i=0;i<y;i++){
    free(tablica[i]);
  }
  free(tablica);
}

int czytaj(FILE *plik_we,obraz_struct *obraz) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;
  int *ptr=NULL;           /* wskaznik pomocniczy uzywany do obslugi zapisu */
                           /* obrazu do tablicy                             */

  /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien być P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
    fprintf(stderr,"Blad: To nie jest plik PGM\n");
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
  allokuj_tablice(&(obraz->tablica),*(obraz->wym_x),*(obraz->wym_y));

  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<*(obraz->wymy);i++) {
    *ptr=(obraz->tablica[i]);
    for (j=0;j<*(obraz->wymx);j++) {
      if (fscanf(plik_we,"%d",(*ptr)!=1)){
	fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
	return(0);
      }
      ptr++;
    }
  }
  return *(obraz->wymx)**(obraz->wymy);   /* Czytanie zakonczone sukcesem    */
}                       /* Zwroc liczbe wczytanych pikseli */


/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}

int zapisz(FILE *plik_wy,obraz_struct *obraz)
{
  int i,j;
  int *ptr;                /* wskaznik pomocniczy uzywany do obslugi zapisu */
                           /* obrazu do tablicy                             */
 
  fprintf (plik_wy, "P2\n");
  fprintf (plik_wy,"%d %d \n",*(obraz->wymx),*(obraz->wymy));
  fprintf (plik_wy,"%d \n",*(obraz->szarosci));
  for (i=0;i<*(obraz->wymy);i++) {
    *ptr=(obraz->tablica[i]);
    for (j=0;j<*(obraz->wymx);j++) {
      fprintf (plik_wy,"%d ",*ptr);
      ptr++;
    }
    fprintf (plik_wy,"\n");
  }
 return 0;
}
