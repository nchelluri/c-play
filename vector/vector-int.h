#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>

struct vector {
  unsigned int length;
  unsigned int used;
  int *datum;
};

struct vector* createVector(unsigned int);
bool addToVector(struct vector*, int);
bool insertIntoVector(struct vector*, int, unsigned int);
int elementInVector(struct vector*, unsigned int);
int deleteFromVector(struct vector *, unsigned int);
void destroyVector(struct vector *);

#endif
