#include "funkcje_stosu.h"

void push(t_elem **stos,int element){
  t_elem *tmp;
  tmp=(t_elem*)malloc(sizeof(t_elem));
  tmp->wart=element;
  tmp->nast=*stos;           
  *stos=tmp;
 }
 
void pop(t_elem **stos,int *elem){
  t_elem *tmp;
  tmp=(t_elem*)malloc(sizeof(t_elem));
   
  if (*stos!=NULL)
    {
      *elem=(*stos)->wart;
      tmp=*stos;
      *stos=(*stos)->nast;
      free(tmp);
    }
       
  else fprintf(stderr,"Stos jest pusty\n");
}

int empty(t_elem *stos){
  
  if (stos==NULL)
    return 0;
  else
    return -1;
}

void print(t_elem *stos){
  /* t_elem tmp;
  tmp=*stos; */

  t_elem *tmp;
  tmp=(t_elem*)malloc(sizeof(t_elem));
  
  tmp=stos;
  if(tmp==NULL)
    fprintf(stderr,"Stos jest pusty\n");

  while(tmp!=NULL)
    {
      printf("%d ", tmp->wart);
      tmp=tmp->nast;
    }
  printf("\n");
}

void inicjuj(t_elem **stos){

  *stos=NULL;
}
