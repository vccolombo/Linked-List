#include <stdio.h>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList* list = createLinkedList();
    list = insertLinkedList(list, "test1", 10);
    list = insertLinkedList(list, "test2", 20);
    list = insertLinkedList(list, "test3", 30);
    printLinkedList(list);
    
    
    return 0;
}
