#include "funkcje.h"

void push(t_elem **stos,int element){
  t_elem *tmp;
  tmp=(t_elem*)malloc(sizeof(t_elem));
  tmp->wart=element;
  tmp->nast=*stos;           
  *stos=tmp;
 }
 
int pop(t_elem **stos){
  t_elem *tmp;
  int elem;
   
  if (*stos!=NULL)
    {
      elem=(*stos)->wart;
      tmp=*stos;
      *stos=(*stos)->nast;
      free(tmp);
      return elem;
    }
       
  else fprintf(stderr,"Stos jest pusty");
}

int empty(t_elem *stos){
  t_elelm *tmp;
  
  if (&stos==NULL)
    return 0;
}

void print(t_elem *stos){
  t_elem tmp;
  tmp=*stos;

  while (tmp!=NULL)
    {
      printf("%d ", tmp->wart);
      tmp=tmp->nast;
    }
  printf("\n");
}

void inicjuj(t_elem **stos){

  *stos=NULL;
}
