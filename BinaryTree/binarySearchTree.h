#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FAILURE = -1,
    UNEXPECTED_BEHAVIOR,
    SUCCESS
} ValidationState;

typedef struct node Node;

typedef struct binarySearchTree BinarySearchTree;

BinarySearchTree* createNewBinarySearchTree(void);

int initializeBinarySearchTree(BinarySearchTree* binarySearchTree, double value);

int insertValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value);

int removeValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value);

int findValueInBinarySearchTree(BinarySearchTree* binarySearchTree, double value);

int removeLastValueInBinarySearchTree(BinarySearchTree* binarySearchTree);

int clearBinarySearchTree(BinarySearchTree* binarySearchTree);

int deleteBinarySearchTree(BinarySearchTree* binarySearchTree);

#endif