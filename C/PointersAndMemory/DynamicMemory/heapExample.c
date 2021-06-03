#include <stdio.h>
#include <stdlib.h>

int *squares(int max_val) {
  // allocates on the heap so will still be available after the function
  // returns
  int *result = malloc(max_val * sizeof(int));
  for (int i = 1; i <= 10; i++) {
    result[i-1] = i * i;
  }
  return result;
}

// program that has an array holding the squares of the integers between
// 1 and 10, inclusive
int main() {
  // the left hand side allocates space for one int on the stack
  // but does not allocate the array, we need to do this in the function.
  int *squares_to_10 = squares(10);

  for (int i = 0; i < 10; i++) {
    printf("%d\t", squares_to_10[i]);
  }
  printf("\n");

  return 0;
}
