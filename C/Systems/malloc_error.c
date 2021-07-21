#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv) {
  // LONG_MAX is too big to be allocated
  char *name = malloc(LONG_MAX);
  if (name == NULL) {
    perror("malloc");
    exit(1);
  }

  return 0;
}
