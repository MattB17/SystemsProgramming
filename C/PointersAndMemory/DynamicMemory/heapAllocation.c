#include <stdio.h>
#include <stdlib.h>

int *set_i() {
  int *i_pt = malloc(sizeof(int));
  *i_pt = 5;
  return i_pt;
}

int some_other_function() {
  int junk = 999;
  return junk;
}

int main() {
  int *pt = set_i();
  printf("Access i via *pt and we get %d\n", *pt);
  return 0;
}
