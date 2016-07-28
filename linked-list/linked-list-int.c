#include <stdio.h>
#include <stdlib.h>
#include "linked-list-int.h"

struct linked_list* create_linked_list(void) {
  struct linked_list* l = malloc(sizeof(struct linked_list));

  if (! l) {
    fprintf(stderr, "Unable to allocate memory for linked list");
    return NULL;
  }

  l->length = 0;
  l->head = NULL;

  return l;
}

void destroy_linked_list(struct linked_list* l) {
  struct linked_list_node *cur;
  struct linked_list_node *next = l->head;

  for (unsigned int i = 0; i < l->length; i++) {
    cur = next;
    next = next->next;

    free(cur);
  }

  free(l);
}

bool add_to_linked_list(struct linked_list *l, int value) {
  struct linked_list_node *last;

  if (! l->head) {
    l->head = malloc(sizeof(struct linked_list_node));

    if (! l->head) {
      fprintf(stderr, "Could not allocate memory for linked list head");
      return false;
    }

    l->head->value = value;
    l->head->next = NULL;
  } else {
    last = l->head;
    while (last->next != NULL) {
      last = last->next;
    }

    last->next = malloc(sizeof(struct linked_list_node));
    if (! last->next) {
      fprintf(stderr, "Could not allocate memory for linked list node");
      return false;
    }

    last->next->value = value;
    last->next->next = NULL;
  }

  l->length++;

  return true;
}

bool insert_into_linked_list(struct linked_list *l, unsigned int index, int value) {
  // TODO: index must be less than length; how to handle error conditions?

  struct linked_list_node *node = malloc(sizeof(struct linked_list_node));
  struct linked_list_node *prev;

  if (! node) {
    fprintf(stderr, "Could not allocate memory for linked list node");
    return false;
  }

  node->value = value;
  node->next = NULL;

  if (index == 0) {
    node->next = l->head;
    l->head = node;
  } else {
    prev = l->head;

    for (unsigned int i = 1; i < index; i++) {
      prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;
  }

  l->length++;

  return true;
}

int delete_from_linked_list(struct linked_list *l, unsigned int index) {
  struct linked_list_node *prev, *to_delete;
  int ret_val;

  if (index == 0) {
    to_delete = l->head;
    l->head = l->head->next;
  } else {
    prev = l->head;

    for (int i = 1; i < index; i++) {
      prev = prev->next;
    }

    to_delete = prev->next;
    prev->next = to_delete->next;
  }

  ret_val = to_delete->value;
  free(to_delete);

  l->length--;

  return ret_val;
}

int element_in_linked_list(struct linked_list *l, unsigned int index) {
  struct linked_list_node *el = l->head;

  for (unsigned int i = 0; i < index; i++) {
    el = el->next;
  }

  return el->value;
}
