#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c;
  float aa, d, sqrtd;

  printf("Program wylicza rozwiazania dwumianu kwadratowego.\n");
  printf("Podaj wspolczynnik a:\n");
  scanf("%f", &a);
  printf("Podaj wspolczynnik b:\n");
  scanf("%f", &b);
  printf("Podaj wspolczynnik c:\n");
  scanf("%f", &c);

  aa = 2.0 * a;
  d  = (b*b) - (4.0*a*c);

  if (a != 0.0) {

    if (d == 0.0)
      printf("Istnieje jedno rozwiazanie: %f\n", -b/aa);

    else if  (d > 0.0) {

      sqrtd = (float) sqrt( (double)d );
      printf("Istnieja dwa rozwiazania rzeczywiste:\n");
      printf("  x1 = %f\n", (-b - sqrtd) / aa);
      printf("  x2 = %f\n", (-b + sqrtd) / aa);

    }

    else { /* czyli d <= 0 */

      sqrtd = (float) sqrt( (double)-d );
      printf("Istnieja dwa rozwiazania zespolone:\n");
      printf("  x1 = %f + %f i\n", -b/aa, sqrtd/aa);
      printf("  x2 = %f - %f i\n", -b/aa, sqrtd/aa);

    }
  }

  else { /* czyli a jest 0 */

    if (c == 0.0)
      printf("Dwumian jest jednomianem, jedyne rozwiazanie: x = 0.0\n");

    else if (b == 0.0) /* ale wiemy a=0 i c!=0 */
      printf("Dwumian jest sprzeczny (%f = 0.0), blad w danych.\n", c);

    else /* czyli b!=0 i c!=0 */
      printf("Dwumian jest jednomianem, jedno rozwiazanie: %f\n", -c/b);

  }
  return 0;
}

