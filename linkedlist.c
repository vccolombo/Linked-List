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

  // If key already in list, update data
  LinkedList* search = searchLinkedList(*head, new_key);
  if (search != NULL) {
    search->data = new_data;
    return;
  }
  
  // else create new node

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
  if (list == NULL) {
    return NULL;
  }
  
  if(list->key == key) {
    return list;
  }

  return searchLinkedList(list->next, key);
}

void removeFromLinkedList(LinkedList* list, char* key) {

  if (list == NULL) {
    return;
  }

  if(list->key == key) {
    printf("It's the first element in the list. Wait for a future version to remove this node.\n");
    return;
  }

  while (list->next != NULL) {
    if(list->next->key == key) {
      LinkedList* to_remove = list->next;
      list->next = to_remove->next;

      free(to_remove);
      return;
    }
    list = list->next;
  }
  
}

void printLinkedList(LinkedList* list, void (*fptr)(void *)) {
  while (list != NULL) { 
        (*fptr)(list->data); 
        list = list->next; 
  }  
  printf("\n");
}
