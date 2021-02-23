#include <stdio.h>

int main() {
  // you can't change the size of an array
  // contiguous chunk of memory
  // address of A[1] = address of A + (1 * sizeof(int))
  int A[3] = {13, 55, 20};

  // accesses 3rd array element
  int in_bounds = A[2];
  // accesses garbage
  int out_of_bounds = A[4];

  return 0;
}
