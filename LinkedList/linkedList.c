 #include<stdio.h>
 
 #include "linkedList.h"

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    if(validate(linkedList) == NOT_VALID) return NULL;

    linkedList->header->nextNode = NULL;
    linkedList->header->value = -1;
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

    if(linkedList->header->value == -1)
    {
        linkedList->header = node;
        linkedList->quantityOfNodes++;
        return FUNCTION_SUCESS;
    }

    else
    {
        Node* currentNode = linkedList->header;
        Node* nextNode = currentNode->nextNode;

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

    if(checkListCapacity(linkedList) == LIST_IS_EMPTY)
    {
        printf("List is already empty. ");
        return FUNCTION_FAILURE;
    }

    Node* currentNode = linkedList->header;
    Node* nextNode = currentNode->nextNode;

    while(nextNode != NULL)
    {
        free(currentNode);
        currentNode = nextNode;
        nextNode = nextNode->nextNode;
    }

    return FUNCTION_SUCESS;
}

int freeLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    clearLinkedList(linkedList);

    free(linkedList);
}