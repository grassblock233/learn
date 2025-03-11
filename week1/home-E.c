#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int index;
    int element;
    struct ListNode *next;
};

typedef struct ListNode *list;

void InitList(list node)
{
    node->next = NULL;
}

int TransInputNumber(char *str)
{
    int n;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            n = str[i] - '0';
            break;
        }
    }
    return n;
}

void CreateList(list node, int element, int index)
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
    head->index = index;
    head->next = NULL;
    node->next = head;
}

_Bool JudgeList(list node)
{
    _Bool flag = 1;
    node = node->next;
    for (;;)
    {
        if (node->next == NULL)
        {
            break;
        }

        if (((node->next->index) * (node->next->index) - (node->element)) != node->next->element)
        {
            flag = 0;
            break;
        }
        node = node->next;
    }
    return flag;
}

int main()
{
    struct ListNode node;
    char str[128];
    int length;
    int element;
    _Bool flag;

    InitList(&node);
    fgets(str, 128, stdin);
    length = TransInputNumber(str);
    for (int i = 1; i <= length; i++)
    {
        scanf("%d", &element);
        CreateList(&node, element, i);
    }

    flag = JudgeList(&node);
    if (flag == 0)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
}