#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// include header file
# include "sorts.h"

// check that the sort is correct
void check_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      printf("Mis-sorted at index %d\n", i);
      return;
    }
  }
}

// initialize an array randomly
void random_init(int *arr, int size) {
  for (int i =0; i < size; i++) {
    arr[i] = rand();
  }
}

// initialize an array sorted in reverse order
void max_to_min_init(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = size - i;
  }
}

// both random_init and max_to_min_init have the same signature
// so we can add a pointer to it `void (*initializer)(int *, int)`
// all the sorting functions also have the same signature
// so a pointer to it would be void (*sort_func)(int *, int)

// times the sort
double time_sort(int size,
                 SortFunc_t initializer,
                 SortFunc_t sort_func) {
  int arr[size];
  initializer(arr, size);

  // clock returns the amount of CPU time used so far
  clock_t begin = clock();
  sort_func(arr, size);
  clock_t end = clock();

  check_sort(arr, size);

  return (double)(end - begin) / CLOCKS_PER_SEC;
}

// parse_command_line accepts argc and argv and returns a function
// pointer of type `void (*func_name)(int *, int)`
// without the typedef it would be
// `void (*parse_command_line(int argc, char **argv))(int *, int)`
SortFunc_t parse_command_line(int argc, char **argv) {
  if (argc > 1) {
    for (int sort = 0; sort < NUM_SORTS; sort++) {
      if (strcmp(argv[1], SORTS[sort].name) == 0) {
        return SORTS[sort].sort_func;
      }
    }
  }
  fprintf(stderr, "Unrecognized sort name. Valid names are:\n");
  for (int i = 0; i < NUM_SORTS; i++) {
    fprintf(stderr, " %s\n", SORTS[i].name);
  }
  exit(1);
}

int main(int argc, char **argv) {
  srand(time(NULL));

  // get a pointer to the sort function based on user input
  SortFunc_t sort_func = parse_command_line(argc, argv);

  for (int size = 1; size <= 4096; size *= 2) {
    double time_spent = time_sort(size, random_init, sort_func);
    printf("%d: %f\n", size, time_spent);
  }

  return 0;
}
