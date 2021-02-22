#include <stdio.h>

#define SIZE 5

int main() {
  int sum = 0;
  int curr_int;

  do {
    printf("Enter an integer: ");
    scanf("%d", &curr_int);
    if (curr_int <= 0) {
      break;
    }
    sum += curr_int;
  } while (1); // infinite loop

  printf("The total is %d\n", sum);

  int i, j;

  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (i == j) {
        printf(" ");
        continue;
      }
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
