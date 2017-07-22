#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char *argv[])
{
        int fd;
        char buffer[256]={""};
        struct flock filelock;
	fd=open(argv[1],O_RDWR);

        if(fd==-1)
        {
                printf("Error in opening file!!\n");
                return 1;
        }

	lseek(fd,-100,SEEK_END);
	filelock.l_whence=SEEK_CUR;
	filelock.l_start=0;
        filelock.l_len=100;

	if(fcntl(fd,F_GETLK,&filelock)==0)
	{
	        printf("File Locked\n");
		printf("\nFile is locked by process (pid) :    \t%d\n",filelock.l_pid);
		return 0;
	}
	else
	{
		printf("Not Locked\n");   		
		filelock.l_type=F_WRLCK;
        	filelock.l_whence=SEEK_END;
    		filelock.l_start=0;
        	filelock.l_len=100;
	       	
		if((fcntl(fd,F_SETLK,&filelock))==-1)
		{     
		      printf("\nError in Locking File....\n");        
		      return 1;        
		}
		else
		{	
			printf("File locked\n");
			lseek(fd,-50,SEEK_END);
			printf("Contents of locked file are = \n");
			if(read(fd,buffer,sizeof(buffer)))
			{
		        	printf("%s",buffer);
			}
		}
	}
	
	filelock.l_type = F_UNLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;
	if((fcntl(fd,F_UNLCK,&filelock))==-1)
	{
	        printf("Error in Unlocking File\n");
	        return 1;
	}
	else
	{
		printf("File Unlocked\n");
		close(fd);
		return 0;
	 }
}
