#include <stdio.h>

int main() {
  if (3 < 0) {
    printf("I'm happy!\n");
  } else {
    printf("I'm sad!\n");
  }
  printf("I'm done sharing my feelings.\n");

  int x = 10;
  if (x >= 5) {
    x = 2;
    x = x - 1;
  } else {
    x = 20;
  }

  return 0;
}
