#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>
void sig(int ert , int gul)
{
    char line[300];
    int meter = 1;
    int arr[100];
    char jobs[100][100];


    FILE *fd = fopen("gud.txt", "r");

    while (fgets(line, sizeof(line), fd))
    {
        int b = 0;
        char *tok = strtok(line, " ");
        if (tok[0] == 'T')
        {

            b++;
        }
        if (strcmp(tok, "Sl") == 0 || strcmp(tok, "S") == 0 || strcmp(tok, "R") == 0)
        {

            b++;
        }
        tok = strtok(NULL, " ");
        strcpy(jobs[meter], tok);
        tok = strtok(NULL, " ");
        if (tok != NULL)
        {
            arr[meter] = atoi(tok);
        }

        fflush(stdout);

        fflush(stdout);
        if (b)
        {

            meter++;
        }
        b = 0;
    }
    if(ert <= meter)
    {
            kill(arr[ert],gul);
    }
    else
    {
        printf("NO SUCH JOB NUMBER \n");
    }
   
}