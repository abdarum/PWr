#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include <fcntl.h> 
#include <sys/stat.h> 

#define QUIT_COMMAND "exit()"

int main()
{
	int fd_fifo, fd_file;
	int licz, licz2;

	char * myfifo = "./tmp_to_remove_fifo";
	mkfifo(myfifo, 0666);
       	
	char bufor[BUFSIZ];
	char bufor2[BUFSIZ];
	strcpy(bufor, "");

	printf("\n\tTo exit of this program enter \"%s\"\n\n", QUIT_COMMAND);

	while(1)
	{
		printf("Enter name of file to send to FIFO\n");
		licz=read(0, bufor, BUFSIZ);
		
		//printf("read |%s|\n",bufor);
		bufor[strcspn(bufor, "\n")] = 0;
		//printf("read |%s|\n",bufor);
		if(strcmp(bufor, QUIT_COMMAND) == 0)
		{
			printf("You quit!\n");
			return 0;
		}

		fd_fifo = open(myfifo, O_WRONLY); 
		fd_file = open(bufor, O_RDONLY); 

		write(fd_fifo, "\n*******************\n", 22);
		write(fd_fifo, "Name of file:\n", 15);
		write(fd_fifo, bufor, licz);
		write(fd_fifo, "\n", 2);
		write(fd_fifo, "*******************\n\n", 22);

		while ((licz2=read(fd_file, bufor2, BUFSIZ)) > 0)
			write(fd_fifo, bufor2, licz2);

		close(fd_file);
		close(fd_fifo); 



	}

	return -1;

}
