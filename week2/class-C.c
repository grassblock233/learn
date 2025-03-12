#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int element;
    struct ListNode *next;
};

typedef struct ListNode *list;

void InitList(list node)
{
    node->next = NULL;
}

_Bool CreateList(list node, int element)
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

void DeleteList(list LastNode)
{
    list temp = LastNode->next;
    LastNode->next = temp->next;
    free(temp);
}

void PrintList(list node)
{
    node = node->next;
    for (;;)
    {
        if (node = NULL)
        {
            break;
        }
        else
        {
            printf("%d ", node->element);
            node = node->next;
        }
    }
}

void InputElement(list node)
{
    int element;
    int length;
    list FirstNode = node;

    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        CreateList(node, element);
        node = node->next;
    }

    FirstNode->element = length;
}

void SearchRepeatElement(list nodeA, list nodeB, list nodeC)
{
    nodeA = nodeA->next;
    nodeB = nodeB->next;
    nodeC = nodeC->next;

}

int main()
{
    struct ListNode nodeA;
    struct ListNode nodeB;
    struct ListNode nodeC;

    InputElement(&nodeA);
    InputElement(&nodeB);
    InputElement(&nodeC);
}