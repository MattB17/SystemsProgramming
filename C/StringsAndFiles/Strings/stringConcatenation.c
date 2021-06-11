#include <stdio.h>
#include <string.h>

int main() {
  char s1[30];
  char s2[14] = "University of";
  char s3[15] = " C Programming";
  strcpy(s1, s2);
  strcat(s1, s3);
  printf("%s\n", s1);
  return 0;
}
