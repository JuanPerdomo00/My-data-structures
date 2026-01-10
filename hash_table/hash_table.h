#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PRIME_CONST_ONE 163
#define PRIME_CONST_TWO 167
#define NUM_BUCKETS 10

typedef struct {
  char *key;
  char *value;
} item;

typedef struct {
  int size;
  int base_size;
  int count;
  item **items;
} hash_table;

// Sentinel
static item ITEM_DELETED = {NULL, NULL};

static item *new_item(const char *key, const char *value);
static void destroy_item(item *i);
static hash_table *new_ht_sized(const int base_size);
static void resize_ht(hash_table *ht, const int base_size);
static void resize_ht_up(hash_table *ht);
static void resize_ht_down(hash_table *ht);
hash_table *new_ht();

static int hash_func(const char *key, const int prime, const int num_buckets);
static int get_hash(const char *key, const int num_buckets, const int attempts);

void insert(hash_table *ht, const char *key, const char *value);
char *search(hash_table *ht, const char *key);
void deleted(hash_table *ht, const char *key);

void destroy_hash_table(hash_table *ht);

#endif
