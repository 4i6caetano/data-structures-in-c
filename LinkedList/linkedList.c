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
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    Node* node = malloc(sizeof(Node));
    if(validateNode(node) == NOT_VALID) return FUNCTION_FAILURE;

    node->value = value;
    node->nextNode = NULL;

    if(linkedList->header == NULL)
    {
        linkedList->header = node;
        linkedList->quantityOfNodes++;
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
        linkedList->quantityOfNodes++;

        return FUNCTION_SUCESS;
    }
}

int insertOnLinkedList(double value, int position, LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    if(position > linkedList->quantityOfNodes)
    {
        printf("The position is bigger than the current number of elements. If you wish to append, use the Append command.");
        return FUNCTION_FAILURE;
    }

    Node* node = malloc(sizeof(Node));
    if(validateNode(node) == NOT_VALID) return FUNCTION_FAILURE;

    node->value = value;

    Node* currentNode = linkedList->header;
    Node* nextNode = linkedList->header->nextNode;
    // nextNode vai estar apontando exatamente aonde queremos inserir

    for(int i = 0; i < position; i++)
    {
        currentNode = nextNode;
        nextNode = nextNode->nextNode;
    }

    //here, the insertion happens
    currentNode->nextNode = node;
    node->nextNode = nextNode;

    linkedList->quantityOfNodes++;

    return FUNCTION_SUCESS;

}

int removeOfLinkedList(LinkedList* linkedList, int position)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;
}

int showLinkedListSize(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    int linkedListSize = linkedList->quantityOfNodes;

    printf("The linked list currently holds %d values. ", &linkedListSize);

    return FUNCTION_SUCESS;
}

int printLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;
}

int clearLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;
}

int freeLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;
}