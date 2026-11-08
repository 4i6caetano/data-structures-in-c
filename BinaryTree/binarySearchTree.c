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
    binarySearchTree->height = 0; 
    
    return binarySearchTree;
}