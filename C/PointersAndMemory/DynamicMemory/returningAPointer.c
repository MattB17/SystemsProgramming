#include <stdio.h>
#include <stdlib.h>


void helper(int **data_arr) {
  *data_arr = malloc(sizeof(int) * 3);

  int *arr = *data_arr;
  arr[0] = 18;
  arr[1] = 21;
  arr[2] = 23;
}

int main() {
  int *data;
  helper(&data);

  printf("middle value: %d\n", data[1]);
  free(data);
  return 0;
}
