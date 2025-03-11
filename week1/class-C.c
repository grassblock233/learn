#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List
{
    char word[256];
    struct List *next;
};

typedef struct List *list;

void InitList(list Node)
{
    Node->next = NULL;
}

void InsertList_END(list Node, char *word)
{
    for (;;)
    {
        if (Node->next == NULL)
        {
            break;
        }
        else
        {
            Node = Node->next;
        }
    }

    list Head = malloc(sizeof(struct List));
    if (Head == NULL)
    {
        return;
    }
    Head->next = NULL;
    strcpy(Head->word, word);
    Node->next = Head;
}

_Bool IsRepeat(list Node, char *word)
{
    _Bool flag = 0;
    for (;;)
    {
        if (Node == NULL)
        {
            break;
        }
        else if (strcmp(Node->word, word) == 0)
        {
            flag = 1;
            break;
        }
        Node = Node->next;
    }
    return flag;
}

void Str2Word(char *str, char (*word)[256])
{
    int count = 0;
    int p = 0;
    int len = strlen(str);
    for (int i = 0; i <= len; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            word[count][p] = str[i];
            p++;
        }
        else
        {
            if ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
            {
                count++;
                p = 0;
            }
        }
    }
}

void PrintAns(list Node)
{
    Node = Node->next;
    for (;;)
    {
        if (Node == NULL)
        {
            break;
        }
        int len = strlen(Node->word);
        for (int i = 0; i < len; i++)
        {
            printf("%c", Node->word[i]);
        }
        printf(" ");
        Node = Node->next;
    }
}

int main()
{
    int count;
    char word[256][256];
    char str[10240];
    struct List node;

    scanf("%d", &count);
    getchar();
    InitList(&node);
    fgets(str, 10240, stdin);
    Str2Word(str, word);
    for (int i = 0; i < count; i++)
    {
        if (IsRepeat(&node, word[i]) == 0)
        {
            InsertList_END(&node, word[i]);
        }
    }
    PrintAns(&node);

    return 0;
}