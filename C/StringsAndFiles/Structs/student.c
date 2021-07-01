#include <stdio.h>
#include <string.h>

int main() {
  struct student {
    char first_name[20];
    char last_name[20];
    int year;
    float gpa;
  };

  struct student good_student;

  strcpy(good_student.first_name, "Jo");
  strcpy(good_student.last_name, "Smith");
  good_student.year = 2;
  good_student.gpa = 3.2;

  printf("Name: %s %s\n",
         good_student.first_name, good_student.last_name);
  printf("Year: %d, GPA: %.2f\n", good_student.year, good_student.gpa);

  return 0;
}
