#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    printf("enter n: ");
    scanf("%i", &n);
    if (n < 2)
    {
        printf("N is not prime");
    }
    else
    {
        for (i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                printf("N is not prime");
                return 0;
            }
        }
        printf("N is prime");
    }
}
