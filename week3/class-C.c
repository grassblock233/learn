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
    head->element = element;
    head->next = NULL;
    node->next = head;
}

void TransList(list node, int length)
{
    list FirstNode = node;
    list LastNode;
    list temp;

    /*Init Task*/
    node = node->next;
    temp = node->next;
    node->next = NULL;

    for (int i = 1; i < length; i++)
    {
        LastNode = node;
        node = temp;
        temp = node->next;
        node->next = LastNode;
    }
    FirstNode->next = node;
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
        }
        node = node->next;
    }
}

int InputList(list node)
{
    int element;
    int length = 0;

    for (;;)
    {
        if (scanf("%d", &element) != EOF)
        {
            CreateList(node, element);
            node = node->next;
            length++;
        }
        else
        {
            break;
        }
    }
    return length;
}

int main()
{
    struct ListNode node;
    int length;

    InitList(&node);
    length = InputList(&node);
    TransList(&node, length);
    PrintList(&node);
}
