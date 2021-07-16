#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *prev;
  struct node *next;
} Node;

Node *front = NULL;

// function signatures
int insert(Node *new_node, Node **list, int idx);
Node *delete(Node **list, int idx);

// implementation
// insert new_node in list at position idx
int insert(Node *new_node, Node **list, int idx) {
  return 0;
}

Node *delete(Node **list, int idx) {
  return NULL;
}
