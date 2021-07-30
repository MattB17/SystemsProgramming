int main() {
  int i;
  pid_t result;

  i = 5;
  printf("%d\n", i);

  result = fork();

  // if it returns to the parent program and fork was successful
  // then the value of result is positive
  if (result > 0) {
    i = i + 2;
  // if it returns to the child program the value of result is 0
  } else if (result == 0) {
    i = i - 2;
  // if the value of result is negative then the fork called failed
  // and the new process was not created
  } else {
    perror("fork");
  }

  printf("%d\n", i);

  return 0;
}
