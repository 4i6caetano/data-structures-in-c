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
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    if(validate(linkedList) == NOT_VALID) return NULL;

    linkedList->header->nextNode = NULL;
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

    Node* node = malloc(sizeof(Node));
    if(validateNode(node) == NOT_VALID) return FUNCTION_FAILURE;

    node->value = value;
    node->nextNode = NULL;

    if(linkedList->header == NULL)
    {
        linkedList->header = node;
        return FUNCTION_SUCESS;
    }

    else
    {
        Node* nextNode = linkedList->header;
        Node* currentNode = linkedList->header->nextNode;

        while(nextNode != NULL)
        {
            currentNode = nextNode;
            nextNode = nextNode->nextNode;
        }
        
        currentNode->nextNode = node;

        return FUNCTION_SUCESS;
    }
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