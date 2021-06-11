#include <stdio.h>

int main() {
  char text[20];
  text[0] = 'h';
  text[1] = 'e';
  text[2] = 'l';
  text[3] = 'l';
  text[4] = 'o';
  // this line makes text a string rather than a char array
  // and the other entries are ignored
  text[5] = '\0';

  printf("%s", text);
  printf("\n");

  return 0;
}
