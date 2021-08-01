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
* each has a default action associated with it

There is a library function `kill` and a bash program also called `kill`

There are times we want to change the default action of a signal
* to print a message, to save some state, or to ignore the signal

The process control block (PCB) contains a signal table
* each entry contains a pointer to code which will be executed when the system delivers a signal to the process
* this is called the signal handling function
* we can change the behaviour of a signal by installing a new signal handling function

The `sigaction()` system call will modify the signal table so that our function is called instead of the default action

`int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`
* `signum` is the number of the signal that we are going to modify
* `act` is a pointer to a struct that we need to intialize before calling `sigaction`
* `oldact` pointer to a struct that will hold the previous state of the signal when sigaction returns

```
struct sigaction {
  void       (*sa_handler)(int);
  void       (*sa_sigaction)(int, siginfo_t *, void *);
  sigset_t     sa_mask;
  int          sa_flags;
  void       (*sa_restorer)(void);
}
```
* `sa_handler` is the function pointer for the signal handler we are installing

There are 2 signals you can't change
* SIGKILL
* SIGSTOP

### Processes
A program is a set of executable instructions
* source code
* compiled machine code

A process is a running instance of a program

When a program is loaded into memory for the purpose of executing the program, the memory layout has the following structure
```
---------------
---------------
     Code
---------------
    Globals
---------------
     Heap
---------------
    Unused
---------------
     Stack
---------------
      OS
---------------
```

The stack holds the function that is currently executing and any local variables

The operating system keeps track of some additional state for a process in the PCB (Process Control Block)

```
-------------------
| PID |           |
-------------------
| PC  |           |
-------------------
| SP  |           |
-------------------
| Open file table |
-------------------
|   Signal table  |
-------------------
|       ...       |
-------------------
```
* PID is the process ID
* SP is the stack pointer that defines the top of the stack
* PC is the program counter that identifies the instruction in the code

The process control block stores
* the current value of important registers
* any open file descriptors
* and other state that the operating system manages

The number of processors (CPUs) determine how many processes can be running at the same time

Processes can be in 3 different states
* running - one per processor
* ready - could run if there was another processor
* blocked - processes waiting for an event to occur

The operating system gives us the illusion of many running processes by switching between the ready and running states

Creating a process requires a system call because the operating system must set up data structures as the process control block that are needed by the new process

When a process calls `fork()` it transfers control to the operating system

To duplicate a process the operating system copies the original process' address space, its data, and it's PCB that keeps track of the current state of the process
* as a result, the newly created process is running the same code, has the same values for all variables in memory and has the same value for the program counter and stack pointer
* the newly created process gets a unique process ID
* the return value of `fork()` is different between the two processes
* the original process is the parent and the newly created process is the child
* when the child process runs it starts executing just after `fork()` returns
  * however we don't know whether the parent process or the child process will execute first
  * when the operating system is finished creating the new process control can be returned to either the parent or the child
* the parent and child processes are completely different processes and don't share memory
* if the parent and child are both producing output, the order of output is unpredictable
  * and could change on each run

`fork` might fail if there are too many processes for a user or across the whole system

The operating system controls the order that the processes run

The process we run from the shell is a child of the shell process
* the shell uses the `wait` system call to suspend itself until it's child terminates

`wait(int *stat_loc);`
* can use the `wait` system call to force the parent process to wait until it's children have terminated
* information about how the child terminated is stored in `stat_loc`
* if `wait` is successful, it returns the process ID of the child that terminated
  * otherwise it returns -1
* when a process calls `exit` or returns from main it returns -1 or 0
  * this is the value set in `stat_loc`
  * by convention 0 indicates that the program terminated successfully
  * a non-zero value usually indicates an unsuccessful termination

`waitpid(pid_t pid, int *stat_loc, int options);`
* lets you specify which child process to wait for

`wait` and `waitpid` only wait for a child process
* you cannot wait for an unrelated process or a child of a child process
* for more powerful communication between processes you can use a pipe or a signal

A zombie process is a process that is dead but is still hanging around for the parent to collect its termination status

We call the child process an orphan when the parent terminates first

The process with PID 1 is the `init` process, the first process that the operating system launches
* when a process becomes an orphan, it is adopted by the `init` process
* a zombie process is cleaned up after its termination status has been collected
* the main task of the `init` process is to call wait in a loop for all the termination statuses of the processes it has adopted
* after the `init` process has collected the termination status of an orphaned process, all of the process's data structures can be deleted

