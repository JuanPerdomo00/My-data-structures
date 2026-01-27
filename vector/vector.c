#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector *new_vector() {
  Vector *v = (Vector *)malloc(sizeof(Vector));
  v->length = 0;
  v->capacity = 2;
  v->data = (int32_t *)malloc(sizeof(int32_t));
  return v;
}

void free_vector(Vector *v) {
  if (v->length == 0) {
    return;
  }
  free(v->data);
  free(v);
}

void append(Vector *v, int32_t value) {
  if (v->length >= v->capacity) {
    if (v->capacity == 0)
      v->capacity = 2;
    else
      v->capacity *= 2;

    v->data = realloc(v->data,
                      v->capacity * sizeof(*v->data)); // First element array;
  }
  v->data[v->length++] = value;
}

int32_t pop(Vector *v) {
  assert(v->length > 0 && "The vector must have at least 1 element.");
  int32_t value = v->data[v->length - 1];
  v->data[v->length - 1] = 0;
  v->length--;
  return value;
}

void shift(Vector *v) {
  assert(v->length > 0 && "The vector must have at least 1 element.");
  memmove(&*v->data, &*(v->data + 1), (v->capacity * sizeof(*v->data)));
  v->length--;
}

void unshit(Vector *v, int32_t value) {
  if (v->length >= v->capacity) {
    if (v->capacity == 0) {
      v->capacity = 2;
    } else {
      v->capacity *= 2;
    }
    v->data = realloc(v->data, (v->capacity * sizeof(*v->data)));
  }

  memmove(&*v->data + 1, &*v->data, (v->capacity * sizeof(*v->data)));
  *v->data = value;
  v->length++;
}

void insert(Vector *v, int32_t index, int32_t value) {
  if (v->length >= v->capacity) {
    if (v->capacity == 0) {
      v->capacity = 2;
    } else {
      v->capacity *= 2;
    }
    v->data = realloc(v->data, (v->capacity * sizeof(*v->data)));
  }

  memmove(&*v->data + index + 1, &*v->data + index,
          (v->capacity * sizeof(*v->data)));
  *(v->data + index) = value;
  v->length++;
}

void printv(Vector *v) {
  printf("[");
  for (int32_t i = 0; i < v->length; i++) {
    printf("%d", v->data[i]);
    if (i < v->length - 1) {
      printf(",");
    }
  }
  printf("]\n");
}
