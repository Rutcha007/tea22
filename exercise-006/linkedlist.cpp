#include "linkedlist.h"
#include "stdlib.h"

List* NewList()
{
    List* temp = (List*) malloc(sizeof(List));
    temp->pHead = nullptr;
    temp->pTail = nullptr;
    temp->size = 0;
}

ListNode* NewListNode()
{
    ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
    temp->data = NULL;
    temp->pNext = nullptr;
    return temp;
};

void FreeListNode(ListNode* elem)
{
    free(elem);
};

ListNode* GetPrevious(List* list, ListNode* elem)
{
    ListNode* temp = list->pHead;
    for (size_t i = 0; i < list->size; i++)
    {
        if (temp->pNext == elem)
        {
            return temp;
        }
        else
        {
            temp = temp->pNext;
        }
    };
};

ListNode* GetElement(List* list, unsigned int index)
{
    ListNode* temp = list->pHead;
    for (size_t i = 0; i < list->size; i++)
    {
        if (i == index)
        {
            return temp;
        }
        else
        {
            temp = temp->pNext;
        }
    };
};

void InsertInfoLinkedList(List* list, unsigned int data)
{
    ListNode* temp = NewListNode();
    temp->data = data;

    if (list->pHead == nullptr && list->pTail == nullptr)    //leere Liste
    {
        list->pHead = temp;
        list->pTail = temp;
        temp->pNext = nullptr;
    }
    else if (list->pTail != nullptr)   // keine leere Liste
    {
        ListNode* elem = list->pTail;
        elem->pNext = temp;
        list->pTail = temp;
        temp->pNext = nullptr;
    }
    
    list->size = list->size + 1;
}

int RemovefromLinkedList(List* list, ListNode* elem)
{
    if (list->pHead == nullptr && list->pTail == nullptr)
    {
        
    }
    else if (list->pHead == elem && list->pTail == elem)
    {
        FreeListNode(elem);
        list->pHead = nullptr;
        list->pTail = nullptr;
        list->size = 0;
    }
    else if (list->pTail != elem)
    {
        ListNode* temp = GetPrevious(list,elem); // finde element das vor dem element ist
        temp->pNext = elem->pNext; // vorheriges element bekommt auf sein next das next vom zu löschenden element
        FreeListNode(elem);
        list->size -= 1;
    }
    return 0;
}