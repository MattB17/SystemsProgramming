#include <stdio.h>

int main() {
  int i = 7;

  // j's initial value is 7
  int j = i;

  int *pt;
  pt = &i;
  *pt = 9;

  // value of i will now be 9, we changed the value pointed to by
  // pt and pt points to the address of i
  // j is a different address, so it does not change
  printf("Value of i: %d\n", i);

  *pt = *pt + 1;
  printf("pt points to %d\n", *pt);

  return 0;
}
