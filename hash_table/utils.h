#ifndef UTILS_H
#define UTILS_H

#include "hash_table.h"

void print_ht(hash_table *ht);
void print_ht_debug(hash_table *ht);
void search_value(hash_table *ht, const char *key);
#endif
