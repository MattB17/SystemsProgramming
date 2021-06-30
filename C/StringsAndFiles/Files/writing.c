#include <stdio.h>

int main() {
  FILE *output_file;
  int error;
  int total = 50;
  float small_number = 0.125;

  // open file for writing
  output_file = fopen("myfile.txt", "w");
  if (output_file == NULL) {
    fptintf(stderr, "Error opening file\n");
    return 1;
  }

  // write lines to file
  fprintf(output_file, "The first line in the file\n");
  fprintf(output_file, "The integer is %d\n", total);
  fprintf(output_file, "The small float is %f\n", small_number);

  error = fclose(output_file);
  if (error != 0) {
    fprintf(stderr, "fclose failed\n");
    return 1;
  }

  return 0;
}
