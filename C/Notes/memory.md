# Memory

### Stack and Heap
Function calls are allocated on the stack
* By default, variables are allocated on the stack
  * we shouldn't access variables on the stack after they have been deallocated

Heap space retains variables
  * it is retained until the programmer explicitly deallocates
  * the function `void *malloc(size_t size);` allocates memory on the heap
  * `size` is the number of bytes
  * returns address of memory allocated on the heap
  * malloc returns a void pointer (generic type) because it doesn't need to know how the memory will be used
  * when we store the returned value in a pointer, the pointer specifies how the memory will be used
    * `int *i_pt = malloc(sizeof(int));`
  * free memory with `free`
    * `void free(void *ptr);`
    * ptr is a single pointer to a memory address that was previously allocated with malloc

### Memory Layout
`Buffer` - `Code` - `Global Data` - `Heap` - `Stack` - `OS`

When code is compiled, it is stored in the code segment

Functions are popped onto the stack

Local variables and arguments also go onto the stack
* stack frame allocated for local variables and is above the stack frame for its function
* top frame in the stack is always for the function that is currently being executed

`malloc` allows us to allocate memory while the program runs
* all dynamically allocated memory is stored right below the global segment - in the heap
* as we continue to `malloc`, the heap builds up
* when we `free` a piece of memory, it is marked as free for allocation
  * and future `malloc` calls can allocate all or some of the freed memory

The stack grows up and the heap grows down
* with both having a maximum size
* if your program exceeds the maximum size of the stack or the heap, your program will experience an out of memory error (ENOMEM)
* other segments (like a file buffer segment) may be created between the stack and heap

Below the stack, the OS reserves the largest addresses in memory for its own use
* these OS segments cannot be accessed by normal programs
* if you do try to access OS memory you will get a segmentation fault
* segfaults occur when we try to access something we don't have access to or try to access something that doesn't exist
