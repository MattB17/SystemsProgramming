#include <stdio.h>
#include <stdlib.h>

// takes the average of the command line arguments if the first
// argument is "a", otherwise, takes the sum
int main(int argc, char **argv) {

  // ensure the program is called correctly
  if (argc < 3) {
    printf("Usage: typesExample <operation s/a> <args ...>\n");
    return 1;
  }

  int total = 0;
  for (int i = 2; i < argc; i++) {
    total += strtol(argv[i], NULL, 10);
  }

  if (argv[1][0] == 'a') {
    double avg = (double) total / (argc - 2);
    printf("average: %f\n", avg);
  } else {
    printf("sum: %d\n", total);
  }

  return 0;
}
