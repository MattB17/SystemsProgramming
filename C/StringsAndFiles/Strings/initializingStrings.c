#include <stdio.h>

int main() {
  // with an array initializer
  // all characters after the text are set to the null character
  char text[20] = {'h', 'e', 'l', 'l', 'o', '\0'};

  printf("%s\n", text);

  // initialization method 2, all other elements are null characters
  // if the string fits exactly, there are no null terminators
  // ie. text[5] = "hello" would not have a null terminator
  char other_text[20] = "hello";

  // can change elements of the string
  text[0] = 'j';

  printf("%s\n", other_text);

  // can also initialize without specifying size
  // compiler assigns array with enough space for all characters plus one
  // more array element for the null terminator
  // however array size does not change, once initialized it is fixed
  char another_text[] = "hello";

  printf("%s\n", another_text);

  // last_text is a pointer not an array
  // "hello" is a string literal - a string constant that can't be changed
  // last_text points to the first character of that string
  char *last_text  = "hello";

  // you cannot change a string constant
  // this is not allowed `last_text[0] = 'j';`

  printf("%s\n", last_text);
  return 0;
}
