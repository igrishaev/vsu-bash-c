#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pipefd[2];
    pipe(pipefd);

    pid_t pid;
    pid = fork();

    if (0 == pid){
        // child
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        execl("/bin/ls", "ls", "-l", (char *) NULL);

    }
    else {
        // parent
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execl("/usr/bin/grep", "grep", "file", (char *) NULL);
    }

    return 0;
}
