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
    printLinkedList(list, printInt);
    return 0;
}
