#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
  int result;
  int i, j;

  printf("[%d] Original process (my parent is %d)\n",
          getpid(), getppid());

  for (i = 0; i < 5; i++) {
    result = fork();

    if (result == -1) {
      perror("fork");
      exit(1);
    } else if (result == 0) {
      for (j = 0; j < 5; j++) {
        printf("[%d] Child %d %d\n", getpid(), i, j);
        usleep(100);
      }
      exit(0);
    }
  }

  // wait for all processes to finish
  for (i = 0; i < 5; i++) {
    pid_t pid;
    int status;
    // call wait for each child
    if ((pid = wait(&status)) == -1) {
      perror("wait");
    } else {
      // check if process exited directly
      if (WIFEXITED(status)) {
        printf("Child %d terminated with %d\n", pid, WEXITSTATUS(status));
      // check for incorrect termination and print the reason
      } else if (WIFSIGNALED(status)) {
        printf("Child %d terminated with signal %d\n",
            pid, WTERMSIG(status));
      } else {
        printf("Shouldn't get here\n");
      }
    }
  }
  printf("[%d] Parent about to terminate\n", getpid());

  return 0;
}
