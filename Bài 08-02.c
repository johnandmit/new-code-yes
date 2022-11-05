#include <stdio.h>

int recursion(int n)
{
    if (n <= 1)
        return n;
    else 
        return recursion(n-1)+recursion(n-2);
}
int nonRecursion(int n)
{
    int present = 1, past = 0, temp;
    for (int i = 1; i < n; i++)
    {
        temp = past;
        past = present;
        present = present + temp;
    }
    return present;
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printf("Recurnsion: %i\n\n", recursion(n-1));
    printf("Non-recursion: %i", nonRecursion(n-1));
}
