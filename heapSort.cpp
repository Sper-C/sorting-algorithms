#include "heap.h"

void heapify(int *arr, int n, int i)
{
    int largest = i;   
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    //*So sánh với node con trái
    if (l < n && arr[l] > arr[largest])
        largest = l;
    //*với node con phải
    if (r < n && arr[r] > arr[largest])
        largest = r;
    //*Đổi chỗ với node con và tiến hành heapify ở node con.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    //*Xây dựng max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    //*Sắp xếp kèm heapify
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}