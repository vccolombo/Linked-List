#include "linkedlist.h"
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

void printLinkedList(LinkedList* list) {
  LinkedList* curr;
  for (curr = list; curr; curr = curr->next) {
    printf("Key: %s  Value: %d\n", curr->key, curr->value);
  }
  
}
