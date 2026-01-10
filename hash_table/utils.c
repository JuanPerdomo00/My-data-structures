#include "utils.h"

#include <stdio.h>

#include "hash_table.h"

void print_ht(hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    if (ht->items[i] != NULL) {
      printf("index: %d, key=%s:value=%s\n", i, ht->items[i]->key,
             ht->items[i]->value);
      continue;
    }
    printf("index: %d, key=NULL:value:NULL\n", i);
  }
}

void print_ht_debug(hash_table *ht) {
  printf("Debug hash table\n");
  printf("size: %d\n", ht->size);
  printf("count: %d\n\n", ht->count);

  for (int i = 0; i < ht->size; i++) {
    if (ht->items[i] != NULL) {
      printf("index: %d\n\t- key=%s:value=%s\n\t- addr: %p\n", i,
             ht->items[i]->key, ht->items[i]->value, &ht->items[i]);
      continue;
    }
    printf("index: %d, key=NULL:value:NULL addr: %p\n", i, &ht->items[i]);
  }
}

void search_value(hash_table *ht, const char *key) {
  char *value = search(ht, key);
  if (value == NULL) {
    printf("There is no name key: %s\n", key);
    return;
  }
  printf("value=%s\n", value);
}
