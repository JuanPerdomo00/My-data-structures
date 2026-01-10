#include "hash_table.h"
#include "prime.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

static item *new_item(const char *key, const char *value) {
  item *i = (item *)malloc(sizeof(item));
  i->key = strdup(key);
  i->value = strdup(value);

  return i;
}

static void destroy_item(item *i) {
  free(i->key);
  free(i->value);
  free(i);
}

static hash_table *new_ht_sized(const int base_size) {
  hash_table *ht = (hash_table *)malloc(sizeof(hash_table));
  ht->base_size = base_size;
  ht->size = next_prime(ht->base_size);
  ht->count = 0;
  ht->items = calloc(ht->size, sizeof(item *));
  return ht;
}

hash_table *new_ht() { return new_ht_sized(NUM_BUCKETS); }

void resize_ht(hash_table *ht, const int base_size) {
  if (base_size < NUM_BUCKETS) {
    return;
  }

  hash_table *ht_new = new_ht_sized(base_size);
  for (int i = 0; i < ht->size; i++) {
    item *itm = ht->items[i];
    if (itm != NULL && itm != &ITEM_DELETED) {
      insert(ht_new, itm->key, itm->value);
    }
  }

  const int tmp_size = ht->size;
  ht->size = ht_new->size;
  ht_new->size = tmp_size;

  item **tmp_items = ht->items;
  ht->items = ht_new->items;
  ht_new->items = tmp_items;

  destroy_hash_table(ht_new);
}

void resize_ht_up(hash_table *ht) {
  const int new_size = ht->base_size * 2;
  resize_ht(ht, new_size);
}

void resize_ht_down(hash_table *ht) {
  const int new_size = ht->base_size / 2;
  resize_ht(ht, new_size);
}

static int hash_func(const char *key, const int prime, const int num_buckets) {
  long hash = 0;
  int len = strlen(key);
  for (int i = 0; i < len; i++) {
    hash += (long)pow(prime, strlen(key) - (i + 1)) * key[i];
    hash %= num_buckets;
  }
  return hash;
}

static int get_hash(const char *key, const int num_buckets,
                    const int attempts) {
  const int hash_a = hash_func(key, PRIME_CONST_ONE, num_buckets);
  const int hash_b = hash_func(key, PRIME_CONST_TWO, num_buckets);
  return (hash_a + (attempts * (hash_b + 1))) % num_buckets;
}

void insert(hash_table *ht, const char *key, const char *value) {
  const int load = ht->count * 100 / ht->size;
  if (load > 70) {
    resize_ht_up(ht);
  }

  item *itm = new_item(key, value);
  int index = get_hash(key, ht->size, 0);
  item *current_item = ht->items[index];
  int i = 1;
  while (current_item != NULL && current_item != &ITEM_DELETED) {
    if (strcmp(current_item->key, key) == 0) {
      destroy_item(current_item);
      ht->items[index] = itm;
      return;
    }
    index = get_hash(itm->key, ht->size, i);
    current_item = ht->items[index];
    i++;
  }

  ht->items[index] = itm;
  ht->count++;
}

char *search(hash_table *ht, const char *key) {
  int index = get_hash(key, ht->size, 0);
  item *itm = ht->items[index];

  int i = 1;

  while (itm != NULL) {
    if (itm != &ITEM_DELETED) {
      if (strcmp(itm->key, key) == 0)
        return itm->value;
    }

    index = get_hash(key, ht->size, i);
    itm = ht->items[index];
    i++;
  }

  return NULL;
}

void deleted(hash_table *ht, const char *key) {
  const int load = ht->count * 100 / ht->size;
  if (load < 10) {
    resize_ht_down(ht);
  }
  int index = get_hash(key, ht->size, 0);
  item *itm = ht->items[index];
  int i = 1;

  while (itm != NULL) {
    if (itm != &ITEM_DELETED) {
      if (strcmp(itm->key, key) == 0) {
        destroy_item(itm);
        ht->items[index] = &ITEM_DELETED;
        return;
      }
    }
    index = get_hash(key, ht->size, i);
    itm = ht->items[index];
    i++;
  }

  ht->count--;
}

void destroy_hash_table(hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    item *itm = ht->items[i];
    if (itm != NULL && itm != &ITEM_DELETED) {
      destroy_item(itm);
    }
  }
  free(ht->items);
  free(ht);
}
