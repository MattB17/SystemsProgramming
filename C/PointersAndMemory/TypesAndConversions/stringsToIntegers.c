#include <stdio.h>
#include <stdlib.h>

int main() {
  char *s = "   -17 other junk.";
  char *leftover;
  int i = strtol(s, &leftover, 10);

  printf("i has the value %d\n", i);
  printf("leftover has the value %s\n", leftover);
  return 0;
}
