#include <stdio.h>
#include <time.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int *insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int last = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > last)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = last;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

void bubbleMan(int arr[],int n)
{
    for(int i = n;i>=0;i--)
    {
        for(int j=1;j<i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}

int main()
{
    int arr[10] = {8, 5, 1, 6, 3, 4, 0, 9, 2, 7};
    // insertion_sort(arr,10);
    // selectionSort(arr, 10);
    bubbleMan(arr,10);

    for (int yes = 0; yes < 10; yes++)
    {
        printf("%i ", arr[yes]);
    }
    printf("\n");
}
