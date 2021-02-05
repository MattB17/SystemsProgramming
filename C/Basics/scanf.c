#include <stdio.h>

int main() {
  double cm, inches;

  printf("Type a number of centimeters: ");
  scanf("%lf", &cm);

  inches = cm * 0.393701;
  printf("%lf centimeters is %lf inches.\n", cm, inches);

  double num1, num2;
  printf("Type two numbers separated by a space: ");
  scanf("%lf %lf", &num1, &num2);
  printf("You types %f and %f\n", num1, num2);

  return 0;
}
