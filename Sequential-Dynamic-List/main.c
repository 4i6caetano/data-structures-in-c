#include <stdio.h>
#include <stdlib.h>

#include "sequentialDynamicList.h"

static void printMenu(void)
{
    printf("\n===== DynamicList - Menu =====\n");
    printf("1. Append element (end of list)\n");
    printf("2. Add element at position\n");
    printf("3. Remove last element\n");
    printf("4. Remove element at position\n");
    printf("5. Print list\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main(void)
{
    DynamicList* dynamicList;
    dynamicList = createDynamicList();

    int choice = -1;
    int position;
    float value;

    while (choice != 0)
    {
        printMenu();
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Value to append: ");
                scanf("%f", &value);
                appendElement(dynamicList, value);
                break;

            case 2:
                printf("Position: ");
                scanf("%d", &position);
                printf("Value: ");
                scanf("%f", &value);
                addElementOnPosition(dynamicList, position, value);
                break;

            case 3:
                if (removeLastElement(dynamicList) == FUNCTION_SUCCESS)
                    printf("Last element removed.\n");
                else
                    printf("Could not remove: list invalid.\n");
                break;

            case 4:
                printf("Position to remove: ");
                scanf("%d", &position);
                if (removeElementOnPosition(dynamicList, position) != FUNCTION_SUCCESS)
                    printf("Could not remove at that position.\n");
                break;

            case 5:
                printList(dynamicList);
                break;

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    freeList(dynamicList);
    return 0;
}