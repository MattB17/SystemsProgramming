#include <stdio.h>

int main() {
  int i = 81;
  int *pt = &i;

  // pointer to a pointer
  int **q = &pt;
  // r is a pointer to int
  int *r = *q;
  // k is an int
  int k = **q;

  // pointer to pointer to pointer to int
  int ***s = &q;
  int t = ***s;

  return 0;
}
