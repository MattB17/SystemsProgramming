#include <stdio.h>

int main() {
  int canada_population; /* Variable Declaraction */
  canada_population = 35540000; /* Variable Assignment */

  int base, height, area;
  base = 12;
  height = 7;
  area = base * height;

  int x, y;
  x = 2;
  y = (x + 2) * (x + 5); /* The expression is evaluated before assigning to y */
  /* so if we later change x, y will not change */

  double temperature = 98.6;

  double quotient = 9 / 4; /* both integers so this gives 2.0 */
  int modulo = 9 % 4;

  return 0;
}
