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

void SortList(list node, int length)
{
    node = node->next;
    int swap;
    list FirstNode = node;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (node->element > node->next->element)
            {
                swap = node->element;
                node->element = node->next->element;
                node->next->element = swap;
            }
            node = node->next;
        }
        node = FirstNode;
    }
}

void PrintAns(list node)
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

int InputList(list node)
{
    int length;
    int element;

    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        CreateList(node, element);
        node = node->next;
    }
    return length;
}

void ConnectList(list nodeLA, list nodeLB)
{
    for (;;)
    {
        if (nodeLA->next == NULL)
        {
            break;
        }
        else
        {
            nodeLA = nodeLA->next;
        }
    }

    nodeLB = nodeLB->next;
    nodeLA->next = nodeLB;
}

void DeleteNode(list LastNode)
{
    list temp = LastNode->next;
    LastNode->next = temp->next;
    free(temp);
}

void DeleteRepeat(list node)
{
    list CurrentNode = node;
    list SearchNode;
    int CurrentValue;

    CurrentNode = CurrentNode->next;
    while (CurrentNode)
    {
        CurrentValue = CurrentNode->element;
        SearchNode = CurrentNode->next;
        while (SearchNode)
        {
            if (SearchNode->element == CurrentValue)
            {
                DeleteNode(CurrentNode);
                SearchNode = CurrentNode->next;
            }
            else
            {
                break;
            }
        }
        CurrentNode = CurrentNode->next;
    }
}

int main()
{
    struct ListNode nodeLA;
    struct ListNode nodeLB;
    int lengthA, lengthB;

    InitList(&nodeLA);
    InitList(&nodeLB);

    lengthA = InputList(&nodeLA);
    lengthB = InputList(&nodeLB);

    ConnectList(&nodeLA, &nodeLB);
    SortList(&nodeLA, lengthA + lengthB);
    DeleteRepeat(&nodeLA);
    PrintAns(&nodeLA);
}
