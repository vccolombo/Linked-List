#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct linkedList LinkedList;

struct linkedList {
  char* key;
  int value;
  LinkedList* next;
};

LinkedList* createLinkedList();
LinkedList* insertLinkedList(LinkedList* list, char* key, int value);
LinkedList* searchLinkedList(LinkedList* list, char* key);
LinkedList* removeFromLinkedList(LinkedList* list, char* key);
void printLinkedList(LinkedList* list);

#endif
