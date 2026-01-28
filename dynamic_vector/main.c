#include "dynamic_vector.h"
#include <stddef.h>
#include <stdio.h>

int main() {
  DynamicVector *dv = new_dvector();
  int num = 12;
  char letter = 'J';
  float pi = 3.141592;
  double xd = 999.9999;
  char *fav_lang = "Python/c/zig";
  char *pos_0 = "Pos 0";
  int pos_1 = 0111110;
  append(dv, "Jakepys", TYPE_STRING);
  append(dv, &num, TYPE_INT);
  append(dv, &letter, TYPE_CHAR);
  append(dv, &pi, TYPE_FLOAT);
  append(dv, &xd, TYPE_DOUBLE);
  printdv(dv);

  pop(dv);
  pop(dv);
  printdv(dv);

  shift(dv);
  shift(dv);
  printdv(dv);

  unshift(dv, &letter, TYPE_CHAR);
  unshift(dv, fav_lang, TYPE_STRING);
  printdv(dv);

  insert(dv, 0, pos_0, TYPE_STRING);
  insert(dv, 1, &pos_1, TYPE_INT);

  printdv(dv);
  printf("All good\n");

  printf("len: %lu\n", dv->length);

  for (size_t i = 0; i < 5; i++) {
    pop(dv);
  }

  printdv(dv);

  free_dvector(dv);
  return 0;
}
