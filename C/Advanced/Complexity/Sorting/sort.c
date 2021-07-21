#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

void swap(int *arr, int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

// walks through array swapping consecutive values
// if they are not in the correct order
// is O(n^2)
void bubble_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - 1; j++) {
      if (arr[j - 1] > arr[j]) {
        swap(arr, j - 1, j);
      }
    }
  }
}

// looks for smallest value remaining and then performs a single
// swap to put this in the right place
// again O(n^2)
// slightly faster than bubble_sort as a swap is more compute
// intensive than assignment
void selection_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int current = i;
    for (int j = i; j < size; j++) {
      if (arr[current] > arr[j]) {
        current = j;
      }
    }
    swap(arr, i, current);
  }
}

// this is O(nlogn)
void merge_sort(int *arr, int size) {
  if (size <= 1) {
    return;
  }

  int arr1_size = size/2;
  merge_sort(arr, arr1_size);

  int *arr2 = arr + (size / 2);
  int arr2_size = size / 2 + size % 2;
  merge_sort(arr2, arr2_size);

  int arr_copy[size];
  int arr1_index = 0;
  int arr2_index = 0;
  int copy_arr1 = 0;
  for (int arr_index = 0; arr_index < size; arr_index++) {
    if (arr1_index < arr1_size && arr2_index < arr2_size &&
          arr[arr1_index] < arr2[arr2_index]) {
        copy_arr1 = 1;
    }

    if (copy_arr1 == 1) {
      arr_copy[arr_index] = arr[arr1_index];
      arr1_index += 1;
    } else {
      arr_copy[arr_index] = arr2[arr2_index];
      arr2_index += 1;
    }

    if (arr2_index > arr2_size) {
      copy_arr1 = 1;
    } else {
      copy_arr1 = 0;
    }
  }
  memcpy(arr, arr_copy, size * sizeof(int));
}
