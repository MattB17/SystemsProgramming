#include <stdio.h>

int main() {
  for (int i = 0; i < 31; i++) {
    if (july_daily_sms[i] > 100) {
      printf("July %d\n", i + 1);
    }
  }
}
