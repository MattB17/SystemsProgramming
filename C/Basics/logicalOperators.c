#include <stdio.h>

int main() {
  float gpa = 2.3;

  if (gpa >= 0.0 && gpa <= 4.0) {
    printf("GPA is valid.\n");
  } else {
    printf("GPA is invalid.\n");
  }

  gpa = 4.9;

  if (!(gpa < 0.0 || gpa > 4.0)) {
    printf("GPA is valid.\n");
  } else {
    printf("GPA is invalid.\n")
  }

  float gpa1 = 3.3;
  float gpa2 = 2.2;

  if (gpa1 >= 3.0 || gpa2 >= 3.0) {
    printf("One or both GPAs are at least 3.0\n");
  } else {
    printf("Both GPAs are less than 3.0\n");
  }

  return 0;
}
