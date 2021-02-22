#include <stdio.h>

int main() {
  int rows;

  printf("Enter the number of rows for the triangle: ");
  scanf("%d", &rows);

  for (int row = 1; row <= rows; row++) {
    for (int col = 0; col < row; col++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
