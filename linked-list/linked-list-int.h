#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

struct linked_list {
  unsigned int length;
  struct linked_list_node *head;
};

struct linked_list_node {
  int value;
  struct linked_list_node *next;
};

struct linked_list* create_linked_list(void);
bool add_to_linked_list(struct linked_list *, int);
bool insert_into_linked_list(struct linked_list *, unsigned int, int);
int delete_from_linked_list(struct linked_list *, unsigned int);
void destroy_linked_list(struct linked_list *);
int element_in_linked_list(struct linked_list *, unsigned int);

#endif
