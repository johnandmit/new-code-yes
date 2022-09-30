#include <stdio.h>

int recursion(int n, int count, int past, int present)
{
    if (count < n)
        return recursion(n, ++count, present, past + present);
    return present;
}

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printf("%i\n\n", recursion(n-1, 1, 0, 1));

    int present = 1, past = 0, temp;
    for(int i = 1; i < n-1; i++)
    {
        temp = past;
        past = present;
        present = present + temp;
    }
    printf("%i", present);
}
