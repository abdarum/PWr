#ifndef FUNKCJE
#define FUNKCJE

#include<stdio.h>
#inclued<string.h> 

#define DL_LINI 1024

typedef struct element {
  int wart;
  struct element *nast;
}t_elem;

void push(t_elem **stos,int element);
int pop(t_elem **stos);
int empty(t_elem **stos);
void print(t_elem *stos);
void inicjuj(t_elem **stos);

#endif

/*****************************

empty modyfikuj
dodaj tez

*****************************/



/* wywolanie w main */ 
/*
int main(){

  t_elem *stos;
  stos=(t_elem*)malloc(sizeof(t_elem));


  inicjuj(&stos);
}
*/
