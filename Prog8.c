#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if((pid=fork())<0)
		printf("Fork Error\n");
	else if(pid==0)
	{
		printf("\nFirst Child PID = %d and its Parent PID = %d\n",getpid(),getppid());
		if((pid=fork())<0)
			printf("Fork Error\n");
		else if(pid>0)
			exit(0);

		sleep(2);

		printf("\nSecond Child PID = %d and its Parent PID = %d\n",getpid(),getppid());
		exit(0);
	}
	if(waitpid(pid,NULL,0)!=pid)
		printf("Waitpid Error\n");
	exit(0);
}			
