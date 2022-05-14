#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
int bgd(char *f)
{

    pid_t pid;
    int status = 0;
    pid = fork();

    if (pid == 0)
    {
        
            
            {
                execl("/bin/bash", "bash", "-c", f, (char *)0);
            }
        
        
    }
    else
    {
        printf("%d\n", getpid());
    }
    return getpid();
}
