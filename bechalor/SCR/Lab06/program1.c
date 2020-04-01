#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define SIG_BLOCK   0 /* blokowanie sygnalow */
#define SIG_UNBLOCK 1 /* odblokowywanie sygnalow */
#define SIG_SETMASK 2 /* ustawianie nowej maski */

int handler_a_var = 0;
int handler_b_var = 0;
int handler_c_var = 0;
int handler_d_var = 0;

void handler_a(int sig) {
	handler_a_var = 1;
}

void handler_b(int sig) {
	handler_b_var = 1;
}

void handler_c(int sig) {
	handler_c_var = 1;
}

void handler_d(int sig) {
	handler_d_var = 1;
}

int main(){
	int i=0;
	int handler_c_timer = 0;
	sigset_t sig_c;
	sigset_t sig_d;
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	int ns_to_ms = 1000000;
	tim.tv_nsec = 1*ns_to_ms;

	(void) signal(SIGALRM, handler_a);
	(void) signal(SIGTERM, handler_b);
	(void) signal(SIGINT, handler_c);
	(void) signal(SIGQUIT, handler_d);
	while(1){
		if (handler_a_var){
			printf("\nProgram kończy pracę\n");
			handler_a_var = 0;
			exit(0);
		}

		if (handler_b_var){
			printf("\nTwój sygnał został odebrany\n");
			handler_b_var = 0;
		}

		if (handler_c_var){
			if (handler_c_timer == 0){
				printf("\nZatrzymano odbieranie sygnałów na 2s\n");
				sigemptyset (&sig_c);
				sigaddset(&sig_c, SIGINT);
				sigprocmask(SIG_BLOCK, &sig_c, NULL);
			}

			handler_c_timer++;

			if (handler_c_timer >= 5000){
				sigprocmask(SIG_UNBLOCK, &sig_c, NULL);
				handler_c_timer = 0; 
				handler_c_var = 0;
			}
		}

		if (handler_d_var){
			printf("\nZatrzymano permamentnie odbieranie sygnałów \n");
			sigemptyset (&sig_d);
			sigaddset(&sig_d, SIGQUIT);
			sigprocmask(SIG_SETMASK, &sig_d, NULL);
	
			handler_d_var = 0;
		}

		i++;
		nanosleep(&tim , &tim2);
		//printf("%d\n", i);
	}

	return 0;
}
