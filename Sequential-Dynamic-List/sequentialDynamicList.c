#include <stdio.h>
#include <stdlib.h>

#include "sequentialDynamicList.h"
#include "utils.h"

void createDynamicList(DynamicList* dynamicList)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return;

    dynamicList->list = malloc(INITIAL_CAPACITY * sizeof(float));
    dynamicList->capacity =  INITIAL_CAPACITY;
    dynamicList->quantityOfElements = 0;
}

int appendElement(DynamicList* dynamicList, float appendedItem)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stateOfList(dynamicList) == LIST_IS_FULL)
    {
        printf("The array reached its limit. Doubling the size.");
        doubleListSize(dynamicList);
    }

    dynamicList->list[dynamicList->quantityOfElements] = appendedItem;
    dynamicList->quantityOfElements++;

    printf("Number %f sucessfully appended. ", appendedItem);
    return FUNCTION_SUCCESS;
}

int addElementOnPosition(DynamicList* dynamicList, int position, float value)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stateOfList(dynamicList) == LIST_IS_FULL)
    {
        printf("The array reached its limit. Doubling the size.");
        doubleListSize(dynamicList);
    }

    float* indexPointer = &dynamicList->list[position];
    float currentValue;
    float nextValue;

    currentValue = (*indexPointer);
    (*indexPointer) = value;

    indexPointer++;

    for(int i = position; i < dynamicList->quantityOfElements; i++)
    {
    nextValue = (*indexPointer);
    (*indexPointer) = currentValue;
    currentValue = nextValue;
    indexPointer++;
    }

    dynamicList->quantityOfElements++;

    return FUNCTION_SUCCESS;
}

int removeLastElement(DynamicList* dynamicList)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    dynamicList->list[dynamicList->quantityOfElements - 1] = -1;
    dynamicList->quantityOfElements--;

    return FUNCTION_SUCCESS;
}

int removeElementOnPosition(DynamicList* dynamicList, int position)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    if(stateOfList(dynamicList) == LIST_IS_BLANK)
    {
    printf("List has no value to be removed. ");
    return FUNCTION_FAILURE;
    }

    float* indexPointer = &dynamicList->list[position];
    float nextValue;

    for(int i = dynamicList->quantityOfElements - position - 1; i > 0; i--)
    {
        nextValue = (*(indexPointer + 1));
        (*indexPointer) = nextValue;
        indexPointer++;
    }

    dynamicList->quantityOfElements--;

    return FUNCTION_SUCCESS;
}

int doubleListSize(DynamicList* dynamicList)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    float* temporaryDoubledList;
    temporaryDoubledList = malloc(sizeof(float) * dynamicList->capacity * 2);

    for(int i = 0; i < dynamicList->capacity; i++)
    {
        temporaryDoubledList[i] = dynamicList->list[i];
    }

    dynamicList->capacity = (dynamicList->capacity * 2);

    free(dynamicList->list);

    dynamicList->list = temporaryDoubledList;

    return FUNCTION_SUCCESS;
}

int printList(DynamicList* dynamicList)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return FUNCTION_FAILURE;

    printf("Total capacity of the list: %d numbers.\n", dynamicList->capacity);
    printf("How many numbers are currently on the List: %d numbers.\n", dynamicList->quantityOfElements);
    printf("How many numbers are left until list gets full: %d numbers.\n\n", (dynamicList->capacity - dynamicList->quantityOfElements));

    for(int index = 0; index < dynamicList->quantityOfElements; index++)
    {
        printf("[%d]: %f\t", index, dynamicList->list[index]);
    }

    return FUNCTION_SUCCESS;
}

void freeList(DynamicList* dynamicList)
{
    if(isListValid(dynamicList) == LIST_IS_NOT_VALID) return;

    dynamicList->quantityOfElements = 0;
    dynamicList->capacity = 0;

    free(dynamicList->list);
    free(dynamicList);
}