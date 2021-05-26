#include <stdio.h>
#include <limits.h>

int main() {
  int i = 17;
  double d = 4.8;

  // d is truncated and i gets the value 4
  // d could be too large, then i is garbage
  i = d;

  // the double version of i
  // but uses more space
  d = i;

  printf("i is %d\n", i);
  printf("d is %f\n", d);

  printf("An integer is stored using %lu bytes\n", sizeof(i));
  printf("A double is stored using %lu bytes\n", sizeof(d));

  float f;
  printf("A float is stored using %lu bytes\n", sizeof(f));

  // float and int are both 4 bytes, so not all integers can be represented as floats
  i = INT_MAX;
  f = i;

  // char is 1 byte
  char ch = 'A';
  printf("char ch: displayed as char %c, displayed as int %d\n", ch, ch);

  // an int can hold any char "an int is wider than a char"
  int j = ch;
  printf("j is %c, int %d\n", j, j);

  // but char cannot hold all integers
  i = 320;
  ch = i;
  printf("char ch: displayed as char %c, displayed as int %d\n", ch, ch);
}
