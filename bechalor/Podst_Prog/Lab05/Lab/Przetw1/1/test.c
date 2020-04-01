 
#include <stdio.h>
#include <stdlib.h>
 
// We return the pointer
int **get(int N, int M) /* Allocate the array */
{
  /* Check if allocation succeeded. (check for NULL pointer) */
  int i, **table;
  table = malloc(N*sizeof(int *));
  for(i = 0 ; i < N ; i++)
    table[i] = malloc( M*sizeof(int) );
  return table;
}
 
// We don't return the pointer
void getNoReturn(int*** table, int N, int M) {
  /* Check if allocation succeeded. (check for NULL pointer) */
  int i;
  *table = malloc(N*sizeof(int *));
  for(i = 0 ; i < N ; i++)
    *table[i] = malloc( M*sizeof(int) );
}
 
void fill(int** p, int N, int M) {
  int i, j;
  for(i = 0 ; i < N ; i++)
    for(j = 0 ; j < M ; j++)
      p[i][j] = j;
}
 
void print(int** p, int N, int M) {
  int i, j;
  for(i = 0 ; i < N ; i++)
    for(j = 0 ; j < M ; j++)
      printf("array[%d][%d] = %d | %d\n", i, j, p[i][j],&p[i][j]);
}
 
void free2Darray(int** p, int N) {
  int i;
  for(i = 0 ; i < N ; i++)
    free(p[i]);
  free(p);
}
 
int main(void)
{
  int **p;
  // getNoReturn(&p, 2, 5);
  p = get(2, 5);
  fill(p ,2, 5);
  print(p, 2, 5);
  free2Darray(p ,2);
  return 0;
}
