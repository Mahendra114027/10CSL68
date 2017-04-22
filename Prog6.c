// Code to demonstrate Race COndition between processes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_char(char *);

int main()
{
        pid_t pid;
        if ((pid = fork()) < 0)
                printf("fork error\n");
        else if (pid == 0)
                print_char("Output from Child\n");
        else
                print_char("Output from Parent\n");
        exit(0);
}
void print_char(char *str)
{
        char *ptr;
        int c;
        setbuf(stdout,NULL);
        for(ptr=str;(c=*ptr++)!=0;)
                putc(c,stdout);
}
