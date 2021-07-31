#include <stdio.h>
#include <unistd.h>

int main() {
  printf("About to call execl. My PID is %d\n", getpid());
  execl("./hello", NULL);
  // should never get here if `execl` is successful
  perror("exec");
  return 1;
}
