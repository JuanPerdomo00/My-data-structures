#include "utils.h"
#include "linked_list.h"
#include <stdio.h>

void print_list(LinkedList *list) {
  if (list->head == NULL) {
    printf("List(void)\n");
    return;
  }

  Node *current = list->head;
  printf("length: %d\n", list->length);
  printf("Head -> ");
  while (current != NULL) {
    printf("(lang=%s, age=%lu) -> ", current->name_lp, current->age);
    current = current->next;
  }
  printf("NULL\n");
}
