#include <stdio.h>

void change(int *A) {
  A[0] = 50;
}

int main() {
  int scores[4];
  scores[0] = 4;
  // changes the 0th element to 50
  change(scores);
  printf("First element in array has value %d\n", scores[0]);

  return 0;
}
