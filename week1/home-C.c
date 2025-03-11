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
            return;
        }
        CreateList(node, element);
        node = node->next;
    }
}

void SearchList(list node1, list node2, list node)
{
    node1 = node1->next;
    node2 = node2->next;

    for (;;)
    {
        if (node1 == NULL || node2 == NULL)
        {
            break;
        }

        if (node1->element == node2->element)
        {
            CreateList(node, node1->element);
            node1 = node1->next;
            node2 = node2->next;
        }
        else if (node1->element > node2->element)
        {
            node2 = node2->next;
        }
        else
        {
            node1 = node1->next;
        }
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
            printf("%d ", node->element);
            node = node->next;
        }
    }
}

int main()
{
    struct ListNode node;
    struct ListNode node1;
    struct ListNode node2;
    int element;

    InitList(&node);
    InitList(&node1);
    InitList(&node2);

    InputList(&node1);
    InputList(&node2);

    SearchList(&node1, &node2, &node);
    PrintList(&node);
}