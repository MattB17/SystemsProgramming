#include <stdio.h>

#define GREATER(a, b) ((a) > (b) ? (a) : (b))

// you could instead use a function
// static inline int GREATER(int a, int b) {
//    return a > b ? a : b;
// }

// macros are faster than normal functions, but inline functions are the same

int main() {
  int x = 2;
  int y = 1;

  // this sets y to 3 (because everywhere that b is is replaced by ++y,
  // so y gets incremented twice)
  printf("%d\n", GREATER(x, ++y));

  return 0;
}
