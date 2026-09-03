#ifndef STACK
#define STACK

typedef enum
{
    STACK_IS_NOT_VALID = -1,
    STACK_IS_VALID = 1
} StackValidationState;

typedef enum
{
    STACK_IS_EMPTY,
    STACK_IS_FULL,
    STACK_HAS_SPACE
} StackState;



typedef enum
{
    FUNCTION_FAILURE = -1,
    FUNCTION_UNEXPECTED_RESPONSE,      
    FUNCTION_SUCCESS                   
} FunctionResult;

#define INITIAL_CAPACITY 5

typedef struct stack
{
    int quantityOfElements;
    int stackCapacity;
    double* stack;
}
Stack;

Stack* createStack();

int peek(Stack* stack, double* peekedValue);

int push(Stack*, double value);

int pop(Stack* stack, double* poppedValue);

int printStack(Stack* stack);

int checkStackSize(Stack* stack);

int clearStack(Stack* stack);

int freeStack(Stack* stack);

#endif