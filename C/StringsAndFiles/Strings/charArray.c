#include <stdio.h>

int main() {
  // pretty inconvenient and impractical for longer text
  // also can't store words of different lengths
  char text[5];
  text[0] = 'h';
  text[1] = 'e';
  text[2] = 'l';
  text[3] = 'l';
  text[4] = 'o';

  for (int i = 0; i < 5; i++) {
    printf("%c", text[i]);
  }
  printf("\n");

  return 0;
}
