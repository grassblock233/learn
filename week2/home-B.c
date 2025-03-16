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
    head->next = NULL;
    head->element = element;
    node->next = head;
}

int FindMinElement(list node)
{
    int min;
    node = node->next;
    min = node->element;
    for (;;)
    {
        node = node->next;

        if (node == NULL)
        {
            break;
        }
        else if (node->element < min)
        {
            min = node->element;
        }
    }
    return min;
}

void InputList(list node)
{
    int element;
    int length;

    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        CreateList(node, element);
        node = node->next;
    }
}

int main()
{
    struct ListNode node;
    int min;

    InitList(&node);
    InputList(&node);
    min = FindMinElement(&node);
    printf("%d", min);
}