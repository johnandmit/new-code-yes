#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    printf("Enter n: ");
    scanf("%i", &n);
    if (n < 2)
    {
        printf("n is not prime");
    }
    else
    {
        for (i = 2; i <= sqrt(n); i++)
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
