/* Modul funkcji przetwarzania obrazow */

/*
 *  biel  - zmienna sluzy do zmiany poiomow jest to wartosc podawana w liczbach calkowitych odpowiadajocych procentom - dla 80% jest to liczba 80
 *  czern - podobnie jak w przypadku bieli
 *  prog - wartosc progu uzywana przy progowaniu i polprogowaniu. Rowniez podawana w procentach podobnie jak dla bieli
 */

#include "odczyt_zapis_obrazu.h"

void negatyw(obraz_struct *obraz);
void konturowanie(obraz_struct *obraz);
void zmiana_poziomow(obraz_struct *obraz,int czern,int biel);
void rozciaganie_histogramu(obraz_struct *obraz);
void progowanie(obraz_struct *obraz,int prog);
void progowanie_czerni(obraz_struct *obraz,int prog);
void progowanie_bieli(obraz_struct *obraz,int prog);
void rozmywanie_poziome(obraz_struct *obraz);
void rozmywanie_pionowe(obraz_struct *obraz);

