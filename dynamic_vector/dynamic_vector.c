#include "dynamic_vector.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicVector *new_dvector() {
  DynamicVector *dv = malloc(sizeof(DynamicVector));
  dv->length = 0;
  dv->capacity = 2;
  dv->item = (void *)malloc(dv->capacity * sizeof(void *));
  dv->data_type = (DataType *)malloc(dv->capacity * sizeof(DataType));
  return dv;
}

void append(DynamicVector *dv, void *item, DataType dtype) {
  if (dv->length >= dv->capacity) {
    if (dv->capacity == 0) {
      dv->capacity = 2;
    } else {
      dv->capacity *= 2;
    }
    dv->item = realloc(dv->item, dv->capacity * sizeof(void *));
    dv->data_type = realloc(dv->data_type, dv->capacity * sizeof(DataType));
  }

  dv->item[dv->length] = item;
  dv->data_type[dv->length] = dtype;
  dv->length++;
}

void pop(DynamicVector *dv) {
  assert(dv->length > 0 && "The vector must have at least 1 element.");
  dv->item[dv->length - 1] = 0;
  dv->data_type[dv->length - 1] = 0;
  dv->length--;
}

void shift(DynamicVector *dv) {
  assert(dv->length > 0 && "The vector must have at least 1 element.");
  memmove(dv->item, dv->item + 1, ((dv->length - 1) * sizeof(*dv->item)));
  memmove(dv->data_type, dv->data_type + 1,
          ((dv->length - 1) * sizeof(*dv->data_type)));

  dv->length--;
}

void unshift(DynamicVector *dv, void *item, DataType dtype) {
  if (dv->length >= dv->capacity) {
    if (dv->capacity == 0) {
      dv->capacity = 2;
    } else {
      dv->capacity *= 2;
    }
    dv->item = realloc(dv->item, dv->capacity * sizeof(void *));
    dv->data_type = realloc(dv->data_type, dv->capacity * sizeof(DataType));
  }

  memmove(&*dv->item + 1, &*dv->item, (dv->capacity * sizeof(*dv->item)));
  memmove(&*dv->data_type + 1, &*dv->data_type,
          (dv->capacity * sizeof(*dv->data_type)));
  *dv->item = item;
  *dv->data_type = dtype;
  dv->length++;
}

void insert(DynamicVector *dv, size_t index, void *item, DataType dtype) {
  assert(index <= dv->length && "Index out of bounds");

  if (dv->length >= dv->capacity) {
    if (dv->capacity == 0) {
      dv->capacity = 2;
    } else {
      dv->capacity *= 2;
    }
    dv->item = realloc(dv->item, dv->capacity * sizeof(void *));
    dv->data_type = realloc(dv->data_type, dv->capacity * sizeof(DataType));
  }

  memmove(dv->item + index + 1, dv->item + index,
          ((dv->length - index) * sizeof(*dv->item)));

  memmove(dv->data_type + index + 1, dv->data_type + index,
          (dv->capacity * sizeof(*dv->data_type)));

  *(dv->item + index) = item;
  *(dv->data_type + index) = dtype;
  dv->length++;
}

void free_dvector(DynamicVector *dv) {
  if (dv == NULL)
    return;

  free(dv->item);
  free(dv->data_type);
  free(dv);
}

void printdv(DynamicVector *dv) {
  printf("[");
  for (size_t i = 0; i < dv->length; i++) {
    switch (dv->data_type[i]) {
    case TYPE_INT:
      printf("%d", *(int *)dv->item[i]);
      break;
    case TYPE_CHAR:
      printf("'%c'", *(char *)dv->item[i]);
      break;
    case TYPE_DOUBLE:
      printf("%.2lf", *(double *)dv->item[i]);
      break;
    case TYPE_FLOAT:
      printf("%.2f", *(float *)dv->item[i]);
      break;
    case TYPE_STRING:
      printf("\"%s\"", (char *)dv->item[i]);
      break;
    default:
      printf("\"unknown\"");
    }
    if (i < dv->length - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
