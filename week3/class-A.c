#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int element;
    struct ListNode *next;
};

typedef struct ListNode * list;

void InitList(list node)
{
    node->next = NULL;
}

_Bool CreateList(list node,int element)
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
    head->next = NULL;
    node->next = head;
    return 1;
}

void InputList(list node)
{
    int length;
    int element;
    scanf("%d",&length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d",&element);
        CreateList(node,element);
        node = node->next;
    }
}

int SearchMinNode(list node)
{
    node = node->next;
    int min = node->element;
    int index = 0;
    for (int i = 0;;i++)
    {
        if (node->next == NULL)
        {
            break;
        }
        else if (node->element < min)
        {
            min = node->element;
            index = i;
        }
        node = node->next;
    }
    return index;
}

void MoveListNode(list node,int index)
{
    list FirstNode = node;
    while (index--)
    {
        node = node->next;
    }
    if (node->next != NULL)
    {
        list temp = node->next;
        node->next = temp->next;
        temp->next = FirstNode->next;
        FirstNode->next = temp;
    }
    else
    {
        list temp = node->next;
        temp->next = FirstNode->next;
        FirstNode->next = temp;
        node->next = NULL;
    }
}

void PrintList(list node)
{
    node = node->next;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        else
        {
            printf("%d ",node->element);
            node = node->next;
        }
    }
}

int main()
{
    struct ListNode node;
    int index;

    InitList(&node);
    InputList(&node);
    index = SearchMinNode(&node);
    MoveListNode(&node,index);
    PrintList(&node);
    return 0;
}