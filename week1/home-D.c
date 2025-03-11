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

void CreateList(list node, int element)
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
        return;
    }
    head->element = element;
    head->next = NULL;
    node->next = head;
}

void InputList(list node)
{
    int element;

    for (;;)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        else
        {
            CreateList(node, element);
            node = node->next;
        }
    }
}

_Bool FindElement(list node, int element)
{
    _Bool Flag = 0;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        else if (node->element == element)
        {
            Flag = 1;
            break;
        }
        node = node->next;
    }
    return Flag;
}

int FindList(list node, list node1, list node2)
{
    int count = 0;
    node1 = node1->next;
    node2 = node2->next;
    for (;;)
    {
        if (node1 == NULL)
        {
            break;
        }
        else
        {
            if (FindElement(node2, node1->element) == 0)
            {
                count++;
                CreateList(node, node1->element);
            }
            node1 = node1->next;
        }
    }
    return count;
}

void PrintList(list node)
{
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        else
        {
            printf("%d ", node->element);
        }
        node = node->next;
    }
}

int main()
{
    int count = 0;
    struct ListNode node;
    struct ListNode node1;
    struct ListNode node2;

    InitList(&node);
    InitList(&node1);
    InitList(&node2);

    InputList(&node1);
    InputList(&node2);
    count = FindList(&node, &node1, &node2);

    PrintList(node.next);
    printf("\n");
    printf("%d", count);
}
