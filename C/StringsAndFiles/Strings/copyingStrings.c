#include <stdio.h>
#include <string.h>

int main() {
  char s1[40];
  char s2[14] = "University of";
  strcpy(s1, s2);
  printf("%s\n", s1);
  printf("%s\n", s2);

  // safer strncpy
  char t1[5];
  char t2[32] = "University of";
  strncpy(t1, t2, sizeof(t1));
  t1[4] = '\0';
  printf("%s\n", t1);
  printf("%s\n", t2);

  return 0;
}
