#include <stdio.h>
#include <string.h>

struct student {
  char first_name[20];
  char last_name[20];
  int year;
  float gpa;
};

int main() {
  struct student s;
  struct student *p;

  strcpy(s.first_name, "Jo");
  strcpy(s.last_name, "Smith");
  s.year = 2;
  s.gpa = 3.2;

  p = &s;
  // one way of accessing attribute from pointer
  (*p).gpa = 3.8;
  // another way of accessing an attribute from pointer
  p->year = 1;
  strcpy(p->first_name, "Henrick");

  printf("Name: %s %s\n", s.first_name, s.last_name);
  printf("Year: %d, GPA: %.2f\n", s.year, s.gpa);

  return 0;
}
