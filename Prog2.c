#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>

int main()
{
        #ifdef _POSIX_JOB_CONTROL
                printf("System supports POSIX job control.\n");
        #else
                printf("System  does not support POSIX job control.\n");
        #endif

        #ifdef _POSIX_SAVED_IDS
                printf("System supports saved set UID and GID.\n");
        #else
                printf("System does not support saved set GID and UID.\n");
        #endif

        #ifdef _POSIX_CHOWN_RESTRICTED
                printf("System supports change of Ownership of a file.\n");
        #else
                printf("Chown Restricted not defined.\n");
        #endif

        #ifdef _POSIX_NO_TRUNC
                printf("System supports pathname trunc option.\n");
        #else
                printf("Truncation Option not defined.\n");
        #endif

        #ifdef _POSIX_VDISABLE
                printf("System supports character disability option for terminal files.\n");
        #else
                printf("System  does not support character disability option.\n");
        #endif

        return 0;
}
