#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


LinkedList* createLinkedList() {
  LinkedList* root = NULL;

  return root;
}

void pushLinkedList(LinkedList** head, key_type* new_key, void* new_data, size_t data_size) {
  LinkedList* to_add = (LinkedList*) malloc(sizeof(LinkedList));
  if (to_add == NULL) {
    exit(0); // No memory to insert
  }

  to_add->key = new_key;
  to_add->data = malloc(data_size);
  to_add->next = (*head);

  int i;
  for (i = 0; i < data_size; i++) {
    *(char *)(to_add->data+i) = *(char*)(new_data+i);
  }
  

  (*head) = to_add;
}

LinkedList* searchLinkedList(LinkedList* list, key_type* key) {
  if (strcmp(list->key, key) == 0) {
    return list;
  }
  if (list->next == NULL) {
    return NULL;
  }
  return searchLinkedList(list->next, key);
}

 LinkedList* removeFromLinkedList(LinkedList* list, char* key) {
  if (list == NULL) {
    return NULL;
  }

  // Check if the current element is the one to be removed
  if (strcmp(list->key, key) == 0) {
    LinkedList* temp;

    temp = list->next;

    free(list);

    return temp;
  }

  list->next = removeFromLinkedList(list->next, key);

  return list;
  
}

void printLinkedList(LinkedList* list, void (*fptr)(void *)) {
  while (list != NULL) { 
        (*fptr)(list->data); 
        list = list->next; 
  }  
}
