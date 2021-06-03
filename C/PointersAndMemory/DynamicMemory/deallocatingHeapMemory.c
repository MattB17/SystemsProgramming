#include <stdio.h>
#include <stdlib.h>

int play_with_memory() {
  // declared on stack
  int i;
  // declared on heap
  int *pt = malloc(sizeof(int));

  i = 15;
  *pt = 49;

  // free just deallocates it, it doesn't actually change what is in that
  // memory location
  // but at any future time that space could be used for something else and
  // so the pointer should not be used after calling free
  free(pt);

  return 0;
}

int main() {
  play_with_memory();
  return 0;
}
