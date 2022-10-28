#include <stdio.h>

int arr[5], n = 5, f = 0, r = 0;

int size()
{
    return (n-f+r)%n;
}

void enqueue(int val)
{
    if(size() == n-1)
    {
        printf("shorty like a melody");
    }
    else
    {
        arr[r] = val;
        r = (r + 1) % n; 
    }
}

int dequeue()
{
    int val;
    if(f == r)
    {
        printf("full");
    }
    else
    {
       val = arr[f];
       f = (f+1) % n; 
    }
    return val;
}

void display()
{
    int i = f;
    while(i!=r)
    {
        printf("%i ",arr[i]);
        i = (i+1)%n;
    }
}

int main()
{
    // printf("enter length of queue: ");
    // scanf("%i",&n);
    int val, choice = 1;
    while(choice != 0)
    {
        printf("\n1. enqueue\n2. dequeue\n3. print\nother. exit\nenter: ");
        scanf("%i",&choice);
        if(choice == 1)
        {
            printf("enter value: ");
            scanf("%i",&val);
            enqueue(val);
        }
        else if(choice == 2)
        {
            printf("%i",dequeue());
        }
        else if(choice == 3)
        {
            display();
        }
        else
        {
            choice = 0;
        }
    }
}
