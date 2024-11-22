#ifndef LinkedList_H //include guard
#define LinkedList_H

typedef struct ListNode
{
    unsigned int data;
    struct ListNode* pNext;
}ListNode_t;

typedef struct List
{
    struct ListNode* pHead;
    struct ListNode* pTail;
    unsigned int size;
}List_t;

ListNode* NewListNode(void);
void FreeListNode(ListNode* elem);

#endif