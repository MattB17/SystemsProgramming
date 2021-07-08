#include <stdio.h>

// macro for simple variable
#define TAX_RATE .08

// macro for function
#define WITH_TAX(x) ((x) * 1.08)

int main() {
  double purchase = 9.99;
  double purchase2 = 12.49;
  printf("%f\n", WITH_TAX(purchase));
  printf("%f\n", WITH_TAX(purchase + purchase2));

  return 0;
}
