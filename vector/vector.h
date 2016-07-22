#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>

struct vector {
  unsigned int length;
  unsigned int used;
  void **datum;
};

struct vector* createVector(unsigned int);
bool addToVector(struct vector*, void*);
bool insertIntoVector(struct vector*, void*, unsigned int);
void *elementInVector(struct vector*, unsigned int);
void *deleteFromVector(struct vector *, unsigned int);
void destroyVector(struct vector *);

#endif
