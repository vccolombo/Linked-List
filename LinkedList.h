#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct linkedList LinkedList;

struct linkedList {
  char key[100];
  int value;
  LinkedList* next;
};

LinkedList* createLinkedList();
LinkedList* insertLinkedList(LinkedList* list, char key[100], int value);
LinkedList* searchLinkedList(LinkedList* list, char key[100]);
int removeFromLinkedList(LinkedList* list, char key[100]);

#endif
