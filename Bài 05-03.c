#include <stdio.h>
int main()
{
    int a, b;
    
    printf("Enter a: ");
    scanf("%i", &a);
    printf("Enter b: ");
    scanf("%i", &b);
    
    while (a != b)
    {
        if (a < b)
        {
            b = b - a;
        }
        else
        {
            a = a - b;
        }
    }
    
    printf("GCD = %i", a);
}
