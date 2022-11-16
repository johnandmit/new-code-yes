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

ddlNode *Insert(ddlNode *prev, int X, ddlNode *header)
{
    ddlNode *Temp;
    Temp = (ddlNode *)malloc(sizeof(ddlNode));
    Temp->info = X;
    if (prev->next != NULL)
    {
        Temp->next = prev->next;
    }
    else
    {
        Temp->next = header;
    }
    Temp->prev = prev;
    prev->next = Temp;
    return Temp;
}

void remover(ddlNode *dlist, int key)
{
    ddlNode *temp = dlist;
    while (1)
    {
        if (temp->info == key)
        {
            printf("%i ", temp->info);
            ddlNode *TempNode = temp->prev;
            TempNode->next = temp->next;
            temp->next->prev = TempNode;
        }
        temp = temp->next;
        if (temp == dlist)
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
        printf("1. insert\n2. remove\n3. end programme\nEnter: ");
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
            Insert(at(header, place), x, header);
        }
        else if (choice == 2)
        {
            printf("enter key you want to remove: ");
            scanf("%i", &x);
            remover(header, x);
        }
    }
}
