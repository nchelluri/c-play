#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector-int.h"

struct vector* createVector(unsigned int length)
{
  struct vector *v = malloc(sizeof(struct vector));

  if (! v) {
    fprintf(stderr, "malloc of vector struct failed\n");
    return NULL;
  }

  v->datum = malloc(sizeof(int) * length);

  if (! v->datum) {
    fprintf(stderr, "malloc of vector datum failed\n");
    return NULL;
  }

  v->length = length;
  v->used = 0;

  return v;
}

void destroyVector(struct vector *v) {
  free(v->datum);

  free(v);
}

bool addToVector(struct vector *v, int data) {
  int *newDatum;

  if (v->used == v->length) {
    newDatum = malloc(sizeof(int) * v->length * 2);

    if (! newDatum) {
      fprintf(stderr, "malloc of resized vector datum failed\n");
      return false;
    }

    for(unsigned int i = 0; i < v->length; i++) {
      newDatum[i] = v->datum[i];
    }

    free(v->datum);
    v->datum = newDatum;
    v->length = v->length * 2;
  }

  v->datum[v->used++] = data;

  return true;
}

bool insertIntoVector(struct vector *v, int data, unsigned int index) {
  if (! addToVector(v, data)) {
    return false;
  }

  for (unsigned int i = v->used - 1; i > index; i--) {
    v->datum[i] = v->datum[i-1];
  }

  v->datum[index] = data;

  return true;
}

int elementInVector(struct vector *v, unsigned int index) {
  return v->datum[index];
}

// Does not resize vector
int deleteFromVector(struct vector *v, unsigned int index) {
  int val = elementInVector(v, index);

  for (unsigned int i = index; i < v->used - 1; i++) {
    v->datum[i] = v->datum[i + 1];
  }

  v->used--;

  return val;
}
