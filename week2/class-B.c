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

void DeleteList(list LastNode)
{
    list temp = LastNode->next;
    LastNode->next = temp->next;
    free(temp);
}

void SearchRepeatNode(list node)
{
    node = node->next;
    list CurrentNode = node;
    for (node = node->next;;)
    {
        if (node == NULL)
        {
            break;
        }

        if (node->element == CurrentNode->element)
        {
            DeleteList(CurrentNode);
            node = CurrentNode->next;
        }
        else
        {
            CurrentNode = node;
            node = node->next;
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
        }
        node = node->next;
    }
}

int main()
{
    struct ListNode node;
    int length;
    int element;

    InitList(&node);
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        CreateList(&node, element);
    }

    SearchRepeatNode(&node);
    PrintList(&node);
}