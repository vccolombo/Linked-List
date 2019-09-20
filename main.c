#include <stdio.h>
#include "LinkedList.h"

void printNode(LinkedList* list) {
    if (list == NULL) {
        printf("Node is NULL\n");
        return;
    }
    printf("Key: %s  Value: %d\n", list->key, list->value);  
}

int main(int argc, char const *argv[])
{
    LinkedList* list = createLinkedList();
    list = insertLinkedList(list, "test1", 10);
    list = insertLinkedList(list, "test2", 20);
    list = insertLinkedList(list, "test3", 30);
    printf("Print entire list:\n");
    printLinkedList(list);

    printf("Print each position (test search):\n");
    LinkedList* achado;
    achado = searchLinkedList(list, "test1");
    printNode(achado);
    achado = searchLinkedList(list, "test2");
    printNode(achado);
    achado = searchLinkedList(list, "test3");
    printNode(achado);
    achado = searchLinkedList(list, "testError");
    printNode(achado);

    printf("Remove and print new list:\n");
    list = removeFromLinkedList(list, "test3");
    printLinkedList(list);
    
    return 0;
}
