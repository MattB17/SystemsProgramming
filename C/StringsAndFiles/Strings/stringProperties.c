# include <stdio.h>
# include <string.h>

int main() {
  char weekday[10] = "Monday";
  // this gives 10 - the number of elements in the array
  printf("Size of string: %lu\n", sizeof(weekday));

  char s1[10] = "Mon";
  char s2[10] = "day";

  // this does not work - it just adds two pointers
  // char s3[20];
  // s3 = s1 + s2;

  // correct way to get string length
  printf("Length of string: %lu\n", strlen(weekday));

  return 0;
}
