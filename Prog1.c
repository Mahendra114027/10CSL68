#include<stdio.h>
#include<unistd.h>

int main()
{
	long int res;
	
	if((res=sysconf(_SC_CLK_TCK))==-1)
		printf("Error in sysconf\n");
	else
		printf("Number of Clock Ticks =%ld\n",res);

	if((res=sysconf(_SC_CHILD_MAX))==-1)
		printf("Error in sysconf\n");
	else
		printf("Maximum number of Child Processes owned by a process = %ld\n",res);

	if((res=pathconf("/",_PC_PATH_MAX))==-1)
		printf("Error in pathconf\n");
	else
		printf("Maximum path length = %ld\n",res);

	if((res=pathconf("Prog1.c",_PC_NAME_MAX))==-1)
		printf("Error in pathconf\n");
	else
		printf("Maximum number of characters in a file = %ld\n",res);

	if((res=sysconf(_SC_OPEN_MAX))==-1)
		printf("Error in sysconf\n");
	else
		printf("Maximum number of open files/processes =%ld\n",res);

	return 0;
}
