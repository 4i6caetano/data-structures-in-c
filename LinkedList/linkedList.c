 #include<stdio.h>
 
 #include "linkedList.h"
 
 typedef struct node
 {

    double value;
    Node* nextNode;

 } Node;
 
 typedef struct linkedList
{

    Node* header;
    int quantityOfNodes;

} LinkedList;

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList;
    if(validate(linkedList) == NOT_VALID) return NULL;

    linkedList->header = NULL;
    linkedList->quantityOfNodes = 0;

    return linkedList;
}

int appendOnLinkedList(double value, LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int insertOnLinkedList(double value, int position, LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int removeOfLinkedList(LinkedList* linkedList, int position)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int showLinkedListSize(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int printLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int clearLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}

int freeLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return NULL;
}