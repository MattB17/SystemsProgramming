### Command Line Arguments

```
#include <stdio.h>

int main(int argc, char **argv) {
  return 0;
}
```

`int argc` specifies the number of command line arguments
`char **argv` is an array of strings representing the command line arguments

If we assign a variable outside of main then it is a global variable that exists everywhere
* we can't store global variables in the stack because the stack only contains local variables that have been defined for a certain function
* global variables are stored in their own global variable segment - right below the code segment
* the global data segment holds other values such as string literals

### Strings
A character array is an array with a null character after the final string of text
* ['h', 'e', 'l', 'l', 'o', '\0']
* so string is just a character array with a null terminator
