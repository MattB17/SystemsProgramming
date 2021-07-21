#include <stdio.h>
#include <string.h>

void print_backwards(char *s) {
  if (*s == '\0') {
    return;
  }
  // traverse to end of string and then start printing
  print_backwards(s + 1);
  printf("%c", *s);
}

int main() {
  char *s = "violets are blue";
  print_backwards(s);
  return 0;
}
