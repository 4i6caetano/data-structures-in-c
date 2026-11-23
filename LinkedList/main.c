#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

static void printMenu(void)
{
    printf("\n===== LinkedList - Menu =====\n");
    printf("1. Append \n");
    printf("2. Insert in position\n");
    printf("3. Remove in position\n");
    printf("4. Print list\n");
    printf("5. Show list size\n");
    printf("6. Clear list\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main(void)
{
    LinkedList* linkedList = createLinkedList();
    if (linkedList == NULL)
    {
        printf("Failed to create list.\n");
        return 1;
    }

    int choice = -1;
    int position;
    double value;

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
                scanf("%lf", &value);
                appendOnLinkedList(value, linkedList);
                break;

            case 2:
                printf("Position (0-indexed): ");
                scanf("%d", &position);
                printf("Value: ");
                scanf("%lf", &value);
                insertOnLinkedList(value, position, linkedList);
                break;

            case 3:
                printf("Position to remove (0-indexed): ");
                scanf("%d", &position);
                removeOfLinkedList(linkedList, position);
                break;

            case 4:
                printLinkedList(linkedList);
                break;

            case 5:
                showLinkedListSize(linkedList);
                break;

            case 6:
                clearLinkedList(linkedList);
                break;

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    freeLinkedList(&linkedList);
    return 0;
}