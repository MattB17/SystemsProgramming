#include <stdio.h>

int main() {
  /* This program calculates the result of 6 months of compound interest on a
  principal investment of $500, at an interest rate of 4% annually, compounded
  monthly */

  // Initial investment
  int principal = 500;

  // Calculation variables;
  double interest_rate, multiplier, compound_interest;
  interest_rate = 0.04;
  multiplier = 1 + (interest_rate / 12);
  compound_interest = multiplier * multiplier * multiplier * multiplier *
    multiplier * multiplier;

  // Result variable;
  double six_months_compounded;
  six_months_compounded = principal * compound_interest;
  printf("$%.2d compounded for 6 months at %.2f annually is $%.2f\n",
    principal, interest_rate, six_months_compounded);

  return 0;
}
