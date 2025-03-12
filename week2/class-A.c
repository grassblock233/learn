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

_Bool SearchList(list node1, list node2)
{
    node1 = node1->next;
    node2 = node2->next;
    _Bool flag = 1;
    list FirstNode = node1;
    for (;;)
    {
        if (node2 == NULL)
        {
            break;
        }
        node1 = FirstNode;
        for (;;)
        {
            flag = 0;
            if (node1 == NULL)
            {
                break;
            }
            if (node1->element == node2->element)
            {
                flag = 1;
                node1->element = -1;
                break;
            }
            node1 = node1->next;
        }

        if (flag == 0)
        {
            break;
        }
        node2 = node2->next;
    }

    return flag;
}

void InputElement(list node)
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
        }
    }
}
    

int main()
{
    struct ListNode node1;
    struct ListNode node2;
    _Bool flag;

    InitList(&node1);
    InitList(&node2);

    InputElement(&node1);
    InputElement(&node2);

    flag = SearchList(&node1, &node2);
    if (flag == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}