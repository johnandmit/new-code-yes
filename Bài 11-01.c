#include <stdio.h>
#include <stdlib.h>

struct _PointerType
{
    int inf;
    struct _PointerType *next;
};
typedef struct _PointerType PointerType;

PointerType *at(PointerType *header, int place)
{
    PointerType *temp;
    temp = header;
    for (; place > 0 && temp->next != NULL; place--)
    {
        temp = temp->next;
    }
    return temp;
}

PointerType *deleteHead(PointerType *header)
{
    PointerType *TempNode;
    TempNode = header->next;
    free(header);
    return TempNode;
}

int deleteMiddle(PointerType *prev)
{
    int x;
    PointerType *TempNode;
    x = prev->next->inf;
    TempNode = prev->next;
    prev->next = prev->next->next;
    free(TempNode);
    return x;
}

PointerType *Insert(PointerType *prev, int X)
{
    PointerType *TempNode;
    TempNode = (PointerType *)malloc(sizeof(PointerType));
    TempNode->inf = X;
    TempNode->next = prev->next;
    prev->next = TempNode;
    return TempNode;
}

PointerType *printer(PointerType *header)
{
    PointerType *TempNode;
    TempNode = header->next;
    while (TempNode != NULL)
    {
        printf("%i ", TempNode->inf);
        TempNode = TempNode->next;
    }
    printf("\n");
}

int isEmpty(PointerType *header)
{
    return !header;
}

PointerType *MakeNull(PointerType *header)
{
    while (!isEmpty(header))
    {
        header = deleteHead(header);
    }
    return header;
}

int main()
{
    PointerType *header = (PointerType *)malloc(sizeof(PointerType));
    header->next = NULL;
    int choice = 0, x, place;
    while (1)
    {
        printf("1. insert");
        printf("\n2. dellete");
        printf("\n3. Print list");
        printf("\n4. check if list is empty");
        printf("\n5. clear list");
        printf("\n6. end programme");
        printf("\nEnter: ");
        scanf("%i", &choice);
        if (choice == 6)
        {
            break;
        }
        else if (choice == 1)
        {
            printf("Enter place you want to insert: ");
            scanf("%i", &place);
            printf("Enter number you want to insert: ");
            scanf("%i", &x);
            Insert(at(header, place), x);
        }
        else if (choice == 2)
        {
            printf("Enter place you want to delete: ");
            scanf("%i", &place);
            if (place == 0)
                header = deleteHead(header);
            else
            {
                deleteMiddle(at(header,place));
            }
        }
        else if (choice == 3)
        {
            printer(header);
        }
        else if (choice == 4)
        {
            if(isEmpty(header))
            {
                printf("List is empty");
            }
        }
        else
        {
            MakeNull(header);
            header = (PointerType *)malloc(sizeof(PointerType));
            header->next = NULL;
        }
    }
}
