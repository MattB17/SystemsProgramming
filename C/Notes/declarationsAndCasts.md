# Declarations and Casts

### Declaration Mimics Use
Declaration for an array of 10 pointers to functions returning int
* `int (*f[10])();`
* can also be used to access the int from calling the function

An array of 10 pointers to int
* `int *f[10];`

### Casts
Write a declaration, remove the variable, and put parantheses around the whole thing
* `int x;` -> `(int)`
* `char *p;` -> `(char *)`
* `char **p;` -> `(char **)`
* `char *(*p)()` -> `(char *(*)())`
  * this is a pointer to a function which returns a pointer to a char

### Assignment vs Declaration
To declare a pointer to an integer
* `int *p;`
* here `*` makes this into the declaration of a pointer to int rather than of an int

Assign `x` the value pointed to by `p`
* `x = *p;`
* here `*` is an operator which follows the pointer to get the actual value
* it dereferences the pointer value
