#include <stdio.h>

#define LINE_LENGTH 80

int main() {
  FILE *scores_file;
  int error;
  char line[LINE_LENGTH + 1];

  scores_file = fopen("top10.txt", "r");
  if (scores_file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  }

  // while we continue to read lines
  while (fgets(line, LINE_LENGTH + 1, scores_file) != NULL) {
    printf("%s", line);
  }

  error = fclose(scores_file);
  if (error != 0) {
    fprintf(stderr, "fclose failed\n");
    return 1;
  }

  // can also use fgets to read from standard input
  while (fgets(line, LINE_LENGTH + 1, stdin) != NULL) {
    printf("You typed: %s", line);
  }

  return 0;
}
