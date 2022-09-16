#include <stdio.h>
#include <math.h>
int main()
{
    int n, i = 2;
    printf("enter n: ");
    scanf("%i", &n);
    if (n < 2)
    {
        printf("n is not prime");
    }
    else
    {
        for (; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                printf("n is not prime");
                return 0;
            }
        }
        printf("n is prime");
    }
}
