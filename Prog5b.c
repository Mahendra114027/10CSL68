#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	if(argc==3)
	{
		printf("Hard Link is Created\n");
		return link(argv[1],argv[2]);
	}
	else if(argc==4)
	{
		if(!strcmp(argv[1],"-s"))
		{
			printf("Symbolic Link is Created\n");
			symlink(argv[2],argv[3]);
		}
		else
		{
			printf("argv[1] should be -s for creating a symbolic link\n");
		}
	}
	else
	{
		printf("Invalid no. of arguments\n");
	}
	return 0;
}
