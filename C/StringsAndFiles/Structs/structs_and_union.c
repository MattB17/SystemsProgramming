#include <stdio.h>
#include <string.h>

struct player {
  int number;
  char *name;
  int goals;
};

// increments the goals field (ie scoring)
void score(struct player *p) {
  p->goals++;
}

int main(int argc, char **argv) {
  struct player d;
  d.number = 17;
  d.name = "Daniel";
  d.goals = 5;
  score(&d);
}
