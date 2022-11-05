#include<stdio.h>
int main()
{
    int num ,i = -1 , arr[15];
    printf("enter: ");
    scanf("%i",&num);

    while(num != 0)
    {
        arr[++i]= num % 2;
        num /= 2;
    }
    
    printf("Binary: ");
    while(i >= 0)
    {
        printf("%i",arr[i--]);
    }
    return 0;
}
