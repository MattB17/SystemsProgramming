#include <stdio.h>

int main() {
  // uninitialized pointer (so it points to 0)
  // address 0 or anything close to 0 is used as a buffer for failure
  int *p = NULL;
  p[0] = 'a';
  return 0;
}
