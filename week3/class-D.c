#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void DeleteList(list node, int index, int length)
{
    while (--index)
    {
        if (node->next == NULL)
        {
            break;
        }
        node = node->next;
    }
    for (; length > 0; length--)
    {
        list temp = node->next;
        if (temp == NULL)
        {
            node->next = NULL;
            free(temp);
        }
        else
        {
            node->next = temp->next;
            free(temp);
        }
    }
}

void ConnectList(list nodea, list nodeb, int index)
{
    list FirstNodeA = nodea->next;
    list temp;
    for (;;)
    {
        if (nodea->next == NULL)
        {
            break;
        }
        nodea = nodea->next;
    }

    while (--index)
    {
        if (nodeb->next == NULL)
        {
            break;
        }
        nodeb = nodeb->next;
    }

    temp = nodeb->next;
    nodeb->next = FirstNodeA;
    nodea->next = temp;
}

void InputList(list nodea, list nodeb)
{
    int element;
    for (;;)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        CreateList(nodea, element);
    }
    for (;;)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        CreateList(nodeb, element);
    }
}

void Input(int *i, int *len, int *j)
{
    int p = 0;
    int number[3];
    char str[64];
    fgets(str, 64,stdin);

    for (int n = 0; n < 64; n++)
    {
        if (str[n] >= '0' && str[n] <= '9')
        {
            number[p] = str[n] - '0';
            p++;
        }
        if (p == 3)
        {
            break;
        }
    }
    *i = number[0];
    *len = number[1];
    *j = number[2];
}

void PrintList(list nodeb)
{
    nodeb = nodeb->next;
    for (;;)
    {
        if (nodeb == NULL)
        {
            break;
        }
        else if (nodeb->next == NULL)
        {
            printf("%d", nodeb->element);
        }
        else
        {
            printf("%d ", nodeb->element);
        }
        nodeb = nodeb->next;
    }
}


int main()
{
    int i, len, j;
    struct ListNode nodea;
    struct ListNode nodeb;

    InitList(&nodea);
    InitList(&nodeb);

    Input(&i, &len, &j);
    InputList(&nodea, &nodeb);
    DeleteList(&nodea, i, len);
    ConnectList(&nodea, &nodeb, j);
    PrintList(&nodeb);

    return 0;
}
