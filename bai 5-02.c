#include<stdio.h>
int main()
{
    int n, small, i;
    
    printf("Enter n: ");
    scanf("%i",&n);
    
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("- Enter a[%i]: ",i);
        scanf("%i",&a[i]);
    }
    small = a[0];
    for(i = 1;i<n;i++)
    {
        if(a[i]< small)
        {
            small = a[i];
        }
    }
    printf("Minimum = %i",small);
}   
