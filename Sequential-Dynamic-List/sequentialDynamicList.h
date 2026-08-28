#ifndef SEQUENTIAL_DYNAMIC_LIST
#define SEQUENTIAL_DYNAMIC_LIST

#define LIST_IS_FULL 1
#define LIST_IS_NOT_FULL 0
#define LIST_IS_BLANK -1

#define LIST_IS_VALID 1
#define LIST_IS_NOT_VALID -1

#define FUNCTION_SUCCESS 1
#define FUNCTION_FAILURE -1
#define FUNCTION_UNEXPECTED_RESPONSE 0

#define INITIAL_CAPACITY 5

typedef struct dynamicList DynamicList;

typedef struct dynamicList
{
    float *list;
    int capacity;
    int quantityOfElements;
} DynamicList;

void createDynamicList(DynamicList* dynamicList);

int appendElement(DynamicList* dynamicList, float appendedItem);

int addElementOnPosition(DynamicList* dynamicList, int position, float value);

int removeLastElement(DynamicList* dynamicList);

int removeElementOnPosition(DynamicList* dynamicList, int position);

int doubleListSize(DynamicList* dynamicList);

int printList(DynamicList* dynamicList);

void freeList(DynamicList* dynamicList);

#endif