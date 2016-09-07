#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CMD1
#define CMD1 "<Command #1 here>"
#endif

#ifndef CMD2
#define CMD2 "<Command #2 here>"
#endif


static char *str_duplicate (char *str) {
    char *other = malloc(strlen(str) + 1);
    if (other != NULL)
        strcpy(other, str);
    return other;
}


void call(char cmd[]) {

    char *argv[100];
    int argc = 0;

    char *str = strtok(cmd, " ");
    while (str != NULL) {
        argv[argc++] = str_duplicate(str);
        str = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    execvp(argv[0], argv);
}


int main() {

    int pipefd[2];
    pipe(pipefd);

    pid_t pid;
    pid = fork();

    if (0 == pid){
        // child
        close(pipefd[0]);
        dup2(pipefd[1], 1);

        char cmd1[100] = CMD1;
        call(cmd1);

    }
    else {
        // parent
        close(pipefd[1]);
        dup2(pipefd[0], 0);

        char cmd2[100] = CMD2;
        call(cmd2);
    }

    return 0;
}
