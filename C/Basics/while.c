#include <stdio.h>

int main() {
  int i = 0;

  while (i < 5) {
    printf("%d\n", i);
    i++;
  }

  int sum = 0;
  int curr_int;

  do {
    printf("Enter an integer: ");
    scanf("%d", &curr_int);
  } while (curr_int != 0);

  printf("The total is %d\n", sum);

  return 0;
}
