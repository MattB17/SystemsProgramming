#include <stdio.h>

int main() {
  int i = 77;
  // the address of i
  int *ptr = &i;
  int *s;
  // the next address after i
  s = ptr + 1;

  int A[3] = {13, 55, 20};
  // points to the start of A
  int *p = A;
  // prints first element
  printf("%d\n", *p);
  // prints second element
  printf("%d\n", *(p + 1));
  // prints first element
  printf("%d\n", p[0]);
  // prints second element
  printf("%d\n", p[1]);

  // address of A[i] = (address of A) + (i * size of one element of A)

  // points to second element of A
  p = p + 1;
  // prints second element
  printf("%d\n", *p);
  // prints second element
  printf("%d\n", p[0]);
  // prints third element
  printf("%d\n", p[1]);
  // prints first element
  printf("%d\n", *(p - 1));

  return 0;
}
