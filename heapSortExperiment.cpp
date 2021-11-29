#include "heap.h"

void heapifyComp(int *arr, int n, int i, int &count_compare)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((++count_compare && l < n) && (++count_compare && arr[l] > arr[largest]))
        largest = l;

    if ((++count_compare && r < n) && (++count_compare && arr[r] > arr[largest]))
        largest = r;

    if (++count_compare && largest != i)
    {
        swap(arr[i], arr[largest]);

        heapifyComp(arr, n, largest, count_compare);
    }
}

void heapSortComp(int *arr, int n,int &count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        heapifyComp(arr, n, i, count_compare);
    }

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapifyComp(arr, i, 0, count_compare);
    }
}

int measureHeapComp(int *a, int n)
{
    int count_compare = 0;
    heapSortComp(a,n,count_compare);
    return count_compare;
}

double measureHeapTime(int *a, int n)
{
    auto start = high_resolution_clock::now();
    heapSort(a, n);
    auto stop = high_resolution_clock::now();
    auto runtime = stop - start;
    return duration<double, milli>(runtime).count();
}
