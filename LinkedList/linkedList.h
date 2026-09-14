#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum
{
    NOT_VALID = -1,
    VALID = 1
} LinkedListValidationState;

typedef enum
{
    FUNCTION_FAILURE = -1,
    FUNCTION_UNEXPECTED_BEHAVIOR,
    FUNCTION_SUCCESS
} FunctionState;

typedef enum
{

    LIST_IS_EMPTY,
    LIST_IS_NOT_EMPTY

} ListCapacityState;

typedef struct node Node;

typedef struct linkedList LinkedList;

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

#include "utils.h"

#endif