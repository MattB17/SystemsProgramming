#include <stdio.h>
#include <string.h>

struct student {
  char first_name[20];
  char last_name[20];
  int year;
  float gpa;
};

// gets a pointer to a student struct
void change(struct student *s) {
  // dereference pointer to struct to change elements
  strcpy((*s).first_name, "Adam");
  (*s).gpa = 4.0;
}

int main() {
  struct student good_student;

  strcpy(good_student.first_name, "Jo");
  good_student.gpa = 2.1;
  // passes a pointer to the struct
  change(&good_student);
  printf("first name is %s\n", good_student.first_name);
  printf("GPA is %f\n", good_student.gpa);

  return 0;
}
