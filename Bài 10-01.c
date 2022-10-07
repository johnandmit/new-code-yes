#include <stdio.h>
#define MAXLEN 100
typedef struct LIST
{
    int elements[MAXLEN];
    int last;
} list_type;

list_type insert(int x, int p, list_type L)
{
    if (p > L.last && L.last >= MAXLEN)
    {
        printf("overflow\n");
    }
    else if (p < 0 || p > L.last + 1)
    {
        printf("u gay y no eyes?\n");
    }
    else
    {
        for (int q = L.last; q >= p; q--)
        {
            L.elements[q + 1] = L.elements[q];
        }
        L.last++;
        L.elements[p] = x;
        return L;
    }
}

list_type Delete(int p, list_type L)
{
    if (p < 0 || p > L.last)
    {
        printf("no p in list\n");
    }
    else
    {
        for (int i = p; i < L.last; i++)
        {
            L.elements[i] = L.elements[i + 1];
        }
        L.last--;
        return L;
    }
}

int printList(list_type L)
{

    for (int i = 0; i < L.last; i++)
    {
        printf("%i\n", L.elements[i]);
    }
}

int Locate(int x, list_type L)
{
    for (int q = 0; q < L.last; q++)
    {
        if (L.elements[q] == x)
        {
            printf("x was found in index %i\n", q);
        }
    }
}

int main()
{
    int x, p, choice = 5;
    list_type L;
    L.last = 0;
    while (choice == 5)
    {
        printf("1. insert x in list at index p\n2. dellete index p in list\n3. Print list\n4. find x in list\nEnter: ");
        scanf("%i", &choice);
        if (choice == 1)
        {
            printf("enter x: ");
            scanf("%i", &x);
            printf("enter p: ");
            scanf("%i", &p);
            L = insert(x, p, L);
        }
        else if (choice == 2)
        {
            printf("enter p: ");
            scanf("%i", &p);
            L = Delete(p, L);
        }
        else if (choice == 3)
        {
            printList(L);
        }
        else
        {
            printf("enter x: ");
            scanf("%i", &x);
            Locate(x, L);
        }
        printf("\nenter 5 to continue: ");
        scanf("%i", &choice);
    }
}
