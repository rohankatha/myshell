#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <termios.h>
void signale (int signum)
{    
     int pid = fork();
     
     if(pid == 0)
     {    
           execl("/bin/bash", "bash", "-c", "./myshell2", (char *)0);
           //kill(pid,SIGSTOP);
     }
     else
     {
         wait(NULL);
         
         
     }
     
}
void signao (int signum)
{ 
   
   int pid = fork();
   int kid = getpid();
   if(pid == 0)
   {
         execl("/bin/bash", "bash", "-c", "./myshell2", (char *)0);
   }
   else
   {     wait(NULL);
         
        kill(kid+1,SIGKILL);
   }
   
   
}
