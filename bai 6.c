#include <stdio.h>

int *merge(int l[],int r[])
{
    int i = 0, j = 0, new[100];
    while(l[j]!='\0')
    {
        new[i]=l[j];
        i++;
        j++;
    }

    j=0;

    while(r[j]!='\0')
    {
        new[i]=r[j];
        i++;
        j++;
    }
}

int *mergeSort(int l[],int r[])
{
    
}

int main()
{
    int arr[100]
    printf("enter arr: ");
    scanf("%i",arr);
}
