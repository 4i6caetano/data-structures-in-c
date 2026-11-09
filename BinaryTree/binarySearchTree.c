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
    binarySearchTree->height = -1; 
    
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