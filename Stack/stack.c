#include "stdio.h"
#include "stdlib.h"

#include "stack.h"
#include "utils.h"

Stack* createStack()
{
    Stack* stack = malloc(sizeof(Stack));

    if(stack == NULL) return NULL;

    stack->stack = malloc(sizeof(double) * INITIAL_CAPACITY);
    if(stack->stack == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->stackCapacity = INITIAL_CAPACITY;
    stack->quantityOfElements = 0;

    return stack;
}

int peek(Stack* stack, double* peekedValue)
{
    if(stackValidation(stack) ==  STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(!peekedValue) return FUNCTION_FAILURE;

    if(stackCapacityCondition(stack) == STACK_IS_EMPTY) return FUNCTION_FAILURE;

    *peekedValue = stack->stack[stack->quantityOfElements - 1];

    return FUNCTION_SUCCESS;
}

int push(Stack* stack, double value)
{
    if(stackValidation(stack) == STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stackCapacityCondition(stack) == STACK_IS_FULL)
    {
        printf("The stack is full. Doubling its size. ");
        if(doubleStackSize(stack) == FUNCTION_FAILURE)
        {
            printf("The stack cannot be doubled because of memory capacity. ");
            return FUNCTION_FAILURE;
        }
    }

    stack->stack[stack->quantityOfElements] = value;
    stack->quantityOfElements++;

    return FUNCTION_SUCCESS;
}

int pop(Stack* stack, double* poppedValue)
{
    if(stackValidation(stack) ==  STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stackCapacityCondition(stack) == STACK_IS_EMPTY)
    {
        printf("Stack is empty. No value to remove. ");
        return FUNCTION_FAILURE;
    }

    stack->quantityOfElements--;

    if(poppedValue != NULL) *poppedValue = stack->stack[stack->quantityOfElements];

    return FUNCTION_SUCCESS;
}

int printStack(Stack* stack)
{
    if(stackValidation(stack) ==  STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    printf("\n");
    printf("  ┌─────────────┐\n");

    if (stack->quantityOfElements == 0)
    {
        printf("  │   (vazia)   │\n");
    }
    else
    {
        for (int i = stack->quantityOfElements - 1; i >= 0; i--)
        {
            if (i == stack->quantityOfElements - 1)
                printf("  │ %9.2f │  <- topo\n", stack->stack[i]);
            else
                printf("  │ %9.2f │\n", stack->stack[i]);
        }
    }

    printf("  └─────────────┘\n");
    printf("  %d / %d ocupados\n\n", stack->quantityOfElements, stack->stackCapacity);

    return FUNCTION_SUCCESS;
}

int checkStackSize(Stack* stack)
{
    if(stackValidation(stack) == STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stackCapacityCondition(stack) == STACK_IS_EMPTY)
    {
        printf("The stack is currently empty. ");
        return FUNCTION_SUCCESS;
    }

    if(stackCapacityCondition(stack) == STACK_HAS_SPACE)
    {
        printf("The stack has %d space left", (stack->stackCapacity - stack->quantityOfElements));
        return FUNCTION_SUCCESS;
    }

    else
    {
        printf("The stack is currently full. ");
        return FUNCTION_SUCCESS;
    }
}

int clearStack(Stack* stack)
{
    if(stackValidation(stack) == STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(!stack->stack) return FUNCTION_FAILURE;

    double* temporaryPointer = realloc(stack->stack, sizeof(double) * INITIAL_CAPACITY);

    if(!temporaryPointer)
    {
        return FUNCTION_FAILURE;
    }

    stack->stack = temporaryPointer;

    stack->stackCapacity = INITIAL_CAPACITY;
    stack->quantityOfElements = 0;

    return FUNCTION_SUCCESS;
}

int freeStack(Stack* stack)
{
    if(stackValidation(stack) ==  STACK_IS_NOT_VALID) return FUNCTION_FAILURE;

    free(stack->stack);
    stack->quantityOfElements = 0;
    stack->stackCapacity = 0;

    free(stack);

    return FUNCTION_SUCCESS;
}