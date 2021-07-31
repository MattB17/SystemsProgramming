#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int result;

  printf("[%d] Original process (my parent is %d)\n",
         getpid(), getppid());
  result = fork();

  if (result == -1) {
    perror("fork");
    exit(1);
  } else if (result == 0) {
    printf("Child PID = %d, Parent PID = %d \n", getpid(), getppid());
    exit(10);
  }

  // parent sleeps 20, so child already finished
  sleep(20);

  pid_t pid;
  int status;
  // child already terminated before wait is called
  // even though the child terminates, the OS needs to keep information
  // about the status of this process in case the parent process needs
  // to know this value
  if ((pid = wait(&status)) == -1) {
    perror("wait");
  } else {
    if (WIFEXITED(status)) {
      printf("Child %d terminated with %d\n",
             pid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Child %d terminated with signal %d\n",
             pid, WTERMSIG(status));
    }
  }
  printf("[%d] Parent about to terminate\n", getpid());

  return 0;
}
