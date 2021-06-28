// given a string `dest`, the `insert()` function adds a copy of `char c2`
// after each instance of `char c1` in dest
#include <stdio.h>
#include <string.h>

void insert(char *dest, char c1, char c2) {
  char temp[strlen(dest)];
  strcpy(temp, dest);

  int temp_idx = 0, dest_idx = 0;

  // Iterate through the string until we reach the null terminator
  while (temp[temp_idx] != '\0') {
    dest[dest_idx] = temp[temp_idx];
    if (temp[temp_idx] == c1) {
      dest_idx++;
      dest[dest_idx] = c2;
    }
    dest_idx++;
    temp_idx++;
  }
  dest[dest_idx] = '\0';
}

void insert2(char *dest, char c1, char c2) {
  int dest_idx = 0;
  while (dest_idx < strlen(dest)) {
    if (dest[dest_idx] == c1) {
      int shift;
      for (shift = (strlen(dest) + 1); shift > (dest_idx + 1); shift--) {
        dest[shift] = dest[(shift - 1)];
      }
      dest_idx++;
      dest[dest_idx] = c2;
    }
    dest_idx++;
  }
}

int main() {
  char sample[7] = "momo";
  insert(sample, 'm', 'o');
  printf("%s\n", sample);

  char sample2[7] = "momo";
  insert2(sample2, 'm', 'o');
  printf("%s\n", sample2);

  return 0;
}
