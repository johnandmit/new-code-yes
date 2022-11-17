#include <stdio.h>
#include <stdlib.h>

typedef struct _ddlNode
{
    int info;
    struct _ddlNode *next;
    struct _ddlNode *prev;
} ddlNode;
typedef struct _ddlNode ddlNode;

ddlNode *at(ddlNode *header, int place)
{
    ddlNode *temp;
    temp = header;
    for (; place > 0 && temp->next != NULL; place--)
    {
        temp = temp->next;
    }
    return temp;
}

ddlNode *Insert(ddlNode *prev, int X)
{
    ddlNode *TempNode;
    TempNode = (ddlNode *)malloc(sizeof(ddlNode));
    TempNode->info = X;
    TempNode->next = prev->next;
    TempNode->prev = prev;
    prev->next = TempNode;
    return TempNode;
}

void remover(ddlNode *dlist, int key)
{
    ddlNode *temp = dlist;
    while (temp != NULL)
    {
        if (temp->info == key)
        {
            ddlNode *TempNode = temp->prev;
            TempNode->next = temp->next;
            temp->next->prev = TempNode;
        }
        temp = temp->next;
    }
}

ddlNode *printer(ddlNode *header)
{
    ddlNode *TempNode;
    TempNode = header->next;
    while (1)
    {
        printf("%i ", TempNode->info);
        TempNode = TempNode->next;
        if (TempNode == NULL)
            break;
    }
}

int main()
{
    ddlNode *header = (ddlNode *)malloc(sizeof(ddlNode));
    header->next = NULL;
    int choice = 0, x, place;
    while (1)
    {
        printf("\n1. insert\n2. remove\n3. end programme\nEnter: ");
        scanf("%i", &choice);
        if (choice == 3)
        {
            break;
        }
        else if (choice == 1)
        {
            printf("enter place you want to insert: ");
            scanf("%i", &place);
            printf("enter number you want to insert: ");
            scanf("%i", &x);
            Insert(at(header, place), x);
        }
        else if (choice == 2)
        {
            printf("enter key you want to remove: ");
            scanf("%i", &x);
            printer(header);
            printf("\n\n\n");
            remover(header, x);
            printer(header);
        }
    }
}
