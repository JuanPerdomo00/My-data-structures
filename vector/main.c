#include <stdint.h>
#include <stdio.h>

#include "vector.h"

int main() {
  Vector* v = new_vector();

  for (int32_t i = 0; i < 10; i++) {
    append(v, i + 1);
  }

  printv(v);

  int32_t num = pop(v);
  int32_t num2 = pop(v);
  printf("value: %i\n", num);
  printf("value: %i\n", num2);

  printv(v);

  shift(v);
  shift(v);

  printv(v);

  unshit(v, 20);
  unshit(v, 10);

  printv(v);

  insert(v, v->length, -255);
  insert(v, 0, 255);

  printv(v);

  free_vector(v);
  return 0;
}
