#include <stdio.h>

int main(void) {
  FILE *data_file;
  int error;

  int number;
  char character;
  float fraction;

  data_file = fopen("my_data", "rb");
  if (data_file == NULL) {
    fprintf(stderr, "Error: could not open file\n");
    return 1;
  }

  // read 3 variables
  // usually we would check the read values for errors
  fread(&number, sizeof(int), 1, data_file);
  fread(&character, sizeof(char), 1, data_file);
  fread(&fraction, sizeof(fraction), 1, data_file);
  printf("Here's what we got from the file: %d, %c, %f\n",
         number, character, fraction);

  error = fclose(data_file);
  if (error != 0) {
    fprintf(stderr, "Error: fclose failed\n");
    return 1;
  }

  return 0;
}
