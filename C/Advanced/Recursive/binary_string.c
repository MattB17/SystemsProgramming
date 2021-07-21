// binary string problem
// create all binary strings
// of length n only consisting of 0s and 1s

// generate all strings of length n + 1 by adding a 0
// to every string of length n and by adding a 1 to every
// string of length n
#include <stdio.h>

#define N 4

void binstrs(char bits[], int index) {
  if (index == N) {
    printf("%s\n", bits);
    return;
  }

  bits[index] = '0';
  binstrs(bits, index + 1);

  bits[index] = '1';
  binstrs(bits, index + 1)
}

int main() {
  char binary_num[N + 1];
  binary_num[N] = '\0';

  binstrs(binary_num, 0);
  return 0;
}
