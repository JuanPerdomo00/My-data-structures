#ifndef DVECTOR_H
#define DVECTOR_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef enum {
  TYPE_INT,
  TYPE_STRING,
  TYPE_CHAR,
  TYPE_FLOAT,
  TYPE_DOUBLE,
} DataType;

typedef struct {
  void **item;
  DataType *data_type;
  size_t length;
  size_t capacity;
} DynamicVector;

DynamicVector *new_dvector();

void append(DynamicVector *dv, void *item, DataType dtype);
void free_dvector(DynamicVector *dv);
void pop(DynamicVector *dv);
void shift(DynamicVector *dv);
void unshift(DynamicVector *dv, void *item, DataType dtype);
void insert(DynamicVector *dv, size_t index, void *item, DataType dtype);

// Debug
void printdv(DynamicVector *dv);
#endif
