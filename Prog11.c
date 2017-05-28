#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen(char B[], char s1[], char s2[], int else_flag)
{
        int Bt=101, Bf=102, Sn=103;
        printf("\n\t if %s GOTO %d", B, Bt);
        printf("\n\t GOTO %d", Bf);
        printf("\n%d :\t%s", Bt, s1);

        if (!else_flag)
                printf("\n%d :\n", Bf);
        else 
	{
                printf("\n\t GOTO %d", Sn);
                printf("\n%d:\t%s", Bf, s2);
                printf("\n%d:\n", Sn);
        }
}

int main() 
{
        int else_flag = 0, i = 0;
        char stmt[60], tok[10][20], *p;

        printf("Format of if statement\nExample\n");
        printf("if (a<b) then (s,a)\n");
        printf("if (a<b) then (s,a) else (s,b)\n");
        
	printf("Enter statement\n");
        scanf("%[^\n]", stmt);

        p = strtok(stmt, " ");
        while(p) 
	{
                strcpy(tok[i++], p);
                if(!strcmp(p, "else"))
                        else_flag = 1;
                p = strtok(NULL, " ");
        }

        if(else_flag) 
                gen(tok[1],tok[3],tok[5],else_flag);

        else 
                gen(tok[1], " ", tok[3], else_flag);
 
       return 0;
}
