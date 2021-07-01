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
