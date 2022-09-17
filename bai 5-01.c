#include<stdio.h>
int main()
{
    int n, small, i = 0;
    printf("enter n: ");
    scanf("%i",&n);
    int a[n];
    for(;i<n;i++)
    {
        printf("enter a[%i]: ",i);
        scanf("%i",&a[i]);
    }
    small = a[0];
    i = 1;
    for(;i<n;i++)
    {
        if(a[i]< small)
        {
            small = a[i];
        }
    }
    printf("%i",small);
}   
