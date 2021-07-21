#include <string.h>

// s is a pointer to the first character in the string
void print_recursive(char *s) {
  // base case
  if (*s == '\0') {
    printf("\n");
    return;
  }
  printf("%c", *s);
  // move to next character in array
  print_recursive(s + 1);
}
