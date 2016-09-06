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
        close(pipefd[0]); // reading end of the pipe
        dup2(pipefd[1], 1); // stdout ---> pipe writing end
        execlp("ls", "ls", NULL);

    }
    else {
        // parent
        close(pipefd[1]); // writing end of the pipe
        dup2(pipefd[0], 0);  // stdin ----> pipe reading end
        execlp("wc", "wc", NULL);
    }

    return 0;
}
