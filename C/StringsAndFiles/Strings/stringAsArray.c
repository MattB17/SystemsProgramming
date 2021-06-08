#include <stdio.h>

int main() {
  char text[20];
  text[0] = 'h';
  text[1] = 'e';
  text[2] = 'l';
  text[3] = 'l';
  text[4] = 'o';
  text[5] = '\0';

  printf("%s", text);
  printf("\n");

  return 0;
}
