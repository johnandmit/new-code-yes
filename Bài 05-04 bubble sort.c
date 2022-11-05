#include<stdio.h>
int main()
{
    int n,a[10],i;

    printf("Enter n: ");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a(%i): ", i);
        scanf("%d", &a[i]);
    }

    for (i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if(a[j-1] > a[j])
            {
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("sorted array =\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
}
