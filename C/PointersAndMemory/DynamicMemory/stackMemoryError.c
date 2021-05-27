#include <stdio.h>

int *set_i() {
  int i = 5;
  return &i;


int some_other_function() {
  int junk = 999;
  return junk;
}

int main() {
  int *pt = set_i();
  // now the value of pt is 999
  // i is declared as a variable within set_i and is only available within
  // set_i, memory is allocated on the stack for i
  // when set_i is finished the memory is freed and can be reallocated
  // some_other_function uses the same space in the stack and allocates the
  // variable junk, which is at the address i was at
  printf("Access i via *pt and we get %d\n", *pt);
  return 0;
}
