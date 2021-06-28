// writing a function `my_strlen` that takes a constant string as input and
// returns an integer whose value is the number of characters found before
// the null termination character ('\0')
#include <stdio.h>
#include <string.h>

int my_strlen(const char *s) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

int main() {
  char fruit[] = "apples";
  int n = my_strlen(fruit);
  printf("%s has length %d\n", fruit, n);
  return 0;
}
