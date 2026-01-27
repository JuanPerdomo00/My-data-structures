#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  int32_t *data;
  size_t length;
  size_t capacity;
} Vector;

Vector *new_vector();
void free_vector(Vector *v);

void append(Vector *v, int32_t value);
int32_t pop(Vector *v);
void shift(Vector *v);
void unshit(Vector *v, int32_t value);
void insert(Vector *v, int32_t index, int32_t value);

// Debug
void printv(Vector *v);
#endif
