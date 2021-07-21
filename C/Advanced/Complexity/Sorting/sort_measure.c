#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

void check_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      printf("Missorted at index %d\n", i);
      return;
    }
  }
}

void random_init(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand();
  }
}

double time_sort(int size) {
  int arr[size];
  random_init(arr, size);

  clock_t begin = clock();
  bubble_sort(arr, size);
  clock_t end = clock();

  check_sort(arr, size);

  return (double)(end - begin) / CLOCKS_PER_SEC;
}

int main() {
  srand(time(NULL));

  for (int size = 1; size <= 4096; size *= 2) {
    double time_spent = time_sort(size);
    printf("%d: %f\n", size, time_spent);
  }

  return 0;
}
