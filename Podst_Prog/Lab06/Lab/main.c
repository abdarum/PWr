/*

Program: kalkulator RPN ver. 1.1
Program spelnia funkcje kalkulatora 4 dzialaniowego "+", "-", "*", "/"
Praca Kornela Stefańczyka nr 235420

Sprawozdanie znajduje sie na koncu pliku po programie.

*/
#include "funkcje_stosu.h"

int main(){
  
  char wczytano[DL_LINI];
  t_elem *stos;
  int liczba;
  int i,wyswietlono_blad;
  int tmp,tmp_1,tmp_2;
  const char cyfry[] = "1234567890";
  stos=(t_elem*)malloc(sizeof(t_elem));
  inicjuj(&stos);
  
  /************************************************/
  /*                   OPCJE                      */
  /* zapobiega spacjom na poczatku                */
  /* # kasuje ostatni element na stosie           */
  /* $ zamiana miejsc ostatnich 2 elementow stosu */
  /* & zduplikowanie elementu na szczycie stosu   */
  /* ? wydrukowanie zawartosci calego stosu       */
  /* q zakonczenie pracy programu                 */
  /************************************************/
  
  printf("Podaj dzialania w RPN\n");
  while(wczytano[i]!='q'){
    
    scanf("%s",wczytano);
    i=0;
    wyswietlono_blad=0;    
    if (sscanf(wczytano,"%d",&liczba)==1) {
      push(&stos,liczba);
      if(wczytano[0]=='-'){
	i = strspn(wczytano+1, cyfry);
	i++;
      }
      else
	i = strspn(wczytano, cyfry);
      
    }
    
    while(wczytano[i]!='\0'){
      
      switch(wczytano[i]){
	
      case '+':
	if(empty(stos)==0||empty(stos->nast)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}
	
	pop(&stos,&tmp_2);
	pop(&stos,&tmp_1);
	tmp=tmp_1+tmp_2;
	push(&stos,tmp);
	break;
	
      case '-':
	if(empty(stos)==0||empty(stos->nast)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}

	pop(&stos,&tmp_2);
	pop(&stos,&tmp_1);
	tmp=tmp_1-tmp_2;
	push(&stos,tmp);
	break;
	
      case '*':
	if(empty(stos)==0||empty(stos->nast)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}

	pop(&stos,&tmp_2);
	pop(&stos,&tmp_1);
	tmp=tmp_1*tmp_2;
	push(&stos,tmp);
	break;
	
      case '/':
	if(empty(stos)==0||empty(stos->nast)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}

	pop(&stos,&tmp_2);
	pop(&stos,&tmp_1);
	tmp=tmp_1/tmp_2;
	push(&stos,tmp);
	break;
	
      case '#':
	if(empty(stos)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}

	pop(&stos,&tmp);
	break;
	
      case '$':
	if(empty(stos)==0||empty(stos->nast)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}
	pop(&stos,&tmp_2);
	pop(&stos,&tmp_1);
	push(&stos,tmp_2);
	push(&stos,tmp_1);
	break;
	
      case '&':
	if(empty(stos)==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");
	  fprintf(stderr,"Niewystarczajaca ilosc elementow, aby wykonac operacje\n");
	  break;
	}

	tmp=stos->wart;
	push(&stos,tmp);
	break;
	
      case '?':
	if(wyswietlono_blad==1)    
	  printf("\n");
	print(stos);
	break;
	
      case 'q':
	exit(0);
	break;
	
      default:
	if(wyswietlono_blad==0){
	  if(wyswietlono_blad==1)    
	    printf("\n");    
	  fprintf(stderr,"Niepoprawnie wybrane opcje:\n");
	  wyswietlono_blad=1;    
	}

	fprintf(stderr,"%c",wczytano[i]);

      }	
      i++;
      tmp=tmp_1=tmp_2=0;

    }
    if(wyswietlono_blad==1)    
      fprintf(stderr,"\n");
    }
  
  free(stos);
  return 0;
}

/*****                       SPRAWOZDANIE                       *****/
/*

  Program podobnie jak poprzednie byl realozowany w czesciach co bylo
    pomocne w jego testowaniu.

    - pierwszym etapem pracy nad nim byloskonstruowanie struktury i
  napisanie funkcji obslugujacych dzialanie stosu. Sprawdzilem 
  ze funkcje dzialaja i za ich pomoca mozna stworzyc dzialajacy stos.
  
    - kolejnym etapem pisania programu bylo zrobienie elementow
  czytajacych liczby i znaki z stdin oraz przetwarzania ich na 
  potrzeby programu. Funkcja "sscanf(wczytano,"%d",&liczba)==1)" 
  posluzula do odczytu liczb(dziala to rowniez dla liczb ujemnych).
  
  Fragment "i = strspn(wczytano, cyfry);" pozwala nie pomijac tego 
  co zostanie "przyklejone" do cyfr. W zwiazku z tym mozna uzyc
  konstrukcji typu 12 15-? lub innych tego typu.
 
  Zastrzerzenia:
    * jezeli podamy po znaku specjalnym liczbe(bez spacji) to 
    zostanie ona uznana jako niepoprawna opcja.

    * wszelkie znaki, ktore nie sa zawarte w switch case zostaja
    uznane jako niepoprawne opcje i wyswietlone w bledzie. Jezeli
    po niezidentyfikowanych znakach wystapia jakies liczby program
    je zignoruje(wyswietli z niepoprawnymi opcjami)

    * jezeli nie ma wystarczajacej liczby elementow na stosie 
    program zwroci na to uwage w postaci bledu.

    

    - ostatnim etapem pracy nad programem bylo dodanie funkcji 
  kalkulatora - najpierw sprawdzenie czy jest odpowiednia liczba
  elementow na stosie, a pozniej pobranie elementow ze stosu i 
  operacja na nich w odpowiedniej kolejnosci.


  Program byl oczywiscie na wszystkich etapach testowany, kompilowany
  i sprawdzany czy dziala poprawnie, o czym nie wspominalem, aby
  nie zaciemniac sprawozdania. Wiekszosc testow byla wykonana w czesci
  dotyczacej interfejsu uzytkownika aby wygladalo to wedlug mojego
  zamyslu(aby przy liczbach moglu byc "przyklejone" funkcje bez 
  spacji).

  Funkcje dotyczace stosu znajduja sie w plikach "funkcje_stosu.*", 
  a funkcje kalkulatora sa realizowane w switch. 

  !!! UWAGA !!!
  Jezeli Pan sprawdzal przed 27.01 to byl blad w ktorym nie dzialaly
  liczby z minusem. Wersja jest poprawiona.

*/

