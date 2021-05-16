#include <stdio.h>

void apply_late_penalty(char *grade_ptr) {
  if (*grade_ptr != 'F') {
    // dereference to get value, then increment
    (*grade_ptr)++;
  }
}

int main() {
  char grade_Michelle = 'B';
  printf("Michelle earned a %c\n", grade_Michelle);
  apply_late_penalty(&grade_Michelle);
  printf("Michelle was late, so instead she gets a %c\n", grade_Michelle);

  char grade_Felipe = 'A';
  printf("Felipe earned a %c\n", grade_Felipe);
  apply_late_penalty(&grade_Felipe);
  printf("Felipe was also late and earns a %c\n", grade_Felipe);

  return 0;
}
