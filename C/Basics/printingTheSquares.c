#include <stdio.h>

int main() {
  int n;

  printf("Enter an integer representing the number of squares: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", i, i*i);
  }

  return 0;
}
