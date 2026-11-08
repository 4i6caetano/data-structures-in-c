#include <stdio.h>
#include <stdlib.h>

#include "binaryTree.h"

typedef struct node
{

    double value;
    Node* left_node;
    Node* right_node;

} Node;

typedef struct binarytree
{
    Node* root;
    int quantityOfNodes;
    int depth;
} BinaryTree;

typedef enum
{
    
    FAILURE = -1,
    UNEXPECTED_BEHAVIOR,
    SUCESS

} ValidationState;

BinaryTree* createNewBinaryTree(void)
{
    BinaryTree* binaryTree = malloc(sizeof(BinaryTree));
    if(!binaryTree) return NULL;

    binaryTree->root = NULL;
    binaryTree->quantityOfNodes = 0;
    binaryTree->depth = 0; 
    
    return binaryTree;
}