#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>

#define INTSIZE 32
#define N 4

struct bits {
  unsigned int field[N];
}

typedef struct bits Bitarray;

int setzero(Bitarray *b) {
  return (memset(b, 0, sizeof(Bitarray)) == NULL);
}

void set(unsigned int value, Bitarray *b) {
  int index = value / INTSIZE; // integer division
  b->field[index] |= 1 << (value % INTSIZE);
}

void unset(unsigned int value, Bitarray *b) {
  int index = value / INTSIZE; // integer division
  b->field[index] &= ~(1 << (value % INTSIZE));
}

int isset(unsigned int value, Bitarray *b) {
  int index = value / INTSIZE;
  return (1 << (value % INTSIZE) & b->field[index]);
}

int main() {
  Bitarray a1;
  setzero(&a1);

  // Add 1, 16, 32, 65 to the set
  set(1, &a1);
  set(16, &a1);
  set(32, &a1);
  set(68, &a1);

  // Print using hexidecimal
  printf("%x %x %x %x\n",
         a1.field[0], a1.field[1], a1.field[2], a1.field[3]);

  unset(68, &a1);

  // print using hexidecimal
  printf("%x %x %x %x\n",
         a1.field[0], a1.field[1], a1.field[2], a1.field[3]);

  return 0;
}
