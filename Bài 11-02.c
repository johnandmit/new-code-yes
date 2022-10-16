#include <stdio.h>
#include <stdlib.h>

struct _Polynomial
{
    int coeff;
    int pow;
    struct _Polynomial *next;
};
typedef struct _Polynomial Polynomial;

Polynomial *at(Polynomial *header, int place)
{
    Polynomial *temp;
    temp = header;
    for (; place > 0&&temp->next != NULL; place--)
    {
        temp = temp->next;
    }
    return temp;
}

Polynomial *deleteHead(Polynomial *header)
{
    Polynomial *TempNode;
    TempNode = header->next;
    free(header);
    return TempNode;
}

int deleteMiddle(Polynomial *prev)
{
    Polynomial *TempNode;
    TempNode = prev->next;
    prev->next = prev->next->next;
    free(TempNode);
}

Polynomial *Insert(Polynomial *prev, int coeff, int pow)
{
    Polynomial *TempNode;
    TempNode = (Polynomial *)malloc(sizeof(Polynomial));
    TempNode->coeff = coeff;
    TempNode->pow = pow;
    TempNode->next = prev->next;
    prev->next = TempNode;
}

Polynomial *printer(Polynomial *header)
{
    Polynomial *TempNode;
    TempNode = header->next;
    while (TempNode != NULL)
    {
        if(TempNode->coeff> 0)
        {
            printf("+ %ix^%i ", TempNode->coeff, TempNode -> pow);
        }
        else
        {
        printf("%ix^%i ", TempNode->coeff, TempNode -> pow);
        }
        TempNode = TempNode->next;
    }
    printf("\n");
}

int isEmpty(Polynomial *header)
{
    return !header;
}

Polynomial *MakeNull(Polynomial *header)
{
    while (!isEmpty(header))
    {
        
        header = deleteHead(header);
    }
    return header;
}

Polynomial *add(Polynomial *header1, Polynomial *header2)
{
    Polynomial *final = (Polynomial *)malloc(sizeof(Polynomial));
    final->next = NULL;
    Polynomial *temp1 = header1->next;
    Polynomial *temp2 = header2->next;
    Polynomial *temp3 = final;
    while(temp1 != NULL && temp2 != NULL)
    {
        printer(temp3);
        if(temp1->pow == temp2->pow)
        {
            Insert(final, temp1->coeff + temp2->coeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1 -> pow > temp2 -> pow)
        {   
            Insert(final, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
        else
        {
            Insert(final, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
        final = final->next;
    }
    while(temp1!=NULL)
    {
        Insert(final, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
        final = final->next;
    }
    while(temp2!=NULL)
    {
        Insert(final, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
        final = final->next;
    }
    return temp3;
}

int count(Polynomial *header)
{
    Polynomial *TempNode;
    TempNode = header -> next;
    int i = 0;
    while (TempNode != NULL)
    {
        i++;
        TempNode=TempNode->next;
    }
    return i;
}

int main()
{
    Polynomial *header1 = (Polynomial *)malloc(sizeof(Polynomial));
    header1->next = NULL;
    Polynomial *header2 = (Polynomial *)malloc(sizeof(Polynomial));
    header2->next = NULL;
    int choice = 0, x, place, function, pow;
    while (1)
    {
        printf("1. insert\n2. dellete\n3. Print list\n4. check if list is empty\n5. clear list\n6. caculate\n7. end programme\nEnter: ");
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
            printf("enter pow you want to insert: ");
            scanf("%i", &pow);
            printf("enter funtion you want to insert: ");
            scanf("%i", &function);
            if(function == 1)
                Insert(at(header1, place), x, pow);
            else 
                Insert(at(header2, place), x, pow);
        }
        else if (choice == 2)
        {
            printf("enter place you want to delete: ");
            scanf("%i", &place);
            printf("enter function you want to dellete: ");
            scanf("%i",&function);
            if (place == 0 && function == 1)
            {
                header1 = deleteHead(header1);
            }
            else if(function == 1)
            {
                deleteMiddle(at(header1, place));
            }
            else if(place == 0 && function == 2)
            {
                header2 = deleteHead(header2);
            }
            else
            {
                deleteMiddle(at(header2, place));
            }
        }
        else if (choice == 3)
        {
            printf("enter funtion you want to print: ");
            scanf("%i", &function);
            if(function == 1)
                printer(header1);
            else
                printer(header2);
            
        }
        else if (choice == 4)
        {
            printf("enter funtion you want to insert: ");
            scanf("%i", &function);
            if(function == 1)
            {
                if(isEmpty(header1))
                {
                    printf("list is empty");
                }
            }
            else
            {
                if(isEmpty(header2))
                {
                    printf("list is empty");
                }
            }
        }
        else if(choice == 5)
        {
            printf("enter funtion you want to delete: ");
            scanf("%i", &function);
            if(function == 1)
            {
                MakeNull(header1);
                header1 = (Polynomial *)malloc(sizeof(Polynomial));
                header1->next = NULL;
            }
            else
            {
                MakeNull(header2);
                header2 = (Polynomial *)malloc(sizeof(Polynomial));
                header2->next = NULL;
            }
        }
        else
        {
            Polynomial *temp = (Polynomial *)malloc(sizeof(Polynomial));
            temp ->next = NULL;
            temp = add(header1, header2);
            printer(temp);
        }
    }
}
