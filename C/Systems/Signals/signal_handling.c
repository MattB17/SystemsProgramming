#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unisted.h>

void handler(int code) {
  fprintf(stderr, "Signal %d caught\n", code);
  // after this control will return to the program
  // if you want it to quit add `exit(1);`
}

int main() {
  int i = 0;

  // install new function in signal table
  struct sigaction newact;
  newact.sa_handler = handler;
  newact.sa_flags = 0;              // default flags
  sigemptyset(&newact.sa_mask);     // block no signals during handling
  sigaction(SIGINT, &newact, NULL);

  for (;;) {
    if ((i++ % 50000000) == 0) {
      fprintf(stderr, ".");
    }
  }

  return 0;
}
