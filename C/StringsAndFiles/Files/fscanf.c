#include <stdio.h>

int main() {
  FILE *scores_file;
  int error, total;
  char name[81];

  scores_file = fopen("top10.txt", "r");
  if (scores_file == NULL) {
    fprintf(stderr, "Error opening input file\n");
    return 1;
  }

  // "%80s %d" includes two format specifiers because we want to
  // read two fields. %80s tells it to read a string of at most 80
  // characters. %d indicates reading an integer after name
  // name is already a pointer whereas total is not and that is why
  // we use the &
  // we assert it is equal to 2 because we expect fscanf to find 2
  // things on each call
  while (fscanf(scores_file, "%80s %d", name, &total) == 2) {
    printf("Name: %s. Score: %d.\n", name, total);
  }

  error = fclose(scores_file);
  if (error != 0) {
    fprintf(stderr, "fclose failed on input file\n");
    return 1;
  }

  return 0;
}
