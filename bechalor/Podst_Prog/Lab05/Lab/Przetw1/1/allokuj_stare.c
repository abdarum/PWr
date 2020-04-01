
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
int **2d_array;
2d_array = (int **)malloc(sizeof(int *)*N);
for(i=0; i < N; i++) {
  2d_array[i] = (int *)malloc(sizeof(int)*M);
 }
*/

/*
void alokuj(int ***tablica, int rozmiar1, int rozmiar2)
{
  (*tablica)=new int*[rozmiar1];
  for(int i=0; i<rozmiar1;++i) (*tablica)[i]=new int[rozmiar2];
}
void alokuj(int **&tablica, int rozmiar1, int rozmiar2)
{
    tablica=new int*[rozmiar1];
    for(int i=0; i<rozmiar1; i++) tablica[i]=new int[rozmiar2];
}
int **mojatablica=NULL;
alokuj(&mojatablica, 10, 2);
*/



void alokuj_tablice(int ***tablica,int x,int y){
  int i;  
  (*tablica)=(int **)malloc(y*sizeof(int *));
  for(i=0;i<y;i++){
    (*tablica)[i]=(int *)malloc(x*sizeof(int));
  }
}  			    




void zwolnij_tablice(int **tablica,int x,int y){
  int i;
  for(int i=0;i<y;i++){
    free(tablica[i]);
  }
  free(tablica);
}


int main(){
  int **obraz;
  int i,j,x,y,a;
  /*
  printf("podaj podaj parametry tablicy");
  scanf("%d %d",&x,&y);
  */
  x=4;
  y=3;
  a=0;
  printf("przed alokacja %d\n",obraz); 
  alokuj_tablice(&obraz,x,y);
  printf("po alokacja %d\n",obraz);   
  printf("%d",obraz[0]);  

  int *ptr;
  for(i=0; i <y; i++) {
  printf("poczatek alokacja\n"); 
    *ptr = *(obraz[i]);  
    printf("%d \n",obraz[i]);
    for(j=0; j < x; j++) { 
      *ptr = 0; 
      printf("zapisano %d %d %d\n",a,*ptr,ptr);
      ptr++;
      a++;
    }
  }
  
  /*  printf("przed przypisaniem wartosci");
 int *ptr;
 for(i=0; i <y; i++) {
   printf("przed ptr| i %d | *ptr %d | *(obraz[i]) %d \n",i,*ptr,*(obraz[i])); 
   *ptr = *(obraz[i]);  
   printf("przed ptr| i %d | *ptr %d | *(obraz[i]) %d \n",i,*ptr,*(obraz[i])); 
   for(j=0; j < x; j++) { 
      *ptr = 0; 
      printf("po *ptr=0 | %d %d\n",a,*ptr);
      ptr++;
      a++;
    }
    } */

 /*
  printf("wyswietl dane");
 for(i=0; i <y; i++) {
   printf("przed ptr\n"); 
    *ptr = *(obraz[i]);  
  printf("po ptr\n"); 
   for(j=0; j < x; j++) { 
      *ptr = 0; 
      printf(" %d",*ptr);
      ptr++;
    }
  }

 */ 
  zwolnij_tablice(obraz,x,y);
  printf("tablica powinna byc zwolniona\n");
  /* zwolnij_tablice(obraz,x,y);*/
}
