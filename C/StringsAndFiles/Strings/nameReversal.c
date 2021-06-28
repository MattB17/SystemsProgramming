// creates a function `reverse_name` that takes two parameters, `src` and
// `dest`. `src` has the format `firstname lastname` and `reverse_name`
// writes `lastname firstname` to `dest`

#include <stdio.h>
#include <string.h>

void reverse_name(char *src, char *dest) {
  char *space_ptr;
  space_ptr = strchr(src, ' ');
  strcpy(dest, (space_ptr + 1));

  int idx = strlen(dest);
  dest[idx] = ' ';
  idx++;

  int firstname_len = strlen(src) - idx;
  strncpy((dest + idx), src, firstname_len);
  idx += firstname_len;
  dest[idx] = '\0';
}

int main() {
  char source[] = "John Smith";
  char destination[strlen(source) + 1];
  reverse_name(source, destination);
  printf("%s\n", destination);

  return 0;
}
