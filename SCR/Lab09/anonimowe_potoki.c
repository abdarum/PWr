#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//#define BUFSIZ 50

/*
 * fd[0] odbiera informacje
 * fd[1] nadaje informacje
 */


int main(){
	int potok_fd[2], licz, status;
	char bufor[BUFSIZ];
	char name_of_file[200];
	name_of_file[0] = '\0';
	pid_t pid;


	if (pipe(potok_fd) == -1)
	{
			fprintf(stderr, "Error, i can not create a pipe");
			return 1;
	}
	
	pid = fork();

	if(pid > 0)
	{
		//Parent
		close(potok_fd[0]);
		write(1, "Choose image to display:\n", 26);
		//licz=read(0, bufor, BUFSIZ);
		scanf("%s",bufor);
		licz=strlen(bufor)+1;
		printf("licz %d",licz);
		printf("\ndlugosc %d\n",strlen(bufor));
		printf("bufor %s\n",bufor);
		write(potok_fd[1], bufor, licz+1);
	}
	else if(pid == 0)
	{
		//Child
		close(potok_fd[1]);
		close(0);
		dup(potok_fd[0]);
		licz=read(potok_fd[0], bufor, BUFSIZ);
		//write(1, bufor, sizeof(bufor));
		printf("BUFOR %s\n", bufor);
		close(potok_fd[0]);
		execlp("display","display",bufor,NULL);
	}
	else
	{
			fprintf(stderr, "Error, i can not fork");
			return 1;
	}


	wait(&status);
	return(status);
}

