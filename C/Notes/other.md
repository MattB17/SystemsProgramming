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

### Streams
When using `scanf` we are actually reading from a stream called standard input
* the default location of standard input is the keyboard
* this stream's name is `stdin`

When using `printf` the data is actually written to standard output
* the default location is the screen
* this stream's name is `stdout`

Errors use the standard error stream
* it's default location is also the screen
* this stream's name is `stderr`

You can change the location of output for any stream

In general we have a program that accepts input streams and produces output streams

Streams can refer to more than just the screen or keyboard
* they can also refer to files, devices, or networks
* we can also open our own streams

Suppose a compiled program `a.out` reads a number from the keyboard
* `./a.out` will hang waiting for a user to input a number and then execute
* now suppose `number.txt` contains a single number
  * we can redirect the number to our program with `./a.out < number.txt`

Suppose a compiled program `a.out` prints text to the screen
* `./a.out` will print the text to the screen
* `./a.out > result.txt` redirects the output to a text file called `result.txt`

Input and output redirection are not C features
* they are features of the operating system

Expected results should go to standard output and error messages should go to standard error

### Files
`FILE *fopen(const char *filename, const char *mode)`
* opens a file and makes it available as a stream
* `filename` is the name of the file we want to open
* `mode` describes how we want to use the file
  * `"r"` - file opened for reading
  * `"w"` - file opened for writing
  * `"a"` - file opened for appending
* returns a file pointer that can be used when we want to read from the file or write to the file
* `fopen` could fail because the file does not exist or we might not have the proper permissions to open the file
  * if `fopen` fails then it returns `NULL` rather than a valid file pointer

`int fclose(FILE *stream)`
* closes the file pointed to by `stream`
* if it returns 0 then the close was successful, otherwise it failed
* f close could fail if called with an invalid file pointer

`char *fgets(char *s, int n, FILE *stream)`
* `s` is a pointer to memory where text can be stored
  * on success, `fgets` returns `s`
  * it signals an error by returning `NULL`
* `n` is the maximum number of characters that `fgets` is allowed to put in `s`
  * including a null character at the end of the string
* `stream` is the source of the data
* always reads at most `n-1` characters from `stream`
  * and stops reading when it reaches the end of a line in `stream`
* `fgets` can also read from standard input and is sometimes better than `scanf` because it reads until a newline
  * `scanf` reads until a space

`scanf` is forced to read from standard input
* `fscanf` can read from any input stream

`int fscanf(FILE *stream, const char *format, ...)`
* `stream` is the stream from which to read
* it returns the number of items successfully read

When a program writes to a stream it is written to a file buffer controlled by the operating system
* this is periodically written to the file on disk

`int fflush(FILE *stream)`
* requests that the operating system write any changes that are in its buffer

### Structs
Structs are used to aggregate data when the data are not necessarily all the same type
* like arrays but with different types

When arrays are passed to functions, a pointer to the first element in the array is passed
* so if the function modifies the array, the original array will be modified

For structs, a function gets a copy of the struct
* the function gets a copy of the entire struct (including any arrays)

C is allowed to insert spaces between members of a struct
* this is because it may lead to a more favourable layout which makes accesses faster

### Binary Files
To open a binary file
* `output_file = fopen("testing.dat", "rb")`

Writing to a binary file
* `size_t fwrite(const void *ptr, size_t size, size_t nmembm FILE *stream);`
* `ptr` is a pointer to the data we want to write to the file
  * typically a pointer to an array or a pointer to an individual variable
* `size` is the size of each element we are writing to the file
* `nmemb` is the number of elements we are writing to the file
* `stream` is the file pointer to which we will write
* `fwrite` returns the number of elements successfully written to the file or 0 on error

Reading from a binary file
* `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);`
* `ptr` is a pointer to the memory where the data from the file will be stored
* `size` is the size of one element
* `nmemb` is the number of elements to read
* `stream` is the stream to read from
* `fread` returns the number of elements successfully read from the file
  * returns 0 if no elements are read, signaling an error or that the end of the file has been reached

##### wav Files

`wav` files are a binary file for sound
* a `wav` file has 2 parts
  * the header which is 44 bytes of data
    * it contains information about the file including parameters required to play the file in a music program
  * after the header comes 1 or more 2-byte values
    * each 2-byte value is called a sample
    * when a `wav` file is created the audio signal is sampled many thousands of times per second
    * each of these samples is stored as one of these 2-byte integers

`od` is a linux utility that prints out values found in a binary file
* `od -A d -j 44 -t d2 short.wav`
  * `-A d` translates from the default base 8 to base 10
  * `-j 44` signifies to skip the first 44 bytes of the file - because the header occupies those 44 bytes
  * `-t d2` means the file consists of 2 byte values
  * `short.wav` is the file name

