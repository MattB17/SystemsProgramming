// implements the shell command `sort < file1 | uniq`
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
  int fd[2], r;

  // create the pipe
  if ((pipe(fd)) == -1) {
    perror("pipe");
    exit(1);
  }

  // parent will run sort
  if ((r = fork()) > 0) {
    // set up the redirection from file1 to stdin
    int filedes = open("file1", O_RDONLY);

    // reset stdin so that reads come from the file
    if ((dup2(fileds, fileno(stdin))) == -1) {
      perror("dup2");
      exit(1);
    }

    // reset stdout so that writes go to the pipe
    if ((dup2(fd[1], fileno(stdout))) == -1) {
      perror("dup2");
      exit(1);
    }

    // parent won't read from pipe so close read file descriptor
    if ((close(fd[0])) == -1) {
      perror("close");
    }

    // writes go to stdout, so no one should write to fd[1]
    if ((close(fd[1])) == -1) {
      perror("close");
    }

    // close filedes
    if ((close(filedes)) == -1) {
      perror("close");
    }

    execl("/usr/bin/sort", "sort", (char *) 0);
    fprintf(stderr, "ERROR: exec should not return\n");
  // child will run uniq
  } else if (r == 0) {
    // reset stdin so that it reads from the pipe
    if ((dup2(fd[0], fileno(stdin))) == -1) {
      perror("dup2");
      exit(1);
    }

    // the child process will never write to the pipe
    if ((close(fd[1])) == -1) {
      perror("close");
    }

    // stdin reads from the pipe so fd[0] is not needed
    if ((close(fd[0])) == -1) {
      perror("close");
    }

    execl("/usr/bin/uniq", "uniq", (char *) 0);
    fprintf(stderr, "ERROR: exec should not return \n");
  } else {
    perror("fork");
    exit(1);
  }

  return 0;
}
