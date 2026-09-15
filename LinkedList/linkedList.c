 #include<stdio.h>
 
 #include "linkedList.h"

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    if(validate(linkedList) == NOT_VALID) return NULL;

    linkedList->header = NULL;
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

        printf("The list was initialized. ");

        return FUNCTION_SUCCESS;
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

        return FUNCTION_SUCCESS;
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

    if(position < 0)
    {
        printf("Position cannot be negative. ");
        return FUNCTION_FAILURE;
    }

    Node* node = malloc(sizeof(Node));
    if(validateNode(node) == NOT_VALID) return FUNCTION_FAILURE;

    node->value = value;

    Node* currentNode;
    Node* nextNode;
    // nextNode vai estar apontando exatamente aonde queremos inserir

    if(0 == position)
    {
        nextNode = linkedList->header;

        linkedList->header = node;
        linkedList->header->nextNode = nextNode;

        linkedList->quantityOfNodes++;

        return FUNCTION_SUCCESS;
    }

    else
    {

        currentNode = linkedList->header;
        nextNode = linkedList->header->nextNode;

        for(int index = 0; index < position -1; index++)
        {
            currentNode = nextNode;
            nextNode = nextNode->nextNode;
        }

        //here, the insertion happens
        currentNode->nextNode = node;
        node->nextNode = nextNode;

        linkedList->quantityOfNodes++;

        return FUNCTION_SUCCESS;
    }

}

int removeOfLinkedList(LinkedList* linkedList, int position)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    if(linkedList->quantityOfNodes == 0 || linkedList->header == NULL)
    {
        printf("There's no value to be removed from, the list is blank. ");
        return FUNCTION_FAILURE;
    }

    if(position >= linkedList->quantityOfNodes)
    {
        printf("The position is off limits. ");
        return FUNCTION_FAILURE;
    }

    if(position < 0)
    {
        printf("Position cannot be negative. ");
        return FUNCTION_FAILURE;
    }

    Node* currentNode = linkedList->header;
    Node* nextNode = linkedList->header->nextNode;

    if(position == 0)
    {
        free(linkedList->header);
        linkedList->header = nextNode;

        linkedList->quantityOfNodes--;

        if(linkedList->header == NULL)
        {
            printf("The list is now blank. ");
        }

        return FUNCTION_SUCCESS;
    }
    else
    {
        for(int index = 0; index < position - 1; index++)
        {
            currentNode = nextNode;
            nextNode = nextNode->nextNode;
        }

        currentNode->nextNode = nextNode->nextNode;
        free(nextNode);

        linkedList->quantityOfNodes--;

        return FUNCTION_SUCCESS;
    }

    }

int showLinkedListSize(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    int linkedListSize = linkedList->quantityOfNodes;

    printf("The linked list currently holds %d values. ", linkedListSize);

    return FUNCTION_SUCCESS;
}

int printLinkedList(LinkedList* linkedList)
{
    if(validate(linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    if(linkedList->header == NULL)
    {
        printf("\n  (lista vazia)\n\n");
        return FUNCTION_SUCCESS;
    }

    printf("\n  HEADER -> ");

    Node* currentNode = linkedList->header;
    while(currentNode != NULL)
    {
        printf("[ %.2f ]", currentNode->value);
        currentNode = currentNode->nextNode;
        if(currentNode != NULL) printf(" -> ");
    }

    printf(" -> NULL\n");
    printf("  Total de nós: %d\n\n", linkedList->quantityOfNodes);

    return FUNCTION_SUCCESS;
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

    free(currentNode);

    linkedList->header = NULL;
    linkedList->quantityOfNodes == 0;

    return FUNCTION_SUCCESS;
}

int freeLinkedList(LinkedList** linkedList)
{
    if(validate(*linkedList) == NOT_VALID) return FUNCTION_FAILURE;

    clearLinkedList(*linkedList);

    free(*linkedList);

    *linkedList = NULL;

    return FUNCTION_SUCCESS;
}