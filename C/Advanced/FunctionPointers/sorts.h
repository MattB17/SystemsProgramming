// a guard. First line is if not defined SORTS_H
#ifndef SORTS_H
#define SORTS_H

// declares function pointer type SortFunc_t
typedef void (*SortFunc_t)(int *, int);

void bubble_sort(int *, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);

typedef struct {
  char *name;
  // pointer to a sort function
  SortFunc_t sort_func;
} sort_info;

extern const int NUM_SORTS;
// initialize array of sort_info structs
extern sort_info SORTS[];

#endif
