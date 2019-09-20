#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


LinkedList* createLinkedList() {
  LinkedList* root = NULL;

  return root;
}

LinkedList* insertLinkedList(LinkedList* list, char* key, int value) {
  LinkedList* to_add = (LinkedList*) malloc(sizeof(LinkedList));
  if (to_add == NULL) {
    exit(0); // No memory to insert
  }
  
  to_add->key = key;
  to_add->value = value;
  to_add->next = list;
  list = to_add;

  return list;
}

LinkedList* searchLinkedList(LinkedList* list, char* key) {
  if (strcmp(list->key, key) == 0) {
    return list;
  }
  if (list->next == NULL) {
    return NULL;
  }
  return searchLinkedList(list->next, key);
}

int removeFromLinkedList(LinkedList* list, char* key) {
  if (list->next == NULL) {
    return -1;
  }
  if (strcmp(list->next->key, key) == 0) {
    LinkedList* remover = list->next;
    list->next = remover->next;
    
    free(remover);
    return 0;
  }

  return removeFromLinkedList(list->next, key);
}

void printLinkedList(LinkedList* list) {
  LinkedList* curr;
  for (curr = list; curr; curr = curr->next) {
    printf("Key: %s  Value: %d\n", curr->key, curr->value);
  }
  
}
