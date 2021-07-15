#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

int main() {
  // nodes are usually allocated on the heap
  struct node *node_a  = malloc(sizeof(struct node));

  struct node *node_b = malloc(sizeof(struct node));
  node_a->next = node_b;

  printf("node_a: %p\n", node_a);
  printf("node_b: %p\n", node_b);

  return 0;
}
