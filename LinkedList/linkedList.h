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
    FUNCTION_SUCESS
} FunctionState;

typedef struct node Node;

typedef struct linkedList LinkedList;

#include "utils.h"

#endif