#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"
#include "properties.h"
#include "utils.h"

BinarySearchTree* createNewBinarySearchTree(void)
{
    BinarySearchTree* binarySearchTree = malloc(sizeof(BinarySearchTree));
    if(!binarySearchTree) return NULL;

    binarySearchTree->root = NULL;
    binarySearchTree->quantityOfNodes = 0;
    binarySearchTree->height = NOT_INITIALIZED_HEIGHT;
    
    return binarySearchTree;
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

static int insertRecursion(Node* currentNode, double value)
{
    if(currentNode->value == value)
    {
        printf("The tree does not support doubled values. ");
        return FAILURE;
    }

    else if(currentNode->value > value) //LEFT
    {
        if(currentNode->left_node != NULL) //if THERE IS a value, continue recursion
        {
            return insertRecursion(currentNode->left_node, value);
        }

        else // if its NULL, insert
        {
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) return FAILURE;
            newNode->value = value;
            newNode->left_node = NULL;
            newNode->right_node = NULL;

            currentNode->left_node = newNode;
            return SUCCESS;
        }
    }

    else //RIGHT
    {
        if(currentNode->right_node != NULL) //if THERE IS a value, continue recursion
        {
            return insertRecursion(currentNode->right_node, value);
        }

        else // if its NULL, insert
        {
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) return FAILURE;
            newNode->value = value;
            newNode->left_node = NULL;
            newNode->right_node = NULL;

            currentNode->right_node = newNode;
            return SUCCESS;
        }
    }
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

static int findRecursion(Node* currentNode, double value, int* depth)
{

    if(currentNode->value == value)
    {
        return SUCCESS;
    }

    else if(currentNode->value > value) //LEFT
    {
        if(currentNode->left_node == NULL)
        {
            return FAILURE;
        }

        else
        {
            (*depth)++;
            return findRecursion(currentNode->left_node, value, depth);
        }
    }

    else //RIGHT
    {
        if(currentNode->right_node == NULL)
        {
            return FAILURE;
        }

        else
        {
            (*depth)++;
            return findRecursion(currentNode->right_node, value, depth);
        }
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

static void clearRecursive(Node* node)
{

    if(node == NULL) return;

    clearRecursive(node->left_node);
    clearRecursive(node->right_node);

    free(node);

    return;
    
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