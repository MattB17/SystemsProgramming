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
