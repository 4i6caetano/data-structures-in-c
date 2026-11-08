#ifndef BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

typedef struct binarytree BinaryTree;

BinaryTree* createNewBinaryTree(void);

int initializeBinaryTree(BinaryTree binaryTree, double value);

int insertValueInBinaryTree(BinaryTree binaryTree, double value);

int removeValueInBinaryTree(BinaryTree binaryTree, double value);

int findValueInBinaryTree(BinaryTree binaryTree, double value);

int removeLastValueInBinaryTree(BinaryTree binaryTree);

int clearBinaryTree(BinaryTree* binaryTree);

int deleteBinaryTree(BinaryTree* binaryTree);

#endif