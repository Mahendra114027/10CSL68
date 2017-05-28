#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	int fd;
	char buff[256];
	if(argc!=2 && argc!=3)
	{
		printf("Invalid no. of arguments\n");
		return 0;
	}
	
	mkfifo(argv[1], S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO);
	
	if(argc==2)
	{
		fd=open(argv[1], O_RDONLY);
		printf("Content of FIFO files are :\n");
		while(read(fd,buff,sizeof(buff))>0)
			printf(buff);
		printf("\n");	
	}
	else
	{
		fd=open(argv[1], O_WRONLY);
		write(fd,argv[2],strlen(argv[2]));
	}
	close(fd);
}

