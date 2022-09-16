#include <stdio.h>
int main()
{
    int a, b;
    printf("enter a: ");
    scanf("%i", &a);
    printf("enter b: ");
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
    printf("%i", a);
}
