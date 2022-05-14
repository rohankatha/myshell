#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
void fg(char *f)
{
    int pid;
    if ((pid = fork()) == 0)
    {

        
        {
             execl("/bin/bash", "bash", "-c", f, (char *)0);
        }
    }
    else
    {
        wait(NULL);
    }
}
