/* Program komentuje podaną temperature */

#include<stdio.h>

#define prog 20

int main(){

  int temp;

 printf("\n"); 

  printf("Podaj temperature we Wroclawiu: ");
  scanf("%d",&temp);


  if(temp  < prog){
    printf("Nie jest zbyt cieplo!\n");
  }
  else{
 printf("Jest bardzo ladna pogoda!\n");
  }

 printf("\n"); 

}
