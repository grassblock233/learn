#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int index;
    char element;
    struct ListNode *next;
};

typedef struct ListNode *list;

void InitList(list node)
{
    node->next = NULL;
}

_Bool CreateList(list node, char element, int index)
{
    for (;;)
    {
        if (node->next == NULL)
        {
            break;
        }
        else
        {
            node = node->next;
        }
    }

    list head = malloc(sizeof(struct ListNode));
    if (head == NULL)
    {
        return 0;
    }
    head->element = element;
    head->index = index;
    head->next = NULL;
    node->next = head;
    return 1;
}

void DeleteList(list LastNode)
{
    list temp = LastNode->next;
    LastNode->next = temp->next;
    free(temp);
}

_Bool CompareList(list Node, list SubNode)
{
    _Bool flag = 0;

    for (;;)
    {
        if (Node == )
    }
}