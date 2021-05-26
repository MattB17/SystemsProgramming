#include <stdio.h>

int main() {
  int i = 5;
  int j = 10;

  // k is 0
  int k = i / j;
  printf("int k is %d\n", k);

  // here k is truncated to 0
  double half = 0.5;
  k = half;
  printf("int k is %d\n", k);

  // d is also 0
  // i and j are ints and i / j has a value and type
  // an int divided by an int is an int which is 0
  double d = i / j;
  printf("double d is %f\n", d);

  // cast i to a double then divide so d is 0.5
  d = (double) i / j;
  printf("double d is %f\n", d);

  return 0;
}
