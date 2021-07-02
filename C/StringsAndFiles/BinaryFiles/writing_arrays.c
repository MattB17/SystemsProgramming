#include <stdio.h>

int main() {
  FILE *data_file;
  int error;
  int numbers[] = {400, 800, 1200, 1600, 2000};

  data_file = fopen("array_data", "wb");
  if (data_file == NULL) {
    fprintf(stderr, "Error: could not open file\n");
    return 1;
  }

  // write the array
  error = fwrite(numbers, sizeof(int), 5, data_file);
  if (error != 5) {
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
