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
    list head = malloc(sizeof(struct ListNode));
    if (head == NULL)
    {
        return;
    }
    head->next = NULL;
    head->element = element;
    node->next = head;
}

void DeleteList(list node)
{
    list temp = node->next;
    node->next = temp->next;
    free(temp);
}

void SearchList(list node, int item)
{
    list LastNode = node;
    node = node->next;
    _Bool Flag = 0;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        else if (node->element == item)
        {
            DeleteList(LastNode);
            Flag = 1;
        }

        if (Flag == 1)
        {
            node = LastNode->next;
            Flag = 0;
        }
        else
        {
            LastNode = node;
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
            node = node->next;
        }
    }
}

int main()
{
    struct ListNode node;
    list FirstNode = &node;
    list CurrentNode = &node;
    int length;
    int element;
    int item; /*delete*/

    InitList(&node);
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        CreateList(CurrentNode, element);
        CurrentNode = CurrentNode->next;
    }
    scanf("%d", &item);
    SearchList(FirstNode, item);
    PrintList(FirstNode);
}