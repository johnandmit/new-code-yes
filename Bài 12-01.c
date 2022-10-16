#include <stdio.h>
#include <stdlib.h>

typedef struct Node { 
    int data;
    struct Node *next;
} Node;

Node *at(Node *header, int place)
{
    Node *temp;
    temp = header;
    for (; place > 0&&temp->next != NULL; place--)
    {
        temp = temp->next;
    }
    return temp;
}

Node *deleteHead(Node *header)
{
    Node *TempNode;
    TempNode = header->next;
    free(header);
    return TempNode;
}

int deleteMiddle(Node *prev)
{
    int x;
    Node *TempNode;
    x = prev->next->data;
    TempNode = prev->next;
    prev->next = prev->next->next;
    free(TempNode);
    return x;
}

Node *Insert(Node *prev, int X, Node *header)
{
    Node *TempNode;
    TempNode = (Node *)malloc(sizeof(Node));
    TempNode->data = X;
    if(prev->next != NULL)
    {
        TempNode->next = prev->next;
    }
    else
    {
        TempNode->next = header;
    }
    prev->next = TempNode;
    return TempNode;
}

int *printer(Node *header)
{
    Node *TempNode;
    TempNode = header->next;
    printf("the list conclude: ");
    while (TempNode != header)
    {
        printf("%i ", TempNode->data);
        TempNode = TempNode->next;
    }
    printf("\n");
}

int isEmpty(Node *header)
{
    return !header;
}

Node *MakeNull(Node *header)
{
    while (!isEmpty(header))
    {
        
        header = deleteHead(header);
    }
    return header;
}

int count(Node *ptr)
{
    Node *TempNode;
    TempNode = ptr -> next;
    int i = 0;
    while (TempNode != ptr&&TempNode != NULL)
    {
        i++;
        TempNode=TempNode->next;
    }
    return i;
}

int main()
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    int choice = 0, x, place;
    while (1)
    {
        printf("1. insert\n2. dellete\n3. Print list\n4. check if list is empty\n5. clear list\n6. find number of elements in list\n7. end programme\nEnter: ");
        scanf("%i", &choice);
        if (choice == 7)
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
            printf("enter place you want to delete: ");
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
                printf("list is empty");
            }
        }
        else if(choice == 5)
        {
            MakeNull(header);
            header = (Node *)malloc(sizeof(Node));
            header->next = NULL;
        }
        else
        {
            printf("enter place you want to find pointer: ");
            scanf("%i", &place);
            printf("%i\n",count(at(header, place)));
        }
    }
}
