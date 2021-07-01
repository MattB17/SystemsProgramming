#include <stdio.h>
#include <string.h>

struct student {
  char first_name[20];
  char last_name[20];
  int year;
  float gpa;
};

void change(struct student s) {
  s.gpa = 4.0;
  strcpy(s.first_name, "Adam");
}

int main() {
  struct student good_student;

  strcpy(good_student.first_name, "Jo");
  good_student.gpa = 3.2;
  // gpa and first_name are unchanged after this call because it passes a copy of the struct
  // for an array, the element would be changed
  change(good_student);
  printf("first name is %s\n", good_student.first_name);
  printf("GPA is %f\n", good_student.gpa);

  return 0;
}
