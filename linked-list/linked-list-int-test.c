#include <stdio.h>
#include "linked-list-int.h"

void print_list(struct linked_list *);

int main(int argc, char *argv[]) {
  struct linked_list* l;

  l = create_linked_list();
  if (! l) {
    fprintf(stderr, "Unable to create linked list");
    return 1;
  }

//  insert_into_linked_list(l, 0, 16);
//  insert_into_linked_list(l, 1, 32);
//  printf("After inserting initial els\n");
//  print_list(l);

  for (int i = 0; i < 10; i++) {
    printf("Adding %d\n", i * 10);
    add_to_linked_list(l, i * 10);
  }
  printf("After adding initial els, list len = %d\n", l->length);
  print_list(l);

//  printf("head val %d\n",  l->head->value);
//  printf("head->next val %d\n",  l->head->next->value);

  printf("\nList length is 12? %s\n", l->length == 12 ? "Yes (GOOD)" : "No (BAD)");

  insert_into_linked_list(l, 0, 64);
  insert_into_linked_list(l, 7, 53);
  insert_into_linked_list(l, 8, 57);
  printf("\nAfter inserting at els 0, 7, 8\n");
  print_list(l);

  delete_from_linked_list(l, 7);
  delete_from_linked_list(l, 7);
  printf("\nAfter deleting at els 7, 7\n");
  print_list(l);

  add_to_linked_list(l, 1024);
  printf("\nAfter adding 1024\n");
  print_list(l);

  delete_from_linked_list(l, 0);
  printf("\nAfter deleting at el 0\n");
  print_list(l);

  delete_from_linked_list(l, l->length - 1);
  printf("\nAfter deleting last el\n");
  print_list(l);

  add_to_linked_list(l, 2048);
  printf("\nAfter adding 2048\n");
  print_list(l);

  insert_into_linked_list(l, 0, 256);
  printf("\nAfter inserting at 0\n");
  print_list(l);

  destroy_linked_list(l);

  return 0;
}

void print_list(struct linked_list *l) {
  for (unsigned int i = 0; i < l->length; i++) {
    printf("[%d] = %d\n", i, element_in_linked_list(l, i));
  }
}
