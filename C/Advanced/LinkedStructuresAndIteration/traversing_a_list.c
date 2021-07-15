#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

Node *create_node(int num, Node *next) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = num;
  new_node->next = next;

  return new_node;
}

int main() {
  Node *front = NULL;

  // create linked list back to front
  front = create_node(3, front);
  front = create_node(2, front);
  front = create_node(1, front);

  // traverse the list and print the values
  Node *curr = front;
  while (curr != NULL) {
    printf("%d\n", curr->value);
    curr = curr->next;
  }

  return 0;
}
