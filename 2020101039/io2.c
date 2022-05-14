#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>
void outputredir(char *f, char *d , int sod)
{   
        if(sod == 0)
        { 
            int fd = open(f, O_CREAT | O_WRONLY | O_TRUNC, 0644);
           dup2(fd,STDOUT_FILENO);
           int pid = fork();
           if(pid == 0)
           {
                 execl("/bin/bash", "bash", "-c", d, (char *)0);
           }
           else
           {
                execl("/bin/bash", "bash", "-c", "./a.out", (char *)0);
           }
          

        }
        else
        {
              int fd = open(f, O_CREAT | O_WRONLY | O_APPEND, 0644);
           dup2(fd,STDOUT_FILENO);
           int pid = fork();
           if(pid == 0)
           {
                 execl("/bin/bash", "bash", "-c", d, (char *)0);
           }
           else
           {
               execl("/bin/bash", "bash", "-c", "./a.out", (char *)0);
           }
        }
         
    
}

void inputredir(char* token)
{
     char d[1024];
    char f[1024];
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '<')
        {
            d[i] = '\0';
           
            break;
        }
        else
        {

            {
                d[i] = token[i];
            }
        }
    }
   

    {
        int j = 0;
        for (int i = strlen(d) + 1; i < strlen(token) - 1; i++)
        {
            if (token[i] != ' ')
            {
                f[j] = token[i];

                j++;
            }
        }
        f[j] = '\0';
    }
    
             int fd = open(f, O_RDONLY);
             if(fd == -1)
             {
                 printf("NO SUCH FILE OR DIRECTORY");
             }
                dup2(fd, STDIN_FILENO);
             
                int pid = fork();
           if(pid == 0)
           {
                 execl("/bin/bash", "bash", "-c", d, (char *)0);
           }
           else
           {
               execl("/bin/bash", "bash", "-c", "./a.out", (char *)0);
           }
}
void io2(char* token)
{
    char s[1024];
    char d[1024];
    char f[1024];
    int pid;
    int fl = 0;
    int ml = 0;
    int sod = 0;
   
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '>')
        {  
            if( token[i + 1] == '>')
            {
                sod++;
            }
            d[i] = '\0';
            ml++;
            break;
        }
        else
        {

            {
                d[i] = token[i];
            }
        }

           
    }
    
         
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '<')
        {
            fl++;
            break;
        }
    }
    if(sod == 0)
    {
        int j = 0;
        for (int i = strlen(d) + 1; i < strlen(token) - 1; i++)
        {
            if (token[i] != ' ')
            {
                f[j] = token[i];

                j++;
            }
        }
        f[j] = '\0';
    }
    else
    {
         int j = 0;
        for (int i = strlen(d) + 2; i < strlen(token) - 1; i++)
        {
            if (token[i] != ' ')
            {
                f[j] = token[i];

                j++;
            }
        }
        f[j] = '\0';
    }
     fflush(stdout);

  
   // printf("%d", fl);

    if (fl && ml)
    {

        outputredir(f, d,sod);
    }
    else
    {
        if (ml)
        {
            outputredir(f, d,sod);
        }
        else
        {
            if (fl)
            {
                inputredir(token);
            }
        }
    }
}