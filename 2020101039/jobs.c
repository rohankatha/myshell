#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>
void jobs(char *l)
{
    char a[100];
    int meter = 1;
    int arr[100];
    char jobs[100][100];
    char line[300];
    
    {
        int pid = fork();

        if (pid == 0)
        {

            execl("/bin/bash", "bash", "-c", "ps u  | awk '{print $8,$11,$2}' > gud.txt ", (char *)0);
        }
        else
        {
            wait(NULL);
        }
        FILE *fd = fopen("gud.txt", "r");
        
        int fg = open("b.txt",O_CREAT | O_WRONLY);
        while (fgets(line, sizeof(line), fd))
        {
            int b = 0;
            char *tok = strtok(line, " ");
            if (tok[0] == 'T')
            {
                strcpy(a, "Stopped");
                b++;
            }
            if (strcmp(tok, "Sl") == 0 || strcmp(tok, "S") == 0 || strcmp(tok, "R") == 0)
            {
                strcpy(a, "Running");
                b++;
            }
            tok = strtok(NULL, " ");
            strcpy(jobs[meter], tok);
            tok = strtok(NULL, " ");
            arr[meter] = atoi(tok);

            fflush(stdout);

            fflush(stdout);
            if (b)
            {  
                if(strcmp(l,"o") == 0)
                {
                  printf("[%d] %s  %s [%d] \n", meter, a, jobs[meter], arr[meter]);
                }
                if(strcmp(l,"-r") == 0)
                {
                    if(strcmp(a,"Running") == 0)
                    {
                        printf("[%d] %s  %s [%d] \n", meter, a, jobs[meter], arr[meter]);
                    }
                }
                if(strcmp(l,"-s") == 0)
                {
                    if(strcmp(a,"Stopped") == 0)
                    {
                        printf("[%d] %s  %s [%d] \n", meter, a, jobs[meter], arr[meter]);
                    }
                }

               
                
                meter++;
            }
            b = 0;
            
            
            
        }
        
         
    }
}