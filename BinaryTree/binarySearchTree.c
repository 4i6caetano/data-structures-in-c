#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"

typedef struct node
{

    double value;
    Node* left_node;
    Node* right_node;

} Node;

typedef struct binarySearchTree
{
    Node* root;
    int quantityOfNodes;
    int height;
} BinarySearchTree;

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