#include <stdio.h>
#include <stdlib.h>

#include "sequentialDynamicList.h"


int isListValid(DynamicList *dynamicList)
{
    if(!dynamicList)
    {
        printf("Initialization Error. ");
        return LIST_IS_NOT_VALID;
    }

    return LIST_IS_VALID;
}

int stateOfList(DynamicList* dynamicList)
{
    if(dynamicList->quantityOfElements == 0)
    {
        return LIST_IS_BLANK;
        printf("List is blank. ");
    }

    if(dynamicList->capacity == dynamicList->quantityOfElements)
    {
        return LIST_IS_FULL;
        printf("List is full.");
    }

    return LIST_IS_NOT_FULL;
}

