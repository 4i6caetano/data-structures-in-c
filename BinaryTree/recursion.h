#ifndef RECURSION_H
#define RECURSION_H

#include "binarySearchTree.h"

int checkValidation(BinarySearchTree* binarySearchTree);

int insertRecursion(Node* currentNode, double value);

int findRecursion(Node* currentNode, double value, int* depth);

void clearRecursive(Node* node);

int removeValueRecursive(Node* node, Node* parentNode, double value);

Node* maximumSearchRecursive(Node* node);

Node* minimumSearchRecursive(Node* node);

void recursivePreOrder(Node* node);

void recursiveInOrder(Node* node);

void recursivePostOrder(Node* node);

#endif