#include<stdio.h>

#define END 99
#define MIN -5
#define MAX 5

int main(){

 signed int liczba;
 int counter = 1;

 liczba = 0;

 printf("\n");

 while(liczba != END){
   printf("Podaj %d. wartosc parametru: ", counter);
  scanf("%d",&liczba);

 if(MIN<=liczba && liczba<=MAX) printf("Aktualna wartosc parametru: %d\n", liczba); 
 else  if(liczba != END) printf("Bledna wartosc parametru!\n");

  counter++; 
}

 printf("\n"); 

}
