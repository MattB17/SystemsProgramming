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
  if (idx < 0) {
    return -1
  }
  // insert at the head of the list
  if (idx == 0) {
    // update pointers for new node
    new_node->prev = NULL;
    new_node->next = *list;

    // if *list is not null, update its prev pointer to point
    // to the new node
    if (*list != NULL) {
      (*list)->prev = new_node;
    }

    // set the list pointer to new_node which is the head of the list
    *list = new_node;
    return 0;
  }

  // keep track of spot in list and current index
  Node *curr = *list;
  int curr_index = 0;

  // traverse to right spot
  while (curr && (curr_index + 1) < idx) {
    curr = curr->next;
    curr_index++;
  }

  // check for idx too high
  if (curr == NULL || (curr_index + 1) != idx) {
    return -1;
  }

  new_node->prev = curr;
  new_node->next = curr->next;

  if (new_node->next) {
    new_node->next->prev = new_node;
  }
  curr->next = new_node;

  return 0;
}

Node *delete(Node **list, int idx) {
  if (idx < 0) {
    return NULL;
  }

  Node *to_remove = *list;
  int curr_index = 0;

  // traverse to right spot
  while (to_remove && curr_index < idx) {
    to_remove = to_remove->next;
    curr_index++;
  }

  // check for invalid index / null list
  if (!to_remove || curr_index != idx) {
    return NULL;
  }

  // if we're at the fornt of the list we need to move to the second node
  if (idx == 0) {
    *list = to_remove->next;
  // otherwise update the prev pointer
  } else {
    to_remove->prev->next = to_remove->next;
  }

  // make sure we're not at the end of the list
  if (to_remove->next) {
    to_remove->next->prev = to_remove->prev;
  }

  to_remove->prev = to_remove->next = NULL;

  return to_remove;
}
