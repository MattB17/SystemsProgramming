#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// index i is assigned value i
// running time is O(n)
void linear(int *array, int n) {
  for (int i = 0; i < n; i++) {
    array[i] = i;
  }
}

// first assigns 0 to all indices
// then adds one to indices 1 to n-1
// then adds one to indices 2 to n-1
// and so on, eventually index i has value i
// but runs in O(n^2) time
void quadratic(int *array, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    array[i] = 0;
  }
  for (i = 1; i < n; i++) {
    for (j = i; j < n; j++) {
      array[j] += 1;
    }
  }
}

int main(int agrc, char *argv[]) {
  int size = atoi(argv[1]);
  int arr[size];

  printf("For an array of size %d ...\n", size);

  // times the linear algorithm
  clock_t begin = clock();
  linear(arr, size);
  clock_t end = clock();

  printf("Linear took %lu units of time.\n", end - begin);

  // times the quadratic algorithm
  begin = clock();
  quadratic(arr, size);
  end = clock();

  printf("Quadratic took %lu units of time.\n", end - begin);

  return 0;
}
