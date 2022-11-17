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

void reverse(PointerType *header)
{
    PointerType *TempNode;
    TempNode = header->next;
    int arr[100], i = 0;
    while (TempNode != NULL)
    {
        arr[i] = TempNode->inf;
        TempNode = TempNode->next;
        i++;
    }
    i--;
    for (; i >= 0; i--)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int main()
{
    PointerType *header = (PointerType *)malloc(sizeof(PointerType));
    header->next = NULL;
    int choice = 0, x, place;
    while (1)
    {
        printf("\n1. insert");
        printf("\n2. print reverse");
        printf("\n3. Print list");
        printf("\n4. End programme");
        printf("\nEnter: ");
        scanf("%i", &choice);
        if (choice == 4)
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
            reverse(header);
        }
        else if (choice == 3)
        {
            printer(header);
        }
    }
}
