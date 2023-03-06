#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *random_number(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() * n + 1;
    }
    return arr;
}

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void merge(int arr[], int f, int m, int l)
{
    int first1 = f;
    int first2 = m + 1;
    int temp[l - f + 1];
    int i = 0;

    while (first1 <= m && first2 <= l)
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
    while (first1 <= m)
    {
        temp[i] = arr[first1];
        first1++;
        i++;
    }
    while (first2 <= l)
    {
        temp[i] = arr[first2];
        first2++;
        i++;
    }
    for (int j = f; j <= l; j++)
    {
        arr[j] = temp[j - f];
    }
    
}

void mergeSort(int arr[], int f, int l)
{
    int m;
    if (f < l)
    {
        m = (f + l) / 2;
        mergeSort(arr, f, m);
        mergeSort(arr, m + 1, l);
        merge(arr, f, m, l);
    }
}


int partition(int arr[], int l, int r)
{
    int i = l, pivot = arr[l], j = r;
    while (i < j)
    {
        while (i <= r && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= l && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void insertion_sort(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
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

void quickSort(int arr[], int l, int r)
{
    if(r-l<1)
    {
        insertion_sort(arr,l,r);
    }
    else
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}
void Heapify(int arr[], int i, int n)
{
    i++;
    int left = i * 2-1, right = i * 2, big;
    i--;
    if (left <= n && arr[left] > arr[i])
    {
        big = left;
    }
    else
    {
        big = i;
    }
    if (right <= n && arr[right] > arr[big])
    {
        big = right;
    }
    if (big != i)
    {
        swap(&arr[i], &arr[big]);
        Heapify(arr, big, n);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void sort(int arr[],int n)
{
    buildHeap(arr,n);
    for(int i = n;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        Heapify(arr,0,i-1);
    }
}

int main()
{
    int n = 19999;
    int arr[n];
    random_number(n,arr);
    clock_t time1=clock();
    mergeSort(arr,0,n-1);
    time1=clock()-time1;
    float time_taken1 = ((float)time1)/CLOCKS_PER_SEC;

    clock_t time2=clock();
    quickSort(arr,0,n-1);
    time2=clock()-time2;
    float time_taken2 = ((float)time2)/CLOCKS_PER_SEC;

    clock_t time3=clock();
    sort(arr,n-1);
    time3=clock()-time3;
    float time_taken3 = ((float)time3)/CLOCKS_PER_SEC;
    printf("it took %f second to execute merge sort\nit took %f second to execute quick sort\nit took %f second to execute heap sort\n",time_taken1,time_taken2,time_taken3);
}
