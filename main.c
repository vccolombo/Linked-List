#include <stdio.h>
#include "linkedlist.h"

// Function to print an integer 
void printInt(void *n) 
{ 
   printf(" %d", *(int *)n); 
} 
  
// Function to print a float 
void printFloat(void *f) 
{ 
   printf(" %f", *(float *)f); 
} 

void printChar(void *c) {
    printf("%c", *(char *)c);
}

int main(int argc, char const *argv[]) {
    printf("Creating list...\n");
    LinkedList* list = createLinkedList(); 

    printf("Testing insertion...\n");
    int vetor[] = {1, 2, 3, 4, 5};
    pushLinkedList(&list, "chave1", &vetor[0], sizeof(int));
    pushLinkedList(&list, "chave2", &vetor[1], sizeof(int));
    pushLinkedList(&list, "chave3", &vetor[2], sizeof(int));
    pushLinkedList(&list, "chave4", &vetor[3], sizeof(int));
    pushLinkedList(&list, "chave5", &vetor[4], sizeof(int));
    printLinkedList(list, printInt);

    printf("Testing insertion in existent key...\n");
    pushLinkedList(&list, "chave4", &vetor[0], sizeof(int));
    printLinkedList(list, printInt);

    printf("Testing search...\n");
    printInt(searchLinkedList(list, "chave3")->data);
    printf("\n");
    printInt(searchLinkedList(list, "chave1")->data);
    printf("\n");
    printInt(searchLinkedList(list, "chave5")->data);
    printf("\n");


    printf("Testing removals...\n");    
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chave5");
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chave1");
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chave3");
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chaveDur");
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chave4");
    printLinkedList(list, printInt);
    removeFromLinkedList(&list, "chave2");
    printLinkedList(list, printInt);

    return 0;
}
