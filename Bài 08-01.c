#include <stdio.h>

int steps(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return steps(n-1)+steps(n-2);
}

int main(){
    int n;
    printf("enter steps: ");
    scanf("%i", &n);
    printf("possible combination of steps:%i",steps(n));
}
