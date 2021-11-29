#include "heap.h"

void heapify(int *arr, int n, int i, int &count_compare)
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

        heapify(arr, n, largest, count_compare);
    }
}

int heapSort(int *arr, int n)
{
    int count_compare = 0;

    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        heapify(arr, n, i, count_compare);
    }

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0, count_compare);
    }

    return count_compare;
}

void measure(int* a,int n)
{
    int count_compare = 0;
    auto start = high_resolution_clock::now();
    count_compare = heapSort(a, n);
    auto stop = high_resolution_clock::now();
    auto runtime = stop - start;
    cout << "Run time: " << chrono::duration<double, milli>(runtime).count() << endl;

    cout << "Comparision time: " << count_compare << endl;
    cout << "--------------------- " << endl;
    cout << "--------------------- " << endl;
}
