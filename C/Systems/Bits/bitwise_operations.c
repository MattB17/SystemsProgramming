#include <stdio.h>

int main() {
  // bit representation - 0x13 in hexadecimal
  char a = 0b00010011;
  // hexadecimal representation - 00010100 in binary
  unsigned char b = 0x14;

  printf("Result of negating %x is %x in hex\n", a, ~a);

  printf("Result of bitwise and of %x and %x is %x in hex\n", a, b, a & b);

  printf("Result of bitwise or of %x and %x is %x in hex\n", a, b, a | b);

  printf("Result of bitwise xor of %x and %x is %x in hex\n", a, b, a ^ b);

  return 0;
}
