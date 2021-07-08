#include <stdio.h>

// declares size_t to be an unsigned int
typedef unsigned int size_t;

// other custom types
typedef unsigned int age_t;
typedef unsigned int shoe_size_t;

// alias struct student so instead of typing
// `struct student s` we can type `Student s`
typedef struct student {
  char first_name[20];
  char last_name[20];
  int year;
  float gpa;
} Student;

void print_boot_size(shoe_size_t shoe_size) {
  printf("boot size: %d\n", shoe_size + 2);
}

// the compiler won't complain if you pass in any other value
// that can be an unsigned int, even if it is not a shoe size

int main() {
  age_t my_age = 5;
  print_boot_size(my_age);
  print_boot_size('5');

  Student s;
  Student *p;

  return 0;
}
