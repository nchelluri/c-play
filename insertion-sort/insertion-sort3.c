#include <stdio.h>
#include <stdlib.h>
#include "../vector/vector.h"

#define MAX_ITEMS 100000

int main(int argc, char *argv[])
{
  int current;
  unsigned int currentIndex;
  int *tmp;
  int retVal = 0;
  struct vector *v = createVector(10);

  if (! v) {
    fprintf(stderr, "Error creating vector\n");
    return 1;
  }

  while (v->used < MAX_ITEMS && scanf("%d", &current) != EOF) {
    for (currentIndex = 0; currentIndex < v->used; currentIndex++) {
      if (*(int *)elementInVector(v, currentIndex) > current) {
        break;
      }
    }

    tmp = malloc(sizeof(int));
    if (! tmp) {
      fprintf(stderr, "Error allocating integer memory\n");
      retVal = 2;
      goto cleanup;
    }
    *tmp = current;
    insertIntoVector(v, tmp, currentIndex);
  }

  for (unsigned int i = 0; i < v->used; i++) {
    printf("[%d]: %d\n", i, *(int *)elementInVector(v, i));
  }

 cleanup:

  if (v) {
    for (unsigned int i = 0; i < v->used; i++) {
      free(elementInVector(v, i));
    }
  }

  destroyVector(v);

  return retVal;
}
