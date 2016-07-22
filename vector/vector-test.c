#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char *argv[])
{
  int *vally;
  struct vector *v = createVector(10);

  for (unsigned int i = 1; i < 100; i++) {
    vally = malloc(sizeof(int));
    *vally = i * 10;
    printf("[%d] Adding %d to vector\n", i, *vally);
    addToVector(v, vally);
  }

  vally = malloc(sizeof(int));
  *vally = 1000;
  insertIntoVector(v, vally, 0);

  vally = malloc(sizeof(int));
  *vally = 55;
  insertIntoVector(v, vally, 6);

  for (unsigned int i = 0; i < v->used; i++) {
    printf("v[%d] = %d\n", i, *(int *)elementInVector(v, i));
  }

  vally = deleteFromVector(v, 6);
  printf("Deleting %d\n", *vally);
  free(vally);

  for (unsigned int i = 0; i < v->used; i++) {
    printf("v[%d] = %d\n", i, *(int *)elementInVector(v, i));
  }

  for (unsigned int i = 0; i < v->used; i++) {
    free(v->datum[i]);
  }
  
  destroyVector(v);

  return 0;
}
