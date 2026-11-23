#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"

static void printMenu(void)
{
    printf("\n===== Binary Search Tree - Menu =====\n");
    printf("1.  Initialize tree (set root)\n");
    printf("2.  Insert value\n");
    printf("3.  Find value\n");
    printf("4.  Remove value\n");
    printf("5.  Find maximum value\n");
    printf("6.  Remove maximum value\n");
    printf("7.  Find minimum value\n");
    printf("8.  Remove minimum value\n");
    printf("9.  Print Pre-Order\n");
    printf("10. Print In-Order\n");
    printf("11. Print Post-Order\n");
    printf("12. Get tree height\n");
    printf("13. Print visual tree\n");
    printf("14. Clear tree\n");
    printf("0.  Exit (Delete tree)\n");
    printf("Choice: ");
}

int main(void)
{
    BinarySearchTree* bst = createNewBinarySearchTree();
    if(bst == NULL)
    {
        printf("Failed to create Binary Search Tree.\n");
        return 1;
    }

    int choice = -1;
    double value;

    while(choice != 0)
    {
        printMenu();
        if(scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }

        switch(choice)
        {
            case 1:
                printf("Root value: ");
                scanf("%lf", &value);
                initializeBinarySearchTree(bst, value);
                printf("\n");
                break;

            case 2:
                printf("Value to insert: ");
                scanf("%lf", &value);
                insertValueInBinarySearchTree(bst, value);
                printf("\n");
                break;

            case 3:
                printf("Value to find: ");
                scanf("%lf", &value);
                findValueInBinarySearchTree(bst, value);
                printf("\n");
                break;

            case 4:
                printf("Value to remove: ");
                scanf("%lf", &value);
                removeValueInBinarySearchTree(bst, value);
                printf("\n");
                break;

            case 5:
                findMaximumValue(bst);
                printf("\n");
                break;

            case 6:
                removeMaximumValue(bst);
                printf("\n");
                break;

            case 7:
                findMinimumValue(bst);
                printf("\n");
                break;

            case 8:
                removeMinimumValue(bst);
                printf("\n");
                break;

            case 9:
                printf("Pre-Order: ");
                preOrder(bst);
                printf("\n");
                break;

            case 10:
                printf("In-Order: ");
                inOrder(bst);
                printf("\n");
                break;

            case 11:
                printf("Post-Order: ");
                postOrder(bst);
                printf("\n");
                break;

            case 12:
                getTreeHeight(bst);
                printf("\n");
                break;

            case 13:
                printBinarySearchTree(bst);
                break;

            case 14:
                clearBinarySearchTree(bst);
                printf("\n");
                break;

            case 0:
                printf("Exiting...\n");
                if(deleteBinarySearchTree(bst) == FAILURE)
                {
                    printf("Deletion cancelled.\n");
                    choice = -1;
                }
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
