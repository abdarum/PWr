
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 512            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */



int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;

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
  if (fscanf(plik_we,"%d %d %d",wymx,wymy,szarosci)!=3) {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<*wymy;i++) {
    for (j=0;j<*wymx;j++) {
      if (fscanf(plik_we,"%d",&(obraz_pgm[i][j]))!=1) {
	fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
	return(0);
      }
    }
  }
  return *wymx**wymy;   /* Czytanie zakonczone sukcesem    */
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


int negatyw(int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
{
  int i,j;
  for (i=0; i<wymy; i++){
     for (j=0; j<wymx; j++){
       obraz_pgm[i][j]=(szarosci-(obraz_pgm[i][j])); 
	  }
	  }
	  return 0;
}


int progowanie(int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
{
  int i,j,prog;
  printf ("Podaj wartosc szarosci wieksza od zera\n", szarosci);
  scanf ("%d", &prog);  
  for (i=0; i<wymy; i++){
    for (j=0; j<wymx; j++){
      if (obraz_pgm[i][j]<=prog)
	obraz_pgm[i][j] = 0;
      else
	obraz_pgm[i][j] = szarosci;
    }
  }
  return 0;
}


int konturowanie(int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
{
  int i,j;
  for (i=0; i<wymy; i++){
    for (j=0; j<wymx; j++){
      obraz_pgm[i][j]=abs(obraz_pgm[i+1][j]-(obraz_pgm[i][j]))+abs(obraz_pgm[i][j+1]-(obraz_pgm[i][j]));
	}
  }
  return 0;
}


int rozmywanie_poziome(int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
{
  int i,j;
  for (i=0; i<wymy; i++){
    for (j=0; j<wymx; j++){
      obraz_pgm[i][j]=((obraz_pgm[i-1][j]+(obraz_pgm[i][j])+(obraz_pgm[i+1][j]))/3);
	}
  }
  return 0;
}


int zapis(FILE *plik_wy, int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
{
  int i,j;
  fprintf (plik_wy, "P2\n");
  fprintf (plik_wy,"%d %d \n",wymx,wymy);
  fprintf (plik_wy,"%d \n",szarosci);
  for (i=0; i<wymy; i++){
    for (j=0; j<wymx; j++){
      fprintf (plik_wy,"%d ",(obraz_pgm[i][j]));
    }
    fprintf (plik_wy,"\n");
  }
  return 0;
}

      
int main()
 {
  int obraz[MAX][MAX] ;
  int wymx,wymy,odcieni;
  int opcja = 0;
  int odczytano = 0;
  FILE *plik;
  char nazwa[100];

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  plik=fopen(nazwa,"r");

  if (plik != NULL) {       /* co spowoduje zakomentowanie tego warunku */
    odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
    fclose(plik);
  }

  /* Wyswietlenie poprawnie wczytanego obraza zewnetrznym programem */
  /*  if (odczytano != 0){
    wyswietl(nazwa);

  return odczytano;
  }*/

while (opcja != 6){
    printf ("Menu programu przetwarzania obrazow PGM\n");
    printf ("\t 1.Konturowanie \n");
    printf ("\t 2.Progowanie \n");
    printf ("\t 3.Negatyw \n");
    printf ("\t 4.Rozmywanie poziome \n"); 
    printf ("\t 5.Zapisz plik jako \n");
    printf ("\t 6.Zamknij program \n");
    scanf("%d", &opcja);

    switch (opcja)
      {


      case 1:
	{
	  printf ("Wykonywanie konturowania\n");
	  konturowanie (wymx, wymy, odcieni, obraz);
	  printf ("Dokonano konturowania\n");
	  break;
	}  

      case 2:
	{
	  printf ("Wykonywanie progowania\n");
	  progowanie (wymx, wymy, odcieni, obraz);
	  printf ("Dokonano progowania\n");
	  break;
	}

      case 3:
	{
	  printf ("Wykonywanie negatywu\n");
	  negatyw (wymx, wymy, odcieni, obraz);
	  printf ("Dokonano negatywu\n");
	  break;
	}
	
      case 4:
	{
	  printf ("Wykonywanie rozmywania poziomego\n");
	  rozmywanie_poziome (wymx, wymy, odcieni, obraz);
	  printf ("Dokonano rozmycia poziomego\n");
	  break;
	}
	
      case 5:
	{
	  printf ("Podaj nazwe pliku do zapisu\n");
	  scanf ("%s", &nazwa);
	  plik=fopen(nazwa, "w");
	  zapis (plik, wymx, wymy, odcieni, obraz);
	  printf ("Plik zostal zapisany o nazwie: %s\n", nazwa);
	  break;
	}
	
      case 6:
	{
	  printf ("Program zakonczyl prace\n");
	  break;
	}
      }
 }

return 0;

}


	
