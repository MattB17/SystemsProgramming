#include <stdio.h>

int main() {
  int x, y, z;
  x = (4 < 5); // assigned 1
  y = (5 < 4); // assigned 0
  z = ((2 < 3) || (5 < 4)); // assigned 1
  printf("x: %d. y: %d. z: %d\n", x, y, z);

  // every numeric value except 0 is true
  // so "second" and "third" are printed
  if (0) {
    printf("first\n");
  }
  if (1) {
    printf("second\n");
  }
  if (2) {
    printf("third\n");
  }

  return 0;
}
