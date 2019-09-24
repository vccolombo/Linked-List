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

int main(int argc, char const *argv[]) {
    LinkedList* list = createLinkedList(); 
    int vetor[] = {1, 2, 3, 4, 5};
    pushLinkedList(&list, "chave1", &vetor[0], sizeof(int));
    pushLinkedList(&list, "chave2", &vetor[1], sizeof(int));
    pushLinkedList(&list, "chave3", &vetor[2], sizeof(int));
    pushLinkedList(&list, "chave4", &vetor[3], sizeof(int));
    pushLinkedList(&list, "chave5", &vetor[4], sizeof(int));
    printLinkedList(list, printInt);

    pushLinkedList(&list, "chave5", &vetor[0], sizeof(int));
    printLinkedList(list, printInt);

    printInt(searchLinkedList(list, "chave3")->data);
    printf("\n");

    return 0;
}
