// stack as a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

void push(Node *new_node, Node **stack) {
  new_node->next = *stack;
  *stack = new_node;
}

Node *pop(Node **stack) {
  Node *removed_node = *stack;
  if (*stack != NULL) {
    *stack = (*stack->next);
  }
  return removed_node;
}
