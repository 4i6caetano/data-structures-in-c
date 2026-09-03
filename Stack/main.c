#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    Stack* stack = createStack();
    if (stack == NULL)
    {
        printf("Fatal error: Failed to initialize the stack (out of memory).\n");
        return 1;
    }

    int choice = -1;
    double inputValue;
    double outputValue;

    while (choice != 0)
    {
        printf("\n============================\n");
        printf("         STACK MENU\n");
        printf("============================\n");
        printf("  1. Push (Insert)\n");
        printf("  2. Pop (Remove)\n");
        printf("  3. Peek (View top)\n");
        printf("  4. Print Stack\n");
        printf("  5. Check Space\n");
        printf("  6. Clear Stack (Clear/Trim)\n");
        printf("  0. Exit\n");
        printf("----------------------------\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Enter the value to push: ");
                if (scanf("%lf", &inputValue) == 1)
                {
                    if (push(stack, inputValue) == FUNCTION_SUCCESS)
                    {
                        printf(">> Value %.2f pushed successfully!\n", inputValue);
                    }
                }
                else
                {
                    printf(">> Error: Invalid value.\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                if (pop(stack, &outputValue) == FUNCTION_SUCCESS)
                {
                    printf(">> Popped value: %.2f\n", outputValue);
                }
                break;

            case 3:
                if (peek(stack, &outputValue) == FUNCTION_SUCCESS)
                {
                    printf(">> The value at the top is: %.2f\n", outputValue);
                }
                else
                {
                    printf(">> Could not peek (stack is empty or invalid).\n");
                }
                break;

            case 4:
                printStack(stack);
                break;

            case 5:
                checkStackSize(stack);
                printf("\n");
                break;

            case 6:
                if (clearStack(stack) == FUNCTION_SUCCESS)
                {
                    printf(">> Stack cleared and memory resized to initial capacity.\n");
                }
                else
                {
                    printf(">> Failed to clear the stack.\n");
                }
                break;

            case 0:
                printf(">> Exiting and freeing memory...\n");
                break;

            default:
                printf(">> Invalid option. Please try again.\n");
                break;
        }
    }

    freeStack(stack);
    
    return 0;
}