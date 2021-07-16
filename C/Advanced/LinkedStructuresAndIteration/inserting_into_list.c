#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

Node *create_node(int num, Node *next) {
  // allocate on heap
  Node *new_node = malloc(sizeof(Node));
  new_node->value = num;
  new_node->next = next;
  return new_node;
}

// pointer to pointer to Node to actually change the returned pointer
// if it's just pointer to node then only the local pointer is changed
// in the case position is 0
int insert(int num, Node **front_ptr, int position) {
  // nexative insert position
  if (position < 0) {
    return -1;
  }

  // inserting at beginning of list
  if (position == 0) {
    *front_ptr = create_node(num, *front_ptr);
    return 0;
  }

  Node *curr = *front_ptr;
  // move to the node before where we want to insert
  for (int i = 0; i < position - 1 && curr != NULL; i++) {
    curr = curr -> next;
  }

  // insert position too big
  if (curr == NULL) {
    return -1;
  }

  // set new node to point to node after so we don't lose it
  Node *new_node = create_node(num, curr->next);
  // update pointer of node before it to point to the new node
  curr->next = new_node;

  return 0;
}

int main() {
  Node *front;

  // builds list in reverse order
  front = create_node(4, NULL);
  front = create_node(3, front);
  front = create_node(1, front);

  insert(2, &front, 1);
  insert(5, &front, 4);
  insert(0, &front, 0);

  // traverses the list
  Node *curr = front;
  while (curr != NULL) {
    printf("%d\n", curr->value);
    curr = curr->next;
  }

  return 0;
}
