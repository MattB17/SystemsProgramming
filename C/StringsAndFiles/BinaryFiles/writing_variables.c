#include <stdio.h>

int main() {
  FILE *data_file;
  int error;
  int number = 512;
  char character = 's';
  float fraction = 4.5;

  data_file = fopen("my_data", "wb");
  if (data_file == NULL) {
    fprintf(stderr, "Error: could not open file\n");
    return 1;
  }

  // write the 3 variables
  error = fwrite(&number, sizeof(int), 1, data_file);
  error += fwrite(&character, sizeof(char), 1, data_file);
  error += fwrite(&fraction, sizeof(float), 1, data_file)l

  if (error != 3) {
    fprintf(stderr, "Error: data not fully written to file\n");
    return 1;
  }

  error = fclose(data_file);
  if (error != 0) {
    fprintf(stderr, "Error: fclose failed\n");
    return 1;
  }

  return 0;
}
