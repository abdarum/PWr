#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//#define BUFSIZ 50
#define BRAK_PROBY_NADANIA -1
#define PODJETO_PROBE_NADANIA -2
#define POBRANO_NAZWE_PLIKU "POBRANO_NAZWE_PLIKU"

/*
 * fd[0] odbiera informacje
 * fd[1] nadaje informacje
 */


int main(){
	int potok_fd[2], licz, status;
	char bufor[BUFSIZ];
	char name_of_file[200];
	name_of_file[0] = '\0';


	pipe(potok_fd);
	
	status = 0;
	int sending_status = BRAK_PROBY_NADANIA;
	sending_status = PODJETO_PROBE_NADANIA;



	if (fork()==0){
	
		while((licz=read(potok_fd[0], bufor, BUFSIZ))>0)
		{
			write(1, "informacja zwrotna:\n", 21);
			write(1, bufor, licz);

			//execlp("display","display", bufor);
			execlp("ls","ls");
			strcpy(name_of_file, bufor);
			if(strstr(name_of_file,"\n") != NULL){
				printf("%s", name_of_file);
				write(0, POBRANO_NAZWE_PLIKU, (strlen(POBRANO_NAZWE_PLIKU)+1));
				close(potok_fd[0]);
				close(potok_fd[1]);
				//execlp("display","display",name_of_file);
				exit(0);
			}

		}


		/*
		close(0);
		//dup(potok_fd[0]);
		close(potok_fd[1]);
		//close(potok_fd[0]);
		//close(1);
		//if(read(potok_fd[0], bufor, BUFSIZ)>0)
		//	execlp("display","display", bufor);
		

		strcpy(bufor, "kubus3.jpg");
		execlp("display","display", bufor);
		//write(1, "wyswietlono",12);
		//exit(0);


		while((licz=read(potok_fd[0], bufor, BUFSIZ))>0)
		{
			write(1, "informacja zwrotna:\n", 21);
			write(1, bufor, licz);
		}

		//execlp("display","display", bufor);
		*/
	}
	else
	{
		printf("nieudany fork");
	}



	while((licz=read(0, bufor, BUFSIZ))>0)
	{
		if(strstr(bufor,POBRANO_NAZWE_PLIKU) != NULL){
			close(potok_fd[0]);
			close(potok_fd[1]);
			close(0);
			close(1);

		}

		write(1, "informacja zwrotna rodzic:\n", 28);
		//printf("%s | %d \n",bufor,licz);
		write(1, bufor, licz);
		write(1, "\n", 2);


		write(potok_fd[1], bufor, licz);


	}


	//execlp("display","display", "kubus3.jpg");





	






	/*

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
	*/



	wait(&status);
	return(status);
}
