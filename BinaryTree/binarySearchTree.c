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

static int removeValueRecursive(Node* node, Node* parentNode, double value)
{
    if(node == NULL)
    {
        return FAILURE; // INCORRECT NODE OR VALUE NOT FOUND
    }

    if(node->value != value)
    {
        if(node->value > value)
        {
            return removeValueRecursive(node->left_node, node, value);
        }
        
        else
        {
            return removeValueRecursive(node->right_node, node, value);
        }
    }

    else // 1. VALUE IS FOUND
    {  
        Node* replacedNode;

        if(node->left_node != NULL && node->right_node != NULL) // 1.1 FULL NODE 
        {
            // place the BIGGEST NODE VALUE on the left side as the replacement
            replacedNode = node->left_node;
            while(replacedNode->right_node != NULL)
            {
                replacedNode = replacedNode->right_node;
            }

            node->value = replacedNode->value;

            return removeValueRecursive(node->left_node, node, replacedNode->value);
        }

        else if(node->left_node != NULL && node->right_node == NULL) // 1.2 ONLY LEFT CHILDREN
        {
            replacedNode = node->left_node;

            while(replacedNode -> right_node != NULL) // BIGEST VALUE OF THE LEFT SIDE
            {
                replacedNode = replacedNode->right_node;
            }

            node->value = replacedNode->value;

            return removeValueRecursive(node->left_node, node, replacedNode->value);
        }

        else if(node->left_node == NULL && node->right_node != NULL) // 1.3 ONLY RIGHT CHILDREN
        {
            // SMALEST VALUE OF THE RIGHT SIDE
            replacedNode = node->right_node;

            while(replacedNode->left_node != NULL)
            {
                replacedNode = replacedNode->left_node;
            }

            node->value = replacedNode->value;

            return removeValueRecursive(node->right_node, node, replacedNode->value);
        }

        else // 1.4 THE NODE HAS NO CHILDREN
        {
            if(parentNode == NULL) // IF THE NODE IS THE ROOT
            {
                printf("The root was removed. The tree is now blank.");
                free(node);
                return SUCCESS;
            }

            else if(node == parentNode->left_node) // the node is on the LEFT of the parent
            {
                parentNode->left_node = NULL;
                free(node);

                return SUCCESS;
            }

            else // the node is on the RIGHT of the parent
            {
                parentNode->right_node = NULL;
                free(node);
                
                return SUCCESS;
            }
        }
    }
    //last element is the one on the leftmost part

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

// We return the PARENT node so we can safely remove a node if needed
static Node* maximumSearchRecursive(Node* node) //outmost RIGHT node
{
    // root CANNOT be NULL because we validated it

    if(node->right_node->right_node == NULL) // This is the rightmost value
    {
        return node;
    }

    else // continue searching for the biggest value
    {
        return maximumSearchRecursive(node->right_node);
    }
}

static Node* minimumSearchRecursive(Node* node) //outmost LEFT node
{
    if(node->left_node->left_node == NULL) // This is the leftmost value
    {
        return node;
    }

    else // continue searching for the smallest value
    {
        return minimumSearchRecursive(node->left_node);
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

static void recursivePreOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    else
    {
        // ROOT
        printf("%f, ", node->value);

        // LEFT
        recursivePreOrder(node->left_node);

        //RIGHT
        recursivePreOrder(node->right_node);
    }
}

int preOrder(BinarySearchTree* binarySearchTree)
{

}

static void recursiveInOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    else
    {
        // LEFT
        recursiveInOrder(node->left_node);

        // ROOT
        printf("%f, ", node->value);

        //RIGHT
        recursivePreOrder(node->right_node);
    }
}

static void recursivePostOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    else
    {
        // LEFT
        recursiveInOrder(node->left_node);

        // RIGHT
        recursivePreOrder(node->right_node);

        //ROOT
        printf("%f, ", node->value);
    }
}

int inOrder(BinarySearchTree* binarySearchTree)
{

}

int postOrder(BinarySearchTree* binarySearchTree)
{

}