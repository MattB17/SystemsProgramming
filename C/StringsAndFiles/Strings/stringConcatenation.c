#include <stdio.h>
#include <string.h>

int main() {
  char s1[30];
  char s2[14] = "University of";
  char s3[15] = " C Programming";
  strcpy(s1, s2);
  strcat(s1, s3);
  printf("%s\n", s1);

  // safe version
  char t1[30];
  char t2[14] = "University of";
  char t3[15] = " C Programming";
  strcpy(t1, t2);
  // -1 to make room for null terminator
  strncat(s1, s3, sizeof(s1) - strlen(s1) - 1);
  printf("%s\n", s1);
  return 0;
}
