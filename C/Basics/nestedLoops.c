#include <stdio.h>

int main() {
  printf("Printing a multiplication table\n");
  printf("-------------------------------\n");
  for (int row = 1; row <= 10; row++) {
    for (int col = 1; col <= 10; col++) {
      printf("%d\t", row * col);
    }
    printf("\n");
  }

  return 0;
}
