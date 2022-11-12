#include <stdio.h>
#include <string.h>

void merge(int arr[], int p, int q, int r)
{
    int first1 = p, last1 = q;
    int first2 = q + 1, last2 = r;
    int temp[r - p + 1];
    int i = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] < arr[first2])
        {

            temp[i] = arr[first1];
            first1++;
        }
        else
        {
            temp[i] = arr[first2];
            first2++;
        }
        i++;
    }
    while (first1 <= last1)
    {
        temp[i] = arr[first1];
        first1++;
        i++;
    }
    while (first2 <= last2)
    {
        temp[i] = arr[first2];
        first2++;
        i++;
    }
    for (int j = p; j <= r; j++)
    {
        arr[j] = temp[j - p];
    }
}

void sort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        sort(arr, p, q);
        sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int a[50], n;
    printf("enter n: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter element of array: ");
        scanf("%i", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    sort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
}
