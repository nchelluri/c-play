#include <stdio.h>
#include <stdlib.h>
#include "vector/vector-int.h"

#define MAX_ITEMS 100000

int main(int argc, char *argv[])
{
  int current;
  unsigned int currentIndex;
  int retVal = 0;
  struct vector *v = createVector(10);

  if (! v) {
    fprintf(stderr, "Error creating vector\n");
    return 1;
  }

  while (v->used < MAX_ITEMS && scanf("%d", &current) != EOF) {
    for (currentIndex = 0; currentIndex < v->used; currentIndex++) {
      if (elementInVector(v, currentIndex) > current) {
        break;
      }
    }

    insertIntoVector(v, current, currentIndex);
  }

  for (unsigned int i = 0; i < v->used; i++) {
    printf("[%d]: %d\n", i, elementInVector(v, i));
  }

 cleanup:
  destroyVector(v);

  return retVal;
}
