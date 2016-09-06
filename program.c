#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void read_pipe (int file) {
    FILE *stream;
    int c;
    stream = fdopen (file, "r");
    while ((c = fgetc (stream)) != EOF)
        putchar (c);
    fclose (stream);
}


void write_pipe (int file) {
    FILE *stream;
    stream = fdopen (file, "w");
    fprintf (stream, "foo\n");
    fprintf (stream, "bar\n");
    fclose (stream);
}


int main (void) {
    pid_t pid, pid_master;
    int mypipe[2];

    // create a pipe
    if (pipe (mypipe) != 0) {
        printf("Pipe error\n");
        return -1;
    }

    // fork the process
    pid_master = getpid();
    pid = fork();

    if ((pid_t) 0 == pid) {
        // slave
        close (mypipe[1]);
        read_pipe (mypipe[0]);
        return 0;
    }

    else {
        // master
        close (mypipe[0]);
        write_pipe (mypipe[1]);
        return 0;
    }
}
