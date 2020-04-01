#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>


#define QUIT_COMMAND "exit()"
//#define FILEPATH "/home/kstefanc/Aktualne_kursy/SCR/Lab10/mmapped.bin"
#define FILEPATH "mmapped.bin"
#define NUMINTS  (1000)
#define FILESIZE (NUMINTS * sizeof(int))
#define BOOT_FILE  "/home/kstefanc/Aktualne_kursy/SCR/Lab10/kubus3_tmp.jpg"



size_t getFilesize(const char* filename) {
	struct stat st;
	stat(filename, &st);
	return st.st_size;
}


void load_image(char name_of_file[BUFSIZ])
{
	const char* fileName = name_of_file;

	int image = open(fileName, O_RDONLY);
	if (image <= 0)
	{
		perror("Not find image file\n");
	}
	int commonfile = open(FILEPATH, O_RDWR);
	if (commonfile <= 0)
	{
		close(image);
		perror("Not find common file\n");
	}
	struct stat st;
	stat(fileName, &st);
	ftruncate(commonfile, st.st_size);

	char* ptr = mmap(NULL, st.st_size,
					PROT_READ|PROT_WRITE , MAP_SHARED, commonfile, 0);
	read(image, ptr, st.st_size);
	msync(ptr, st.st_size, MS_SYNC);

	printf("Moved file\n");

	close(image);
	close(commonfile);
}


int main()
{
	int fd_mmap, fd_file;
	int licz, licz2;
	void *map;
	int result;
	FILE *infile;

	int PID;
	int status = 0;
	

	char bufor[BUFSIZ];
	char bufor2[BUFSIZ];
	strcpy(bufor, "");
	
	load_image(BOOT_FILE);

	//load_image("Lena3.jpg");

	printf("\n\tTo exit of this program enter \"%s\"\n\n", QUIT_COMMAND);

	PID = fork();

	if (PID == -1)
		exit(1);
	else if (PID == 0)
	{
		//execl("/usr/bin/display", "Display", BOOT_FILE, "-update 1", (char*)0);
		execlp("display", "display", "-update"," 1", FILEPATH, NULL);
		perror("Can not run display\n");
		exit(1);
	}
	
	do
	{
		printf("Enter name of file to send to mmap\n");
		scanf("%s", bufor);

		if(strcmp(bufor, QUIT_COMMAND) == 0)
		{
			printf("You quit!\n");
			break;
			return 0;
		}
		load_image("Lena3.jpg");

		printf("BUFOR: %s\n", bufor);

		load_image(bufor);

	}while(1);

	return -1;
}
