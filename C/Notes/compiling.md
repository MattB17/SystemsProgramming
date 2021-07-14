# Compiling
To compile a program called `helloWorld.c` with all warnings using gcc:
* `$gcc -Wall helloWorld.c`
* outputs a file called `a.out` in same directory
* To run the file -> `$./a.out`

If you want to specify a name for the compiled file use `-o`
* `$gcc -Wall -o helloWorld.out helloWorld.c`
* Then to run the program -> `$./helloWorld.out`

### Compiler Toolchain
The compiler toolchain is the set of applications that let you transform source code into a running program

`source code (.c)` -> compile -> `executable (.out)` -> run -> `executing program`

`gcc` has to work on many computers running different languages

A compiler is any program that translates code in one language to a different language
* typically we think of compilers as accepting input in a high level language like `C` and producing output in a lower level language like `Assembly`

`$gcc -S helloworld.c`
* produces a program `helloworld.s` in assembly

Compiling process
`Source Program` -> `Lexical Analysis` -> `Syntax Analysis` -> `Semantic Analysis` -> `Code Generation` -> `Executable Program`

The compiler runs in 3 phases
* the first phase is a front-end that translates the source code to a largely language independent intermediate representation
  * this stage consists of the Lexical Analysis and Syntax Analysis
  * `gcc` translates into two languages `gimpl` and `generic`
  * these can be though of as Abstract Syntax Trees
* the second phase is the middle end in which the compiler optimizes your code
  * the compiler looks for ways to make it run faster
  * this consists of semantic analysis
* the third phase is a backend that translates the intermediate language into an assembly language of the computer that will run the program
  * this is the code generation step

This only creates assembly code
* we need to assemble the assembly code into executable code
* this is job of the assembler

`source doe (.c)` -> compile -> `assembly (.s)` -> assemble -> `executable (.out)` -> run -> `executing program`

Can assemble the assembly file with `as`
* `$as helloword.s -o helloworld.o`
* this creates `helloworld.o` as an object rather than as an executable

The final step in the compilation process is called linking
* the linker takes one or more compiled and assembled files and combines them to create a file that is in the executable format

`source code (.c)` -> compile -> `assembly (.s)` -> assemble -> `object file (.o)` -> link -> `executable (.out)` -> run -> `executing program`

The final executable file is a package that contains all of the instructions in the program in addition to a data section containing items like constant strings and links to dynamic libraries
* the libraries contains the object code that implements functions
* this executable is not portable - you can't copy it to another machine and know that it will run

Everything from the assembly code to the object code to the executable is produced for a specific kind of machine
* the executable is specific to not only the machine but also the operating system and system configuration

The executable needs to be loaded into memory when you execute it
* that's the job of the loader
* the loader is operating system specific

Before compiling we need a preprocessor to prepare the source code for the front-end
* the preprocessor adds function prototypes for library and system calls required by the program
* it also interprets preprocessor directives like macros

### Header Files
We can combine multiple files at once as `$gcc compare_sorts.c sorts.c`
* this produces one executable `a.out`
* but the problem is if one file changes we have to compile and assemble everything again which could take a really long time

When multiple files are required, each file is compiled and assembled separately
* then they are combined together in the linking stage
* `$gcc -c compare_sorts.c` and `$gcc -c sorts.c` to compile and assemble both files
* then `gcc compare_sorts.o sorts.o` to get one executable
* now if one of them changes we can just rebuild the `.o` file for that file and relink them all
* but still there is no checking between programs
  * ie) maybe `sorts.c` has sorting functions that take `long` but in `compare_sorts.c` they are passed in as `int`

A header file is an example of an interface
* a header should declare what functions do and what types they require without defining how they are actually implemented

If you add variables in a `.h` file and compile separately then the variables are being duplicated in each object file
* instead declare the variables in the header with the `extern` keyword, but assign in the file
* `extern const int NUM_SORTS;`
* `extern sort_info SORTS[];`

If you want the same variable in multiple files you use the `static` keyword
* `static int x = 0;`
* without static if you have the same statement in multiple files at the linking stage you will get an error that the variable is defined multiple times
* `static` makes a global variable local - it is only available in the file in which it is defined
* if `static` is used for a variable inside a function then that function retains its value across function calls
* for example, consider the function
```
void function_example() {
  static int x = 3;
  printf("%d\n", x);
  x = x + 2;
}
```
* when `function_example` is called the first time it prints `3`, the second time it prints `5` and so on

