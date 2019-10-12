#include <stdio.h>
#include <string.h>

#define DL_LINI 1024

int wyswietl_wyrazy(char *str);
void wczytaj_wyrazy(char *str);
void zostaw_znaki(char *str,int len);


int main (){
  char str[DL_LINI];
  int len=0;
  printf("Podaj wyrazy:\n");
  
  wczytaj_wyrazy(str);

/*
    gets(str);  */
  printf("|Napis pierwotny -> | %s\n",str);
  /*
  len=strlen(str)+1; 
  zostaw_znaki(str, len); 
  */
  /*  wczytaj_wyrazy(str); */
  printf("%s",str); 
  /* wyswietl_wyrazy(str);  */
  return 0;
}



void wczytaj_wyrazy(char *str){
  int i=0;
  char c;
  scanf("%c",&c);
  while(c!=EOF){
    while(c>='A'&&c<='Z'&&c>='a'&&c<='z'&&c==' '){
      str[i]=c;
      i++;
      scanf("%c",&c);
      printf("%c",c);
    }
  }
}

void zostaw_znaki(char *str,int len){
  int i=0;
  char c;
  while(i<len){
    c=str[i];
    if((c>='A'&&c<='Z'&&c>='a'&&c<='z'&&c==' ')==0){
      /*      strcpy(str+1,str);  */
      str[i]=str[i+1]; 
      len--;
    }
    i++;
  }
  str[len-1]='\0';
}


int wyswietl_wyrazy(char *str){
  char * tmp;
  tmp = strtok(str," ,.-");
  while (tmp != NULL)
    {
      printf ("%s\n",tmp);
      tmp = strtok (NULL, " ,.-");
    }
  printf("\n");
  return 0;
}
