### Stack and Heap
* Function calls are allocated on the stack
* By default, variables are allocated on the stack
  * we shouldn't access variables on the stack after they have been deallocated
* heap space retains variables
  * it is retained until the programmer explicitly deallocates
  * the function `void *malloc(size_t size);` allocates memory on the heap
  * `size` is the number of bytes
  * returns address of memory allocated on the heap
  * malloc returns a void pointer (generic type) because it doesn't need to know how the memory will be used
  * when we store the returned value in a pointer, the pointer specifies how the memory will be used
    * `int *i_pt = malloc(sizeof(int));`

### Command Line Arguments

```
#include <stdio.h>

int main(int argc, char **argv) {
  return 0;
}
```

`int argc` specifies the number of command line arguments
`char **argv` is an array of strings representing the command line arguments
