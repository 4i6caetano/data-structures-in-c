#include<stdio.h>

#include "linkedList.h"

int validate(LinkedList* linkedList)
{
    if(!linkedList)
    {
        return NOT_VALID;
    }

    return VALID;
}