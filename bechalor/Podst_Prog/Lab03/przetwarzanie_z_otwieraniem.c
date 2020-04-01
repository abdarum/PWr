/*

Program: przetwarzanie_obrazow.c ver. 1.2
Program przetwarza obrazy w formacie pgm
Praca Kornela Stefańczyka nr 235420

Sprawozdanie znajduje sie na koncu pliku po programie.

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SKALA_SZAROSCI  256  /* Maksymalna skala szarosci */
#define MAX 512          /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024     /* Dlugosc buforow pomocniczych */
#define END 0 /* Symbol ktory jest wywolywany jako koniec programu */

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										    *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			    *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz		    *
 * \param[out] wymx szerokosc obrazka						    *
 * \param[out] wymy wysokosc obrazka						    *
 * \param[out] szarosci liczba odcieni szarosci					    *
 * \return liczba wczytanych pikseli						    *
 ************************************************************************************/

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

int zapisz(FILE *plik_wy, int wymx, int wymy, int szarosci, int obraz_pgm[][MAX])
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

/* Funkcja kopiuje jedna tablice do innej - przydatna przy wyswietlaniu obrazow */    
void kopiuj(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]){

  int i,j;

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
       obraz_wyj[i][j] = obraz_wej[i][j];
    }
  }
}



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

Program byl testowany podczas pisania.

Na poczatku dodana zostala funkcja ktora zapisuje pliki w rozszerzeniu pgm. Jej testy polegaly na kopiowaniu tablicy obraz do tablicy tmp i zapisywaniu pliku. Pozniej porownywalem z plikiem oryginalnym i kiedy dzialalo to poprawnie zajalem sie pisaniem funkcji ktore byly odpowiedzialne za zmiany w tablicach obrazu.

Gdy funkcje przetwarzania obrazu byly przetestowane i dzialajace zajalem sie tworzeniem menu. Zaczalem od napisania wlasciwej czesci menu. Gdy ona dzialala zaczalem pisac obsluge bledow otwierania pliku.

Ostateczny test polegal na przetestowaniu czy wszystkie opcje dzialaja poprawnie.

*/
