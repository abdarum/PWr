#include "opcje.h"

void wyzeruj_opcje(w_opcje * wybor) {
 
  wybor->plik_we=NULL;
  wybor->plik_wy=NULL;

  wybor->negatyw=0;
  wybor->progowanie=0;
  wybor->progowanie_czerni=0;
  wybor->progowanie_bieli=0;
  wybor->zmiana_poziomow=0;
  wybor->konturowanie=0;
  wybor->rozmywanie_poziome=0;
  wybor->rozmywanie_pionowe=0;
  wybor->rozciaganie_histogramu=0;
 
  wybor->w_prog=0;
  wybor->c_prog=0;
  wybor->b_prog=0;
  wybor->poz_bieli=0;
  wybor->poz_czerni=0;
  wybor->wyswietlenie=0;
  wybor->zapisz=0;


  (wybor->rgbw).r=1;
  (wybor->rgbw).g=1;
  (wybor->rgbw).b=1;
  (wybor->rgbw).bw=0;


  strcpy(wybor->nazwa_pliku,""); 
}


int przetwarzaj_opcje(int argc, char **argv, w_opcje *wybor) {
  int i, prog,kontrol_1=0,kontrol_2=0;
  char *nazwa_pliku_we, *nazwa_pliku_wy;

  wyzeruj_opcje(wybor);
  wybor->plik_wy=stdout;        /* na wypadek gdy nie podano opcji "-o" */

  for (i=1; i<argc; i++) {
    if (argv[i][0] != '-')  /* blad: to nie jest opcja - brak znaku "-" */
      return B_NIEPOPRAWNAOPCJA; 
    switch (argv[i][1]) {
    case 'i': {                 /* opcja z nazwa pliku wejsciowego */
      if (++i<argc) {   /* wczytujemy kolejny argument jako nazwe pliku */
	nazwa_pliku_we=argv[i];
	if (strcmp(nazwa_pliku_we,"-")==0) /* gdy nazwa jest "-"        */
	  wybor->plik_we=stdin;            /* ustwiamy wejscie na stdin */
	else                               /* otwieramy wskazany plik   */
	  wybor->plik_we=fopen(nazwa_pliku_we,"r");
      } else 
	return B_BRAKNAZWY;                   /* blad: brak nazwy pliku */
      break;
    }
    case 'o': {                 /* opcja z nazwa pliku wyjsciowego */
      if (++i<argc) {   /* wczytujemy kolejny argument jako nazwe pliku */
	nazwa_pliku_wy=argv[i];
	if (strcmp(nazwa_pliku_wy,"-")==0)/* gdy nazwa jest "-"         */
	  wybor->plik_wy=stdout;          /* ustwiamy wyjscie na stdout */

	else{                              /* otwieramy wskazany plik    */
	  strcpy(wybor->nazwa_pliku,nazwa_pliku_wy); 
	  wybor->plik_wy=fopen(nazwa_pliku_wy,"w");
	  wybor->zapisz=1;
	}
      } else 
	return B_BRAKNAZWY;                   /* blad: brak nazwy pliku */
      break;
    }


    case 'm':{
      /* dla wyboru koloru */
      if (++i<argc) {   /* wczytujemy kolejny argument - kolory */
	(wybor->rgbw).bw=0;
	(wybor->rgbw).r=0;
	(wybor->rgbw).g=0;
	(wybor->rgbw).b=0;

	if(argv[i][0]=='s'){
	  (wybor->rgbw).bw=1;
	}
	
	if(argv[i][0]=='r'||argv[i][1]=='r'||argv[i][2]=='r'){
	  (wybor->rgbw).r=1;
	}
	if(argv[i][0]=='g'||argv[i][1]=='g'||argv[i][2]=='g'){
	  (wybor->rgbw).g=1;
	}
	if(argv[i][0]=='b'||argv[i][1]=='b'||argv[i][2]=='b'){
	  (wybor->rgbw).b=1;
	}

	if(argv[i][1]=='s'||argv[i][2]=='s')
	  return B_BRAKWARTOSCI;     /* blad: niepoprawnie wybrane kolory */	  
	
	if((wybor->rgbw).bw&&((wybor->rgbw).r||(wybor->rgbw).g||(wybor->rgbw).b))
	  return B_BRAKWARTOSCI;     /* blad: niepoprawnie wybrane kolory */

	if(((wybor->rgbw).bw||(wybor->rgbw).r||(wybor->rgbw).g||(wybor->rgbw).b)!=1)
	  return B_BRAKWARTOSCI;     /* blad: niepoprawnie wybrane kolory */
	break;
      }
    }

    case 'p': {

      /* dla progowania czerni */
      if(argv[i][2]=='c'){      
	if (++i<argc) { /* wczytujemy kolejny argument jako wartosc progu */
	  if (sscanf(argv[i],"%d",&prog)==1) {
	    wybor->progowanie_czerni=1;
	    wybor->c_prog=prog;
	  } else
	    return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
	}
	break;
      }
      
      /* dla progowania bieli */
      if(argv[i][2]=='b'){
	if (++i<argc) { /* wczytujemy kolejny argument jako wartosc progu */
	  if (sscanf(argv[i],"%d",&prog)==1) {
	    wybor->progowanie_bieli=1;
	    wybor->b_prog=prog;
	  } else
	    return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
	}
	break;
      }
      /* dla progowania */ 
      if (++i<argc) { /* wczytujemy kolejny argument jako wartosc progu */
	if (sscanf(argv[i],"%d",&prog)==1) {
	  wybor->progowanie=1;
	  wybor->w_prog=prog;
	} else
	  return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
      } else 
	return B_BRAKWARTOSCI;             /* blad: brak wartosci progu */
      
      break;
    }
 

    case 'n': {                 /* mamy wykonac negatyw */
      wybor->negatyw=1;
      break;
    }

    case 'k': {                 /* mamy wykonac konturowanie */
      wybor->konturowanie=1;
      break;
    }

    case 'z': {
      if (++i<argc) { /* wczytujemy kolejny argument jako wartosc progu */
	if (sscanf(argv[i],"%d",&prog)==1) {
	 kontrol_1=1;
	  wybor->poz_czerni=prog;
	} else
	  return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
      }
      if (++i<argc) { /* wczytujemy kolejny argument jako wartosc progu */
	if (sscanf(argv[i],"%d",&prog)==1) {
	  kontrol_2=1;
	  wybor->poz_bieli=prog;
	} else
	  return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
	if(kontrol_1&kontrol_2){
	  wybor->zmiana_poziomow=1;
	}
	
	  
      } else 
	return B_BRAKWARTOSCI;             /* blad: brak wartosci progu */
      break;
    }
  

    case 'r': {
      if(argv[i][2]=='x'){      
	wybor->rozmywanie_poziome=1;     
	break;    
      }
      if(argv[i][2]=='y'){      
	wybor->rozmywanie_pionowe=1;
	break;    
      } else 
	return B_NIEPOPRAWNAOPCJA; /* nie podano drugiej litery */
      break;
    }

    case 'h': {
      wybor->rozciaganie_histogramu=1;
      break;    
    }


    case 'd': {                 /* mamy wyswietlic obraz */
      wybor->wyswietlenie=1;
      break;
    }
    default:                    /* nierozpoznana opcja */
      return B_NIEPOPRAWNAOPCJA;
    } /*koniec switch */
  } /* koniec for */

  if (wybor->plik_we!=NULL)     /* ok: wej. strumien danych zainicjowany */
    return W_OK;
  else 
    return B_BRAKPLIKU;         /* blad:  nie otwarto pliku wejsciowego  */
}

