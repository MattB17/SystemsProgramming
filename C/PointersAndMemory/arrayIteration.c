#include <stdio.h>

#define DAYS 4

int main() {
  float daytime_high[DAYS] = {16.0, 12.8, 14.6, 19.1};

  float average_temp = 0;
  for (int i = 0; i < DAYS; i++) {
    printf("Adding element %d with value %f\n", i, daytime_high[i]);
    average_temp += daytime_high[i];
  }
  average_temp = average_temp / DAYS;
  printf("Average temperature: %f\n", average_temp);

  return 0;
}
