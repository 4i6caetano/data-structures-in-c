#include <stdio.h>
#include<stdlib.h>

#include "binarySearchTree.h"
#include "recursion.h"

int insertRecursion(Node* currentNode, double value)
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

int findRecursion(Node* currentNode, double value, int* depth)
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

void clearRecursive(Node* node)
{

    if(node == NULL) return;

    clearRecursive(node->left_node);
    clearRecursive(node->right_node);

    free(node);

    return;
    
}

int removeValueRecursive(Node* node, Node* parentNode, double value)
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

// We return the PARENT node so we can safely remove a node if needed
Node* maximumSearchRecursive(Node* node) //outmost RIGHT node
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

Node* minimumSearchRecursive(Node* node) //outmost LEFT node
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

void recursivePreOrder(Node* node)
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

void recursiveInOrder(Node* node)
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
        recursiveInOrder(node->right_node);
    }
}

void recursivePostOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    else
    {
        // LEFT
        recursivePostOrder(node->left_node);

        // RIGHT
        recursivePostOrder(node->right_node);

        //ROOT
        printf("%f, ", node->value);
    }
}

int getTreeHeightRecursive(Node* node)
{
    if(node == NULL)
    {
        return NOT_INITIALIZED_HEIGHT;
    }

    int leftHeight = getTreeHeightRecursive(node->left_node);
    int rightHeight = getTreeHeightRecursive(node->right_node);

    if(leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }

    else
    {
        return rightHeight + 1;
    }
}