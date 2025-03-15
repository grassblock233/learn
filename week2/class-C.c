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

void InputList(list node)
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
}

list CompareList(list nodeA, list nodeB)
{
    nodeA = nodeA->next;
    nodeB = nodeB->next;
    list CommenList = malloc(sizeof(struct ListNode));
    list FirstNode = CommenList;
    InitList(CommenList);
    while (nodeA && nodeB)
    {
        if (nodeA->element > nodeB->element)
        {
            nodeB = nodeB->next;
        }
        else if (nodeA->element < nodeB->element)
        {
            nodeA = nodeA->next;
        }
        else
        {
            int CommenValue = nodeA->element;
            list head = malloc(sizeof(struct ListNode));
            head->next = NULL;
            head->element = CommenValue;
            CommenList->next = head;
            CommenList = CommenList->next;
            while (nodeA && nodeA->element == CommenValue)
            {
                nodeA = nodeA->next;
            }
            while (nodeB && nodeB->element == CommenValue)
            {
                nodeB = nodeB->next;
            }
        }
    }
    return FirstNode;
}

void FreeList(list node)
{
    list temp;

    node = node->next;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        temp = node;
        node = node->next;
        free(temp);
    }
}

void CopyList(list Node_Dest, list Node_Sour)
{
    FreeList(Node_Dest);
    InitList(Node_Dest);
    list temp = Node_Sour->next;
    Node_Dest->next = temp;
    free(Node_Sour);
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
    struct ListNode nodeA;
    struct ListNode nodeB;
    struct ListNode nodeC;
    list CommenList1;
    list CommenList2;

    InitList(&nodeA);
    InitList(&nodeB);
    InitList(&nodeC);

    InputList(&nodeA);
    InputList(&nodeB);
    InputList(&nodeC);

    CommenList1 = CompareList(&nodeA, &nodeB);
    CommenList2 = CompareList(CommenList1, &nodeC);

    CopyList(&nodeA, CommenList2);
    PrintList(&nodeA);

    return 0;
}