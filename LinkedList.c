#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>


LinkedList* createLinkedList() {
  LinkedList* root = malloc(sizeof(LinkedList));
  strcpy(root->key, "\0");
  root->value = NULL;
  root->next = NULL;

  return root;
}

LinkedList* insertLinkedList(LinkedList* list, char key[100], int value) {
  if (list->next == NULL) {
    LinkedList* insert = malloc(sizeof(LinkedList));
    list->next = insert;

    strcpy(insert->key, key);
    insert->value = value;
    insert->next = NULL;

    return insert;
  }

  return insertLinkedList(list->next, key, value);
}

LinkedList* searchLinkedList(LinkedList* list, char key[100]) {
  if (strcmp(list->key, key) == 0) {
    return list;
  }
  if (list->next == NULL) {
    return NULL;
  }
  return searchLinkedList(list->next, key);
}

int removeFromLinkedList(LinkedList* list, char key[100]) {
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
