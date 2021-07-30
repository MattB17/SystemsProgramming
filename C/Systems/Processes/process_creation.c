#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
  int result;
  int i, j;

  // prints message with its ID and parent's ID
  printf("[%d] Original process (my parent is %d)\n",
          getpid(), getppid());

  // creates 5 child processes
  for (i = 0; i < 5; i++) {
    result = fork();

    if (result == -1) {
      // if error with fork
      perror("fork");
      exit(1);
    } else if (result == 0) {
      // child process performs loop, printing message and then sleeping
      for (j = 0; j < 5; j++) {
        printf("[%d] Child %d %d\n", getpid(), i, j);
        // each time usleep is called, control is given back to the operating
        // system and it has to make a decision on which process will run next
        usleep(100);
      }
      exit(0);
    }
  }

  printf("[%d] Parent about to terminate\n", getpid());

  return 0;
}
