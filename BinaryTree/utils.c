#include <stdio.h>
#include<stdlib.h>

#include "binarySearchTree.h"

int checkValidation(BinarySearchTree* binarySearchTree)
{
    if(!binarySearchTree) return FAILURE;

    if(binarySearchTree->root == NULL)
    {
        printf("The tree was not initialized.");
        return FAILURE;
    }

    return SUCCESS;
}