#include <stdio.h>
#include <stdlib.h>
#include "vector-int.h"

int main(int argc, char *argv[])
{
  int vally;
  struct vector *v = createVector(10);

  for (unsigned int i = 1; i < 100; i++) {
    vally = i * 10;
    printf("[%d] Adding %d to vector\n", i, vally);
    addToVector(v, vally);
  }

  insertIntoVector(v, 1000, 0);

  insertIntoVector(v, 55, 6);

  for (unsigned int i = 0; i < v->used; i++) {
    printf("v[%d] = %d\n", i, elementInVector(v, i));
  }

  vally = deleteFromVector(v, 6);
  printf("Deleting %d\n", vally);

  for (unsigned int i = 0; i < v->used; i++) {
    printf("v[%d] = %d\n", i, elementInVector(v, i));
  }

  destroyVector(v);

  return 0;
}
