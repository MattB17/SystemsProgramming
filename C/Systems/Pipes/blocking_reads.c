#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXSIZE 4096
void handle_child1(int *fd);
void handle_child2(int *fd);

int main() {
  char line[MAXSIZE];
  int pipe_child1[2], pipe_child2[2];

  // create a pipe for child 1
  if (pipe(pipe_child1) == -1) {
    perror("pipe");
  }

  int r = fork();
  if (r < 0) {
    perror("fork");
    exit(1);
  } else if (r == 0) {
    handle_child1(pipe_child1);
    exit(0);
  } else {
    // this is parent, fork another child
    close(pipe_child1[1]);
    if (pipe(pipe_child2) == -1) {
      perror("pipe");
      exit(1);
    }

    r = fork();
    if (r < 0) {
      perror("fork");
      exit(1);
    } else if (r == 0) {
      // we are in the child
      close(pipe_child1[0]);
      handle_child2(pipe_child2);
      exit(0);
    } else {
      // we are in the parent
      close(pipe_child2[1]);

      // read first from child 1
      if ((r = read(pipe_child1[0], line, MAXSIZE)) < 0) {
        perror("read");
        exit(1);
      } else if (r == 0) {
        printf("pipe from child 1 is closed\n");
      } else {
        printf("Read %s from child 1\n", line);
      }

      // read from child 2
      if ((r = read(pipe_child2[0], line, MAXSIZE)) < 0) {
        perror("read");
        exit(1);
      } else if (r == 0) {
        printf("pipe from child 2 is closed\n");
      } else {
        printf("Read %s from child 2\n", line);
      }
    }
  }
  return 0;
}

void handle_child1(int *fd) {
  // close read file descriptor as we are writing to parent
  close(fd[0]);
  printf("[%d] child\n", getpid());

  // child2's written message will be blocked by child1
  while (1) {
    // do something
  }

  char message[10] = "HELLO DAD";
  write(fd[1], message, 10);
  close(fd[1]);
}

void handle_child2(int *fd) {
  // close read file descriptor as we are writing to parent
  close(fd[0]);
  printf("[%d] child\n", getpid());
  char message[10] = "HI MOM";

  write(fd[1], message, 10);
  printf("[%d] child is finished writing\n", getpid());
  close(fd[1]);
}
