#include <stdio.h>

// prints all command line arguments
int main(int argc, char **argv) {
  printf("%d\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("argv[%d] has the value %s\n", i, argv[i]);
  }

  return 0;
}
