#include <stdio.h>

int main() {
  int i = 5;
  printf("Value of i: %d\n", i);
  printf("Address of i: %p\n", &i);

  // declare pointer variable
  int *pt;
  pt = &i;

  printf("Value of pt: %p\n", pt);
  printf("Address of pt: %p\n", &pt);

  printf("Value pointed to by pt: %d\n", *pt);

  // character pointer
  char ch = 'y';
  char *ch_pt;
  ch_pt = &ch;
  printf("ch_pt points to %c\n", *ch_pt);
  
  return 0;
}
