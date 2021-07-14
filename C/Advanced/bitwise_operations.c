#include <stdio.h>

int main() {
  int val = 1;
  printf("val: %d\n", val);
  // sets the third bit of `val` to `1`
  val |= 1 << 3; // now `val` is `1001`
  printf("val: %d\n", val);
  // sets the 0th bit of `val` to `0`
  val &= ~(1 << 0); // now `val` is `1000`
  printf("val: %d\n", val);

  return 0;
}