Linux provides the exec family of functions to replace the currently running process with a different executable
* when a process calls `execl`, control is passed to the operating system
* while performing `execl`, the file system finds the file containing the executable program and loads it into memory where the code segment is
  * it also initializes a new stack
  * the program counter and stack pointer are updated so that the first instruction to execute when control returns to the user level is the first instruction in the new program
* the program passed to `execl` is the compiled program, not source code
* when control returns to the user level process, the original code that called exec is gone
  * `execl` won't return if successful
  * however it will return if it was not successful and it wasn't able to load the program
* exec does not create a new process, instead it asks the OS to modify the current process
  * so the process has the same process ID before and after calling exec

The shell is a process and it uses `fork` and `exec`
* when you type a command at a shell prompt
  * the shell first calls fork to create a new process
  * then the shell calls exec to load a different program into the memory of the child process
  * typically, the shell then calls wait and blocks until the child finishes executing
  * when the wait call returns, the shell prints a prompt indicating it is ready to receive the next command

### Pipes
Collecting data into larger chunks allows the file system decide exactly when to send the data to the disk, network, or screen
* and to amortize the cost of data transfer by reducing the number of system calls made
* delegating these tasks allows the programmer to ignore the details of data transfer

File descriptors are of type int because the operating system uses them as an index into a file descriptors table of open files
* stdout is file descriptor 0
* stdin is file descriptor 1
* stderr is file descriptor 2

```
// Open a file using a FILE object
FILE *fp = fopen("file1.txt", "r");

// Open a file using a file descriptor
int filedes = open("file1", O_RDONLY);

// create a pipe
int fd[2]; // Array of 2 file descriptors
pipe(fd);

// read 256 bytes from file
read(filedes, buf, 256);

// read 256 bytes from pipe
read(fd[0], buf, 256);
```

Pipes are a form of interprocess communication that also uses file descriptors
* the same read and write system calls can be used for for both files and pipes
* a pip is specified by 2 file descriptors
  * one for reading data from the pipe
  * one for writing data to the pipe

```
int main() {
  int fd[2];

  pipe(fd);
  int r = fork();

  // in parent
  if (r > 0) {
    close(fd[0]);
  // in child
  } else if (r == 0) {
    close(fd[1]);
  }
}
```

When a program calls a pipe system call the operating system creates the pipe data structures and opens two file descriptors on the pipe - one for reading and one for writing
* these two file descriptors are stored in the array that we pass into the pipe
* the first element of the array will be the file descriptor for reading and the second element will be the file descriptor for writing
* after the pipe call returns, the process can now read and write on the pipe

When `fork` makes a copy of a process it also makes a copy of all open file descriptors
* so the child process inherits all open file descriptors
* so in the code above, after fork is called, both processes have read and write file descriptors on the pipe
* pipes are unidirectional - one process will write to the pipe and another process will read from the pipe
* file descriptors not used need to be closed
* ie if the parent writes and the child reads then the parent needs to close the read file descriptor and the child needs to close the write file descriptor

Pipes are used to communicate between 2 independent processes
* but it is up to the operating system to decide when these processes actually run
* it is possible the processes won't run in lock-step with each other

The producer consumer problem
* one process is writing or producing data
* another process is reading or consuming data
* they are connected by a queue
* the producer and consumer may not work at the same rate
* if the consumer is too slow then the data can pile up - we don't want the producer to put data into a full queue
* if the consumer is faster than the producer then the consumer will not have enough data to operate on - we need to ensure that a consumer doesn't try to remove data from an empty queue
* we also don't want the producer and consumer to operate on the queue simultaneously

The pipe is a queue data structure in the operating system
* the process writing to the pipe is the producer
* the process reading from the pipe is the consumer
* since the operating system manages the pipe data structure it ensures that only one process is modifying it at a time
* the OS handles the consumer reading from the pipe when it is empty - the read call will block if the pipe is empty
* when the producer operate more quickly than the consumer the pipe will eventually fill up
  * to prevent data from being lost the OS will cause a write to the pipe to block until there is space in the pipe

`dup2` is a system call
* it makes a copy of an open file descriptor

A file descriptor is really an index into a table
* each process has its own set of file descriptors
* each process has its own file descriptor table
  * this table is stored in the process control block
  * it contains pointers to data structures that contain information about open files
  * the 0th index in the file descriptor table usually contains a link to the console

For the shell to execute a program it first needs to call `fork` to create a new process
* when a child process is created it obtains a copy of the file descriptor table from its parent
* even though the file descriptor tables are separate, the pointers in them may point to the same object
  * that's because file objects are shared
  * changes will be observed by both processes
