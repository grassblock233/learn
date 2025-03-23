#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

struct ListNode
{
    ElementType element;
    struct ListNode *next;
};

typedef struct ListNode *list;

/*List*/

void InitList(list FirstNode)
{
    FirstNode->next = NULL;
}

void CreateList(list CurrentNode, ElementType element)
{
    while (CurrentNode->next != NULL)
    {
        CurrentNode = CurrentNode->next;
    }

    list NewNode = malloc(sizeof(struct ListNode));

    NewNode->next = NULL;
    NewNode->element = element;
    CurrentNode->next = NewNode;
}

int FindListLength(list FirstNode)
{
    int length = 0;
    list CurrentNode = FirstNode->next;

    while (CurrentNode->next != NULL)
    {
        length++;
        CurrentNode = CurrentNode->next;
    }
    return length;
}

list SplitList(list FirstNode, int i, int j)
{
    list NewNode = malloc(sizeof(struct ListNode));
    InitList(NewNode);
    int ListLength = FindListLength(FirstNode);
    list CurrentNode = FirstNode;
    int temp = i;

    while (temp--)
    {
        CurrentNode = CurrentNode->next;
    }

    if (j > ListLength)
    {
        j = ListLength;
    }
    for (j = j - i + 1; j > 0; j--)
    {
        CreateList(NewNode, CurrentNode->element);
        CurrentNode = CurrentNode->next;
    }
    return NewNode;
}

/*Stack*/

void PushStack(list Stack, ElementType element)
{
    list NewNode = malloc(sizeof(struct ListNode));
    NewNode->next = Stack->next;
    NewNode->element = element;
    Stack->next = NewNode;
}

ElementType PopStack(list Stack)
{
    list temp = Stack->next;
    ElementType element = temp->element;
    Stack->next = temp->next;
    free(temp);
    return element;
}

/*Input*/

void TransStrToList(char *str, list node)
{
    unsigned int len = strlen(str);

    for (int n = 0; n < len - 1; n++)
    {
        CreateList(node, str[n]);
        node = node->next;
    }
}

void InputList(list FirstNode, int *i, int *j)
{
    char str1[32];
    char str2[1024];

    scanf("i=%d,j=%d\n", i, j);
    fgets(str2, 1024,stdin);

    TransStrToList(str2, FirstNode);
}

/*Compare*/

list FindCenterNode(list FirstNode)
{
    list slow = FirstNode;
    list fast = FirstNode;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

_Bool CompareListNode(list FirstNode, list CenterNode, list Stack)
{
    _Bool flag = 1;
    FirstNode = FirstNode->next;
    list CenterNode_TEMP = CenterNode;

    while (CenterNode_TEMP != NULL)
    {
        PushStack(Stack, CenterNode_TEMP->element);
        CenterNode_TEMP = CenterNode_TEMP->next;
    }

    do
    {
        if (FirstNode->element != PopStack(Stack))
        {
            flag = 0;
            break;
        }
        FirstNode = FirstNode->next;
    } while (FirstNode != CenterNode);
    return flag;
}

int main()
{
    struct ListNode FirstNode;
    struct ListNode Stack;
    int i, j;

    InitList(&FirstNode);
    InitList(&Stack);
    InputList(&FirstNode, &i, &j);

    list NewNode = SplitList(&FirstNode, i, j);
    list CenterNode = FindCenterNode(NewNode);

    if (CompareListNode(NewNode, CenterNode, &Stack) == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
