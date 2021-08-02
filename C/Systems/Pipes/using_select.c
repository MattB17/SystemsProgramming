// parent forks 2 children with a pipe to read from each of them
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

  if (pipe(pipe_child1) == -1) {
    perror("pipe");
    exit(1);
  }

  int r = fork();
  if (r < 0) {
    perror("fork");
    exit(1);
  } else if (r == 0) {
    // we are in child 1
    handle_child1(pipe_child1);
    exit(0);
  } else {
    // we are in the parent so fork another child
    close(pipe_child1[1]);
    if (pipe(pipe_child2) == -1) {
      perror("pipe");
    }

    // fork the second child
    r = fork();
    if (r < 0) {
      perror("fork");
      exit(1);
    } else if (r == 0) {
      // we are in child 2

      // child 1 was still open in parent and this was inherited by child2
      close(pipe_child1[0]);
      handle_child2(pipe_child2);
      exit(0);
    } else {
      close(pipe_child2[1]);

      // initialize array of bits for the file descriptors
      fd_set read_fds;
      FD_ZERO(&read_fds);
      FD_SET(pipe_child1[0], &read_fds);
      FD_SET(pipe_child2[0], &read_fds);

      // set number of file descriptors for select
      int numfd;
      if (pipe_child1[0] > pipe_child2[0]) {
        numfd = pipe_child1[0] + 1;
      } else {
        numfd = pipe_child2[0] + 1;
      }

      // check for blocking error
      if (select(numfd, &read_fds, NULL, NULL, NULL) == -1) {
        perror("select");
        exit(1);
      }

      // check if first child is ready and read from child1
      if (FD_ISSET(pipe_child1[0], &read_fds)) {
        if ((r = read(pipe_child1[0], line, MAXSIZE)) < 0) {
          perror("read");
          exit(1);
        } else if (r == 0) {
          printf("pipe from child 1 is closed\n");
        } else {
          printf("Read %s from child 1\n", line);
        }
      }

      // check if second child is ready and read from child2
      if (FD_ISSET(pipe_child2[0], &read_fds)) {
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
  }
  return 0;
}

void handle_child1(int *fd) {
  close(fd[0]);
  printf("[%d] child\n", getpid());
  char message[10] = "HELLO DAD";
  write(fd[1], message, 10);
  close(fd[1]);
}

void handle_child2(int *fd) {
  close(fd[0]);
  printf("[%d] child\n", getpid());
  char message[10] = "Hi mom";
  write(fd[1], message, 10);
  close(fd[1]);
}
