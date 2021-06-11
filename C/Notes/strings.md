# Strings

Strings are arrays of chars
* `char *s = "hello world";`

Converting a string to long
* `long int strtol(const char *str, char **endptr, int base);`
* `str` is the string we want to convert
* `endptr` is a pointer to pointer to char pointing to leftover that we don't want to convert
  * `char *s = "   -17 other junk."`
  * `char *leftover;`
  * `int i = strtol(s, &leftover, 10);` gives -17
* `base` is the base of the number system we want to convert to
  * `10` for decimal
  * `2` for binary
* can also handle leading spaces and minus sign
  * `char *s = "    -17";`
  * `int i = strtol(s, NULL, 10)` gives -17

* `size_t strlen(const char *s)`
  * gets length of string pointed to by `s`, not including null terminator
  * `size_t` is an unsigned integer

* `char *strcpy(char *s1, const char *s2);`
  * copies characters from string `s2` into the beginning of array `s1`
  * `s1` is not required to be a string when `strcpy` is called
  * `s2` is required to be a string when `strcpy` is called
    * that is, it must a string literal or a char array with a null terminator

`strcpy` is unsafe - consider the following example

```
#include <stdio.h>
#include <stdlib.h>

int main() {
  char s1[5];
  char s2[32] = "University of";
  strcpy(s1, s2);
  printf("%s\n", s1);
  printf("%s\n", s2);
  return 0;
}
```

The `strcpy` call has undefined behaviour
* it may raise an error
* or appear to work fine

* `char *strncpy(char *s1, const char *s2, int n);` is a safer version of `strcpy`
  * copies characters from string `s2` into the beginning of array `s1`
  * `n` indicates the maximum number of characters that `s1` can hold

* `char *strcat(char *s1, const char *s2);`
  * adds the characters from `s2` to the end of string `s1`
  * both `s1` and `s2` must be strings prior to calling `strcat`
  * `strcat` is also unsafe
    * `s1` may not have enough space to store its contents plus `s2`s contents

* `char *strncat(char *s1, const char *s2, int n);`
  * safe version of `strcat`
  * `n` is the maximum number of characters, not including the null terminator, that should be copied from `s2` to the end of `s1`
  * it always adds a null terminator to `s1`
