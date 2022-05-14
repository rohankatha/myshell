#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>
void pinfo(char *f)
{   char buffer[1024];
    char line[300];
    int p = atoi(f);
    int pid;
    pid = fork();
    sprintf(buffer, "ps u %d | awk '{print $2,$8,$5,$11}' > exp.txt ", p);
    if(pid == 0)
    {  
        execl("/bin/bash", "bash", "-c", buffer, (char *)0);

    }
    else
    {
        wait(NULL);
    }

    FILE *fd = fopen("exp.txt", "r");
    while (fgets(line, sizeof(line), fd))
    {
        if (line[0] != 'P')
        {
            printf("pid -- %d\n", p);
            char *tok = strtok(line, " ");

            tok = strtok(NULL, " ");
            
            {     if(strcmp(tok,"Ssl+") == 0 || strcmp(tok,"Sl+") == 0)
                  {
                          printf("Process status -- S+ \n");
                  }
                  else
                  {
                      printf("Process status -- %s \n", tok);
                  }
                  
            }
          

            tok = strtok(NULL, " ");

            printf("memory -- %s \n", tok);
            tok = strtok(NULL, " ");
            
            {
                   printf("Executable path -- %s  ", tok);
            }
            
        }
    }
    
    
}