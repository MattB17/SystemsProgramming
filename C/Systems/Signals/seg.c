// deliberately dereferences a null ptr for a segmentation fault
#include <stdio.h>

int main() {
  int *ptr = NULL;
  *ptr = 3; // this line is bad
  printf("Value at ptr is %d\n", *ptr);
  return 0;
}
