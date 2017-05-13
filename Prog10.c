#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void callme(int sig_no)
{
	printf("Hello\n");
}

int main()
{
	struct sigaction action;
	action.sa_handler=(void(*)(int))callme;
	sigaction(SIGALRM,&action,0);
	alarm(2);
	pause();
	return 0;
}