You can create a define guard in the header to ensure that
the header file is only defined once
```
#ifndef SORTS_H
#define SORTS_H

<header file stuff>

#endif
```

A multiply included header will generate errors

Compiler toolchain includes a tool `make` to track dependencies and determine which files need to be recompiled

makefiles are composed of a sequence of rules
* each rule has a target - the file to be constructed
* each rule also has a recipe - a command or list of commands to execute to create the target
* if dependencies or pre-requisites are present the recipe is executed if one or more of the dependencies is newer than the target
* if there are no dependencies, the recipe is only executed if the target doesn't exist
```
target: dependencies ...
  recipe
```
* the white space before the `recipe` is a tab, not just spaces

When you run the command `make` it looks for a `Makefile` in the local directory and executes the rules it contains

example rule
```
compare_sorts: compare_sorts.c sorts.c
  gcc compare_sorts.c sorts.c -o compare_sorts
```

with make if a dependency is also a target in the makefile it will execute that rule first

### C Preprocessor
Any line that begin with a `#` is a preprocessor directive
* preprocessor directives are used to modify C source code before it is compiled

The preprocessor is useful for changing how your program based on conditions at the time that the program is compiled

Examples:
* `ex1.c`
```
#define MY_INT (42)

int x = MY_INT;
```
  * `cpp ex1.c` executes the preprocessor on `ex1.c`
    * the preprocessor transforms the code by executing all the directives and expanding all the macros
    * this creates a stream of tokens that are passed to the compiler's parser
  * when the preprocessor executes `#define MY_INT (42)` all instances of `MY_INT` are replaced by the string `(42)`

* `ex2.c`
```
#define MY_INT (6 * LUCKY_NUM)
#define LUCKY_NUM (7)

int x = MY_INT;
```
  * even nested macros are expanded - so `MY_INT` is `(42)`

* `ex3.c`
```
#include <stdio.h>

int main() {
  printf("Line %d: %s compiled on %s at %s.\n", __LINE__, __FILE__, __DATE__, __TIME__);
  return 0;
}
```
  * the preprocessor also includes several pre-defined macros
  * these macros are usually defined on all systems

* `ex4.c`
```
#include <stdio.h>

int main() {
  printf("Compiled on linux? %d\n", __gnu_linux__);
  printf("Compiled on OS X? %d\n", __APPLE__);
  return 0;
}
```
  * some macros are only defined on some systems
    * this is useful if you need your code to behave differently on different systems

* `ex5.c`
```
#include <stdio.h>

#if __APPLE__
const char OS_STR[] = "OS/X";
#elif __gnu_linux__
const char OS_STR[] = "gnu/linux";
#else
const char OS_STR[] = "unknown";
#endif

int main() {
  printf("Compiled on %s\n", OS_STR);
  return 0;
}
```

* `ex6.c`
```
#include <stdio.h>

#ifdef __APPLE__
const char OS_STR[] = "OS/X";
#elif defined(__gnu_linux__)
const char OS_STR[] = "gnu/linux";
#else
const char OS_STR[] = "unknown";
#endif

int main() {
  printf("Compiled on %s\n", OS_STR);
  return 0;
}
```
  * same as last example

* `ex7.c`
```
#include <stdio.h>

int main() {
  #ifdef DEBUG
  printf("Running in debug mode at level %d\n", DEBUG);
  #endif

  return 0;
}
```
  * preprocessor is often used to turn on debugging information when the developer needs additional information
  * we can define macros on the command line using the `-D` flag
    * `gcc -D DEBUG ex7.c` - by default the macro is defined with value 1, which is true
    * `gcc -D DEBUG=3 ex7.c` - we can set it to take another value
    * this can allow us to quickly reconfigure a system to provide varying amounts of debugging information

The preprocessor is an important part of the compiler toolchain
* consider `#include "sorts.h"`
  * the C compiler processes a single file at a time
  * the preprocessor is used to create a single file that contains the contents of header files and the source file being compiled
  * in this case the entire header file is copied into the file being compiled
  * header files depend entirely on preprocessor support

Function-like macros exist but are not recommended
