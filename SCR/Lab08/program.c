#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//#define BUFSIZ 50
#define BRAK_PROBY_NADANIA -1
#define PODJETO_PROBE_NADANIA -2



int main(){
	int potok_fd[2], status;
	char bufor[BUFSIZ];
	char name_of_file[200];
	name_of_file[0] = '\0';
	
	pipe(potok_fd);

	int sending_status = BRAK_PROBY_NADANIA;
	sending_status = PODJETO_PROBE_NADANIA;


	if (fork()==0){
		int counter = 0;
		while (sending_status == BRAK_PROBY_NADANIA)
		{
			while(read(potok_fd[0], bufor, BUFSIZ)>0)
			{
				sending_status = PODJETO_PROBE_NADANIA;
				strcpy(name_of_file, bufor);
				if(strstr(name_of_file,"\n") != NULL){
					execlp("display","display",name_of_file);
					exit(0);
				}

			}
		}
	}

	//write(1, "Enter name of file:\n",  21);
	close(0);
	dup(potok_fd[1]);
	

	
	wait(&status);
	return(status);
}
