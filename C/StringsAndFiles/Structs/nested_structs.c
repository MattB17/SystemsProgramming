#include <stdio.h>

struct point {
  int x;
  int y;
};

struct vector {
  struct point start;
  struct point end;
};

int main(int argc, char **argv) {
  struct point origin;
  origin.x = 0;
  origin.y = 0;

  struct vector v;
  // chaining dots
  v.start.x = 1;
  v.start.y = 2;
  v.end.x = 4;
  v.end.y = 4;

  return 0;
}
