#include <stdio.h>

int main() {
  int age = 5;

  // if without else
  if (age >= 13 && age <= 18) {
    printf("She's a teenager.\n");
  }

  // if with else having nested if
  if (age >= 13 && age <= 18) {
    printf("She's a teenager.\n");
  } else {
    if (age < 13) {
      printf("She's younger than a teenager.\n");
    } else {
      printf("She's older than a teenager.\n");
    }
  }

  // or the unnested version
  if (age >= 13 && age <= 18) {
    printf("She's a teenager.\n");
  } else if (age < 13) {
    printf("She's younger than a teenager.\n");
  } else {
    printf("She's older than a teenager.\n");
  }

  return 0;
}
