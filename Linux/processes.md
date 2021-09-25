# Processes
Modern operating systems are usually multitasking, meaning that they create the illusion of doing more than one thing at once by rapidly switching from one executing program to another
* the Linux kernel manages this through the use of processes
* processes are how Linux organizes the different programs waiting for their turn at the CPU

When a system starts up, the kernel initiates a few of its own activities as processes and launches a program called `init`
* `init` runs a series of shell scripts (located in `/etc`) called init scripts, which start all the system services
* many of these services are implemented as daemon programs
  * daemon programs are programs that just sit in the background and do their thing without having any user interface

The fact that a program can launch other programs is expressed in the process sheme as a parent process producing a child process

The kernel maintains information about each process to help keep things organized
* each process is assigned a number called a process ID (PID)
* PIDs are assigned in ascending order, with `init` always getting PID 1
* the kernel also keeps track of the memory assigned to each process, as well as the processes' readiness to resume execution

Signals are one of several ways that the operating system communicates with programs
* programs "listen" for signals and may act upon them as they are received
* the fact that a program can listen and act upon signals allows it to do things like save work in progress when it is sent a termination signal
