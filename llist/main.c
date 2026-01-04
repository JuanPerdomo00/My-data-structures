#include "linked_list.h"
#include "utils.h"

int main() {
  LinkedList *list = new_list();

  insert_to_init(list, "Python", 1991);
  insert_to_init(list, "C", 1972);
  insert_to_init(list, "Zig", 2016);
	insert_to_end(list, "Go", 2009);
	
  print_list(list);
	
	delete_to_init(list);
	delete_to_init(list);
	
  print_list(list);
	
	delete_to_end(list);
	
	print_list(list);
	
	delete_to_end(list);
	
	print_list(list);
  destroy_list(list);

  return 0;
}
