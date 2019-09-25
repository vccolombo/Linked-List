#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>

#define key_type char

typedef struct linkedList LinkedList;

struct linkedList {
  key_type* key;
  void *data;
  LinkedList* next;
};

LinkedList* createLinkedList();
void pushLinkedList(LinkedList** head, key_type* key, void* new_data, size_t data_size);
LinkedList* searchLinkedList(LinkedList* list, key_type* key);
void removeFromLinkedList(LinkedList** list, key_type* key);
void printLinkedList(LinkedList* list, void (*fptr)(void *));

#endif
