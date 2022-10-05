#include <stdio.h>

int solutions = 0;

int steps(int n, char str[], int i)
{
    if (n == 1)
    {
        str[i] = '\0';
        printf("%s1\n", str);
        solutions++;
        return 0;
    }

    else if (n == 2)
    {
        str[i] = '\0';
        printf("%s11\n%s2\n", str, str);
        solutions += 2;
        return 0;
    }
    else
    {
        str[i] = '1';
        i++;
        steps(n - 1, str, i);
        i--;
        str[i] = '2';
        i++;
        steps(n - 2, str, i);
    }
}

int main()
{
    int n;
    char str[100];
    printf("enter steps: ");
    scanf("%i", &n);
    steps(n, str, 0);
    printf("possible combination of steps:%i", solutions);
}
