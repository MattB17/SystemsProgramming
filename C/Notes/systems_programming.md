# Systems Programming

### System Calls
A system call is a function that requests a service from the operating system

`void exit(int status);`
* request to the operating system to terminate a program
* when `exit` is called the operating system executes instructions to clean up the data structures that represent the running process and to terminate the process

The low level I/O calls `read` and `write` are system calls
* higher level calls like `printf` and `scanf` use read and write in their calls

Process of `printf`
1. call `printf`
2. parse the format string and construct output string
3. set up buffer and copy output string to buffer
4. system call to `write`
  * write causes the system to change to executing operating system code that will take the output string and display it on screen
  * when control returns to the program that called `write` the return value is used to determine if the call was successful

When a system call occurs, control is given to the operating system
* and the operating system executes code on behalf of the program

File management system calls
* `int open(const char *pathname)`
* `ssize_t read(int fd, void *buf, size_t count);`
* `ssize_t write(int fd, const void *buf, size_t count);`
* `int close(int fd);`

Process management system calls
* `pid_t fork(void);`
* `pid_t getpid(void);`
* `pid_t wait(int *status);`
* `int kill(pid_t pid, int sig);`
* `int execv(const char *path, char)`

Interprocess communication system calls
* `int pipe(int pipefd[2]);`
* `int socket(int domain, int type, int protocol);`
* `int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
* `int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`
* `int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)`

Because system calls access resources outside the working program it is possible for them to fail
* the reasons for a system call failing might not be anything the program itself has any control over
* it is a programmer's responsibility to check that a call succeeds before using its results

`FILE *fopen(const char *path, const char *mode);`
* opens a file and returns a file pointer to the open file
* if it cannot open the file it returns `NULL`

`void *malloc(size_t size);`
* returns a pointer to a region of memory that it has allocated
* if it cannot allocate enough memory it returns `NULL`
* it isn't a system call, but it uses systems calls to allocate memory
* and it checks those

`int stat(const char *path, struct stat *buf);`
* finds information about a file pointed to by `path` and stores that information in `buf`
* it returns 0 if it succeeds and -1 if it encounters an error

System calls that return an integer will return -1 to indicate an error

System calls that return a pointer will return `NULL` to indicate an error

A global variable called `ERRNO` os used to indicate the type of the error
* it is a global variable of type `int`
* a header file included with your system includes different error numbers for different types of errors

When a system call fails it returns -1 or NULL to indicate error
* and it sets a value for ERRNO to indicate the type of error

`void perror(const char *s);`
* prints a message to standard error
* the message contains s, followed by a :, and then followed by a message that correspond to the value of ERRNO

It's good practice to use `exit` instead of `return`
* `return` in main will terminate the program
* but it's good practice to use `exit` as errors in functions won't terminate the program if you call `return` but will instead exit to the caller

Error checking and appropriate error messages are important for several reasons
* users of your program need useful messages if they use your program incorrectly or if the program fails
* checking for errors helps you discover bugs in your program more quickly

### Signals
Signals are a mechanism that allows a process or the operating system to interrupt a currently running process and notify that an event has occurred

Each signal is identified by a number between 1 and 31 and defined constants are used to give them names

There is a library function `kill` and a bash program also called `kill`
