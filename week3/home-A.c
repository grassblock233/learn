#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct ListNode
{
    ElementType element;
    struct ListNode *next;
};

typedef struct ListNode * list;

void InitList(list FirstNode)
{
    FirstNode = NULL;
}



int main()