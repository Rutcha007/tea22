#include "linkedlist.h"
#include "stdlib.h"


ListNode* NewListNode()
{
    ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
    return temp;
};

void FreeListNode(ListNode* elem)
{
    free(elem);
};