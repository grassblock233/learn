#include <stdio.h>
#include <stdlib.h>

struct List
{
    int element;
    struct List *next;
};

typedef struct List *list;

void InitList(list node, int data)
{
    node->next = NULL;
    node->element = data;
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

    list head = malloc(sizeof(struct List));
    if (head == NULL)
    {
        return;
    }
    head->next = NULL;
    head->element = element;
    node->next = head;
}

/*
void CreateCircleList(list node)
{
    list FirstNode = node;
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
    node->next = FirstNode;
}
*/

void SortList(list node, int count)
{
    int swap;
    list FirstNode = node;
    for (int i = 0; i < count - 1; i++)
    {
        node = FirstNode;
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (node->element > node->next->element)
            {
                swap = node->element;
                node->element = node->next->element;
                node->next->element = swap;
            }
            node = node->next;
        }
    }
}

void PrintAns(list node, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", node->element);
        node = node->next;
    }
}

int main()
{
    struct List node;
    int element;
    int count = 0;
    scanf("%d", &element);
    InitList(&node, element);
    count++;
    for (;;)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        else
        {
            CreateList(&node, element);
            count++;
        }
    }
    // CreateCircleList(&node);
    SortList(&node, count);
    PrintAns(&node, count);
}