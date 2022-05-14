#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <wait.h>
#include "jobs.h"
#include "fg.h"
#include "pinfo.h"
#include "bg.h"
#include "sig.h"
#include "sigc.h"
#include "bg1.h"
int main()
{
    int a;
    char buffer[1024];
    char c[100];

    char der[100];
    char djik[100];
    getcwd(djik, 100);
     signal(SIGTSTP,signale);
         signal(SIGINT,signao);
    while (1)
    {
        printf("\033[0;32m");
        char s[1024];
    char d[1024];
   
    
    int fl = 0;
    int ml = 0;
    int sod = 0;
        int k = getpid();
        char ckj[34];
        char *sz;
        sz = getenv("USERNAME");
        char skl;
        gethostname(ckj, 34);
        getcwd(c, 100);

        if (strcmp(c, djik) == 0)
        {

            printf("<%s@%s:~>", sz, ckj);
        }
        else
        {
            char lk[strlen(c) - strlen(djik) + 1];
            for (int i = strlen(djik) + 1; i < strlen(c); i++)
            {

                lk[i - strlen(djik)] = c[i];
            }

            lk[0] = '/';

            lk[strlen(c) - strlen(djik)] = '\0';

            printf("<%s@%s:~%s>", sz, ckj, lk);
        }

        printf("\033[0m");

        char *comand = fgets(buffer, 1024, stdin);
        if(comand == NULL)
        {
            kill(0,9);
        }
        int len = strlen(comand);
        comand[len - 1] = '\0';
        char *context = NULL;
        char *token = strtok_r(comand, ";", &context);

        while (token != NULL)
        {

            int count = 0;
            int j = 0;
            int lop = 0;

            for (int i = 0; i < strlen(token); i++)
            {

                if (token[i] != ' ')
                {
                    count++;
                }
                if (token[i] == ' ' && token[i + 1] != ' ')
                {
                    lop++;
                }
            }
            for (int i = 0; i < strlen(token); i++)
            {
                if (token[i] == '>')
                {
                    if (token[i + 1] == '>')
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

            if (count != 0)
            {
                char f[count + lop];
                char dup[100];

                int op = 0;
                for (int i = 0; i < len; i++)
                {
                    if (token[i] != ' ')
                    {
                        f[j] = token[i];

                        op++;
                        j++;
                    }
                    if (token[i] == ' ' && token[i + 1] != ' ')
                    {
                        f[j] = '#';
                        j++;
                    }
                }
                strcpy(dup, f);

                char *monkey = NULL;
                char *moey = NULL;
                char *moie = NULL;
                char *poken = strtok_r(f, "#", &monkey);
                poken = strtok_r(NULL, "#", &monkey);
                char *pok = strtok_r(f, "#", &moie);
                
                 char wetyu[100];
                char *mali = strtok_r(f, "#", &moey);

                if (strcmp(mali, "pinfo") == 0)
                {

                    if (poken == NULL)
                    {
                        int num = getpid();
                        char fup[300];
                        sprintf(fup, "%d", num);
                        pinfo(fup);
                    }
                    else
                    {

                        pinfo(poken);
                    }
                }
                if (strcmp("jobs", mali) == 0)
                {
                    if (poken == NULL)
                    {
                        char ckio[1];
                        strcpy(c, "o");
                        jobs(c);
                    }
                    else
                    {
                        jobs(poken);
                    }
                }
                if (strcmp("sig", mali) == 0)
                {
                    
                   int ert = atoi(poken);
                  
                    
                     strcpy(wetyu,poken);
                  
                    poken = strtok_r(NULL, "#", &monkey);
                     int gul = atoi(poken);
                    
                   sig(ert,gul);

                }
                if(strcmp("bg",mali) == 0)
                {
                    int sery = atoi(poken);
                    
                    bg(sery);

                }

                if (dup[strlen(dup) - 1] != '&' && strcmp(mali, "pinfo") != 0 && strcmp(mali, "echo") != 0 && strcmp(mali, "pwd") !=0 &&  strcmp(mali, "jobs") != 0 && strcmp(mali, "sig") != 0 && strcmp(mali,"bg") != 0)
                {
                    if (token != NULL)
                    {
                        fg(token);
                    }
                }
                int pi;
                if (strcmp(mali, "echo") == 0)
                {
                    int hp = 0;
                    for (int i = 0; i < strlen(token); i++)
                    {
                        if (token[i] != ' ')
                        {

                            hp++;
                        }
                        if (token[i] != ' ' && hp >= 5)
                        {
                            printf("%c", token[i]);
                        }
                    }
                    printf("\n");
                }
                if (strcmp(mali, "pwd") == 0)
                {
                    printf("%s\n", getcwd(c, 100));
                }

                if (dup[strlen(dup) - 1] == '&' && strcmp(mali, "pinfo") != 0)
                {
                    if (token != NULL)
                    {
                        int pi = bgd(token);
                    }
                }
            }

            token = strtok_r(NULL, ";", &context);
        }
    }
}