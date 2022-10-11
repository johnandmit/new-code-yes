#include <stdio.h>
#include <stdlib.h>

struct _PointerType{
    int inf;
    struct _PointerType *next;
};
typedef struct _PointerType PointerType;

PointerType *place(PointerType *header,int place)
{
    PointerType *temp;
    temp = header;
    for(;place>0; place--)
    {   
        temp = temp->next;
    }
    return temp;
}

PointerType *deleteHead(PointerType *header){
    PointerType *TempNode;
    TempNode = header->Next;
    free(header);
    return TempNode;
}

int deleteMiddle(PointerType *prev)
{
    int x;
    PointerType * TempNode;
    x = prev->next->inf;
    TempNode = prev->next;
    prev->next = prev->next->next;  
    free(TempNode);
    return x;
}

PointerType *Insert(PointerType *prev, int X){
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
    TempNode = header;
    while(TempNode->next!=NULL)
    {
        TempNode = TempNode->next;
        printf("%i",TempNode->inf);
    }
}

int isEmpty(PointerType *header)
{
    return !header;
}

PointerType *MakeNull(PointerType *header)
{
    while(!isEmpty(header))
    header=deleteHead(header);
    return header;
}

int main()
{
    PointerType *header;
    int choice = 6;
    int x, place;
    while (choice == 6)
    {
        printf("1. insert\n2. dellete\n3. Print list\n4. check if list is empty\n5. clear list\nEnter: ");
        scanf("%i", &choice);
        if (choice == 1)
        {
            
            printf("enter place you want to insert: ");
            scanf("%i",&place);
            printf("enter number you want to insert: ");
            scanf("%i",&x);
            Insert(place(place),x);
        }
        else if (choice == 2)
        {
            printf("enter place you want to insert: ");
            scanf("%i",&place);
            if(place == 0)
            {
                deleteHead(header);
            }
            else
            {
                PointerType *temp;
                temp->next=header->next
                for(;place > 0;place--)
                {
                    temp->next=temp->next-next;
                }
            }
        }
        else if (choice == 3)
        {
        }
        else if (choice == 4)
        {
        }
        else
        {
        }
        printf("\nenter 6 to continue: ");
        scanf("%i", &choice);
    }
}
