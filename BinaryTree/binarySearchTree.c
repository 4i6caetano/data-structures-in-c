#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"
#include "recursion.h"

BinarySearchTree* createNewBinarySearchTree(void)
{
    BinarySearchTree* binarySearchTree = malloc(sizeof(BinarySearchTree));
    if(!binarySearchTree) return NULL;

    binarySearchTree->root = NULL;
    binarySearchTree->quantityOfNodes = 0;
    binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
    
    return binarySearchTree;
}

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

int initializeBinarySearchTree(BinarySearchTree* binarySearchTree, double value)
{
    if(!binarySearchTree) return FAILURE;

    if(binarySearchTree->root != NULL)
    {
        printf("This tree is already initialized. ");
        return FAILURE;
    }

    Node* node = malloc(sizeof(Node));
    if(!node) return FAILURE;

    binarySearchTree->root = node;

    node->value = value;
    node->left_node = NULL;
    node->right_node = NULL;

    binarySearchTree->quantityOfNodes++;
    binarySearchTree->height = 0;

    return SUCCESS;
}

int insertValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value)
{
    if(checkValidation(binarySearchTree) ==  FAILURE) return FAILURE;

    if(insertRecursion(binarySearchTree->root, value) == SUCCESS)
    {
        binarySearchTree->quantityOfNodes++;
        printf("The %f value was successfully inserted. ", value);
        return SUCCESS;
    }

    else
    {
        printf("There was an error inserting the value. ");
        return FAILURE;
    }
}

int findValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value)
{
    if(checkValidation(binarySearchTree) ==  FAILURE) return FAILURE;

    int depth = 0;

    if(findRecursion(binarySearchTree->root, value, &depth) == SUCCESS)
    {
        printf("The %f value was found in depth %d! ", value, depth);
        return SUCCESS;
    } 

    else
    {
        printf("There's no such value in the tree. However, you can try another one, if you want! ");
        return FAILURE;
    }
}

int clearBinarySearchTree(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    clearRecursive(binarySearchTree->root);

        binarySearchTree->root = NULL;
        binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
        binarySearchTree->quantityOfNodes = 0;

        printf("Tree was completely cleared.\nIf you want to create another, remember to initialize it. \n If you won't use it anymore, remember to delete the tree. ");
        return SUCCESS;
}

int deleteBinarySearchTree(BinarySearchTree* binarySearchTree)
{
    if(!binarySearchTree) return FAILURE;

    if(binarySearchTree->root != NULL)
    {
        char answer;
        printf("The tree will be completely deleted. Do you want to continue? (y/n)");
        scanf("%c", &answer);
        if(answer == 'n') return FAILURE;
        else
        {
            clearBinarySearchTree(binarySearchTree);
        }
    }

    free(binarySearchTree);

    return SUCCESS;
}

int removeValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    if(removeValueRecursive(binarySearchTree->root, NULL, value) == SUCCESS)
    {
        printf("The value '%f' was successfully removed. ", value);
        binarySearchTree->quantityOfNodes--;

        if(binarySearchTree->quantityOfNodes == 0) // REMOVED THE ROOT
        {
            binarySearchTree->root = NULL;
            binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
        }

        return SUCCESS;
    }

    else //FAILURE
    {
        printf("The value could not be found in the tree. ");
        return FAILURE;
    }
}

int findMaximumValue(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    if(binarySearchTree->root->right_node == NULL) // the biggest value is the root
    {
        printf("The biggest value in the tree is the root itself, '%f'. ", binarySearchTree->root->value);
        return SUCCESS;
    }

    else
    {
        Node* parentNode = maximumSearchRecursive(binarySearchTree->root);
        printf("The biggest value in the tree is '%f'. ", parentNode->right_node->value);
        return SUCCESS;
    }
}

int removeMaximumValue(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    if(binarySearchTree->root->right_node == NULL) // the root itself is the biggest value
    {
        Node* oldRoot = binarySearchTree->root;
        printf("The greatest removed value was the root, '%f'. ", oldRoot->value);

        binarySearchTree->root = oldRoot->left_node; // becomes NULL if there was only 1 node
        free(oldRoot);
        binarySearchTree->quantityOfNodes--;

        if(binarySearchTree->quantityOfNodes == 0)
        {
            binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
            printf("Remember to initialize the tree again. ");
        }

        return SUCCESS;
    }

    else
    {
        Node* parentNode = maximumSearchRecursive(binarySearchTree->root);
        Node* maxNode = parentNode->right_node;

        printf("The greatest removed value was '%f'. ", maxNode->value);

        parentNode->right_node = maxNode->left_node; // preserves left child if it exists, otherwise NULL
        free(maxNode);
        binarySearchTree->quantityOfNodes--;

        return SUCCESS;
    }
}

int findMinimumValue(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    if(binarySearchTree->root->left_node == NULL) // the smallest value is the root
    {
        printf("The smallest value in the tree is the root, '%f'. ", binarySearchTree->root->value);
        return SUCCESS;
    }

    else
    {
        Node* parentNode = minimumSearchRecursive(binarySearchTree->root);
        printf("The smallest value in the tree is '%f'. ", parentNode->left_node->value);
        return SUCCESS;
    }
}

int removeMinimumValue(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    if(binarySearchTree->root->left_node == NULL) // the root itself is the smallest value
    {
        Node* oldRoot = binarySearchTree->root;
        printf("The smallest removed value was the root, '%f'. ", oldRoot->value);

        binarySearchTree->root = oldRoot->right_node; // becomes NULL if there was only 1 node
        free(oldRoot);
        binarySearchTree->quantityOfNodes--;

        if(binarySearchTree->quantityOfNodes == 0)
        {
            binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
            printf("Remember to initialize the tree again. ");
        }

        return SUCCESS;
    }

    else
    {
        Node* parentNode = minimumSearchRecursive(binarySearchTree->root);
        Node* minNode = parentNode->left_node;

        printf("The smallest removed value was '%f'. ", minNode->value);

        parentNode->left_node = minNode->right_node; // preserves right child if it exists, otherwise NULL
        free(minNode);
        binarySearchTree->quantityOfNodes--;

        return SUCCESS;
    }
}

int preOrder(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    recursivePreOrder(binarySearchTree->root);
    return SUCCESS;
}

int inOrder(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    recursiveInOrder(binarySearchTree->root);
    return SUCCESS;
}

int postOrder(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    recursivePostOrder(binarySearchTree->root);
    return SUCCESS;
}

int getTreeHeight(BinarySearchTree* binarySearchTree)
{
    if(checkValidation(binarySearchTree) == FAILURE) return FAILURE;

    int height = getTreeHeightRecursive(binarySearchTree->root);
    binarySearchTree->height = height;

    printf("The tree height is %d. ", height);
    return height;
}