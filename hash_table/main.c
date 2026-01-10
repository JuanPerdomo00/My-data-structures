#include "hash_table.h"
#include "utils.h"

int main() {
  hash_table *ht = new_ht();
  insert(ht, "Linus Tordvald", "Linux");
  insert(ht, "RMS", "GNU");
  insert(ht, "Andreas Rumf", "nim");
  print_ht_debug(ht);
  search_value(ht, "Linus Tordvald");
  search_value(ht, "Jakepys");
  deleted(ht, "Linus Tordvald");
	insert(ht, "Linus Tordvald", "Linux");
  print_ht_debug(ht);

  destroy_hash_table(ht);
}
