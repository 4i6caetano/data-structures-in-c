#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int stackValidation(Stack* stack)
{
    if(!stack)
    {
        printf("Initialization error. ");
        return STACK_IS_NOT_VALID;
    }

    return STACK_IS_VALID;
}

int stackCapacityCondition(Stack* stack)
{
    if(stack->stackCapacity == stack->quantityOfElements) return STACK_IS_FULL;

    if(stack->quantityOfElements == 0) return STACK_IS_EMPTY;

    return STACK_HAS_SPACE;
}

int doubleStackSize(Stack* stack)
{
    if(stackValidation(stack) ==  STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    double* temp = realloc(stack->stack, sizeof(double) * (stack->stackCapacity * 2));
    if(temp == NULL) return FUNCTION_FAILURE;
    else
    {
        stack->stack = temp;
        stack->stackCapacity = (stack->stackCapacity * 2);
    }

    return FUNCTION_SUCCESS;
}