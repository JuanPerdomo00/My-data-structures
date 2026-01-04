
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

Node* new_node(char* name_lp, unsigned long age) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->name_lp = name_lp;
  node->age = age;
  node->next = NULL;
  return node;
}

void destroy_node(Node* n) {
  if (n == NULL) {
    return;
  }
  free(n);
}

LinkedList* new_list() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->length = 0;
  return list;
}

void insert_to_init(LinkedList* list, char* name_lp, unsigned long age) {
  if (list->head == NULL) {
    list->head = new_node(name_lp, age);
    list->length++;
    return;
  }

  Node* head = list->head;
  Node* node = new_node(name_lp, age);
  list->head = node;
  list->head->next = head;
  list->length++;
}

void delete_to_init(LinkedList* list) {
  if (list->head == NULL) {
    return;
  }

  Node* second = list->head->next;
  Node* first = list->head;
  list->head = second;
  destroy_node(first);
  list->length--;
}

void insert_to_end(LinkedList* list, char* name_lp, unsigned long age) {
  if (list->head == NULL) {
    list->head = new_node(name_lp, age);
    list->length++;
    return;
  }

  Node* current = list->head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node(name_lp, age);
  list->length++;
}

void delete_to_end(LinkedList* list) {
  if (list->head == NULL) {
    return;
  }

  if (list->head->next == NULL) {
    Node* remove = list->head;
    list->head = NULL;
    destroy_node(remove);
    list->length--;
    return;
  }

  Node* current = list->head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  Node* deleted = current->next;
  current->next = NULL;
  destroy_node(deleted);
  list->length--;
}

void destroy_list(LinkedList* list) {
  if (list->head == NULL) {
    free(list);
    return;
  }

  Node* current = list->head;
  while (current != NULL) {
    destroy_node(current);
    current = current->next;
  }
  free(list);
}
