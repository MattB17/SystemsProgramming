#include <stdio.h>
#include <string.h>

int main() {
  char s1[30] = "University of C Programming";

  char *p;
  p = strchr(s1, 'v');
  if (p == NULL) {
    printf("Character not found\n");
  } else {
    // if not null it points to that character
    // s1 is the start of the string and p is the pointer to the character
    // so p - s1 gives the index of the character in the string
    printf("Character found at index %d\n", p - s1);
  }

  char *p2;
  p2 = strstr(s1, "sity");
  if (p2 == NULL) {
    printf("Substring not found\n");
  } else {
    printf("Substring found starting at index %d\n", p2 - s1);
  }

  return 0;
}
