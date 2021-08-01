/* We send text from the parent to the child
 *
 * The parent process reads from stdin in a loop and writes each line it reads
 * to the pipe. The child process reads from the pipe and prints each line it
 * reads to standard output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXSIZE 4096

int main() {
  char line[MAXSIZE];
  int fd[2];

  // create a pipe
  if (pipe(fd) == -1) {
    perror("pipe");
  }

  int r = fork();

  // parent reads from stdin and writes to child
  // close the read file descriptor as parent writes to pipe
  if (r > 0) {
    close(fd[0]);
    printf("Enter a line > ");
    while (fgets(line, MAXSIZE, stdin) != NULL) {
      printf("[%d] writing to pipe\n", getpid());
      if (write(fd[1], line, MAXSIZE) == -1) {
        perror("Write to pipe");
      }

      printf("[%d] finished writing\n", getpid());
      printf("Enter a line > ");
    }

    close(fd[1]);

    printf("[%d] stdin has been closed, waiting for child\n", getpid());

    int status;
    if (wait(&status) != -1) {
      if (WIFEXITED(status)) {
        printf("[%d] Child exited with %d\n", getpid(),
                WEXITSTATUS(status));
      } else {
        printf("[%d] Child exited abnormally\n", getpid());
      }
    }
  // child reads from parent
  // close the write file descriptor since child will read from pipe
  } else if (r == 0) {
    close(fd[1]);
    printf("[%d] child\n", getpid());
    char other[MAXSIZE];

    while (read(fd[0], other, MAXSIZE) > 0) {
      printf("[%d] child received %s", getpid(), other);
    }
    printf("[%d] child finished reading", getpid());
    close(fd[0]);
    exit(0);
  } else {
    perror("fork");
    exit(1);
  }
  return 0;
}
