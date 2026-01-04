#ifndef LLIST_H
#define LLIST_H

typedef struct Node {
  char *name_lp;
  unsigned long age;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int length;
} LinkedList;

Node *new_node(char *name_lp, unsigned long age);
void destroy_node(Node *n);

LinkedList *new_list();
void destroy_list(LinkedList *list);

// Operations
void insert_to_init(LinkedList *list, char *name_lp, unsigned long age);
void insert_to_end(LinkedList *list, char *name_lp, unsigned long age);
void delete_to_init(LinkedList *list);
void delete_to_end(LinkedList *list);
#endif