`int fseek(FILE *stream, long int offset, int whence);`
* every file maintains a pointer to where it is in the file
* `fseek` allows us to move this pointer around in the file
* `stream` is the stream whose position we want to change
* `offset` is a byte count, specifying how much the file position should change
* `whence` determines how `offset` is interpreted
  * `SEEK_SET` is from the beginning of the file
  * `SEEK_CUR` is from the current file position
  * `SEEK_END` is from the end of the file
* `fseek(my_file, -10, SEEK_CUR)` moves the pointer 10 bytes back from the current position
* move to the beginning of a file with `fseek(my_file, 0, SEEK_SET);`

`void rewind(FILE *stream);` moves to the beginning of `stream`

### Aliases
`typedef` allows you to define an alias for a type
* it is evaluated at compile time
* you're providing a new name for an existing type

macros allows you to define a keyword that is replaced by a specified string when your program is processed before being compiled
* a macro is like a function but it happens before compilation so it is much more efficient

### Bitwise Operations
0 is False and 1 is True

```
int page_flag = 0;
page_flag |= 1 << 3;
```
This sets the 3rd bit of `page_flag` to `1`. So now `page_flag` is `1000` which is 8

```
int page_flag = 9;
page_flag &= ~(1 << 0);
```
This clears the 0th bit of `page_flag`. So now `page_flag` is `1000` which is 8

Logical operators
* `1 && 1 = 1`
* `1 && 0 = 0`
* `0 && 1 = 0`
* `0 && 0 = 0`
* logical operator looks at both arguments and returns 1 if both arguments have a value other than 0
  * `8 && 8 = 1`
  * `8 && 1 = 1`
  * `8 && 0 = 0`

Bit operators
* `1 & 1 = 1`
* `1 & 0 = 0`
* `0 & 1 = 0`
* `0 & 0 = 0`
* performs the `&` operator on each pair of bits
  * `8 & 8 = 1`
  * `8 & 1 = 0`
  * `8 & 0 = 0`

Bitwise exclusive or (XOR)
* `1 ^ 1 = 0`
* `1 ^ 0 = 1`
* `0 ^ 1 = 1`
* `0 ^ 0 = 0`

Bitwise Negation
* `~0 = 1`
* `~1 = 0`
* flips every bit in the variable

Bitwise Shifts
* `<<` shift left
* `>>` shift right

`1 << 3` shifts 1 3 positions
* so `0001` -> `0010` -> `0100` -> `1000` which gives 8

Flag bits are commonly used when a single variable is used to transmit data about multiple options
* that variable is an array of bits in which each bit represents an option with 1 being the option is on

### Enum
```
enum page_flags {
  PAGE_PRESENT,
  PAGE_PROT,
  PAGE_RW,
  PAGE_USER,
  PAGE_DIRTY,
  PAGE_ACCESSED
};
```
* `PAGE_PRESENT` is automatically associated with 0

### Linked Structures
A linked structure uses pointers to increase the number of items in the structure as needed

|       | Array | Linked Structure |
|:-----:|:-----:|:----------------:|
| Implementation | built into C language | user-defined |
| Access and Storage | use indices to fetch and store | requires a "traverse" function to go over elements in the structure |
| Size | fixed size | dynamic size |

Linked List Node
```
struct node {
  int value;
  struct node *next;
};
```

Linked list nodes are usually scattered throughout memory as they are allocated on the heap

Array cells are allocated next to each other
* `arr[i]` is translated to `*(arr + i)`

### File Permissions in Linux
Each file has an owner and a group

`ls -l` prints output like
* `-rw-r--r-- 1 mbuckley instrs 302 Jul 29 14:39 ptr.c`
  * the first part is permissions representing who can read, write, or execute the file
  * the third column `mbuckley` is the owner of the file
  * the fourth column is the group
* the owner and group fields are relevant to permissions because Linux allows us to set separate permissions for the owner of the file, the group, and every other user

Consider file permission string `-rwxr-xr-x`
* the first `-` is the file type
  * this represents a regular file
  * `d` would represent a directory
  * `l` would represent a link
* the next 3 `rwx` means the owner has read, write and execute permissions on the file
* the next 3 `r-x` means the group has read and execute permissions on the file but cannot write
* the last 3 `r-x` means all other users have read and execute permissions on the file but cannot write

Ignoring the initial file type in permissions
* all other permissions are on/off switches which can be represented as a bit
* you need 9 bits to represent the 9 permissions
* syscalls that operate on permissions use a `mode_t` type
* ie `r--r--r--` would be represented as `100100100`

One syscall that operates on file permissions is `chmod`
* `chmod` is used to change file modes or Access Control Lists
* chmod values are done in octal
