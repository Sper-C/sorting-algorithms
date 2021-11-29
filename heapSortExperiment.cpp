#include "heap.h"

void heapifyCompare(int *arr, int n, int i, int &count_compare)
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

        heapifyCompare(arr, n, largest, count_compare);
    }
}

int countHeapSortCompare(int *arr, int n)
{
    int count_compare = 0;

    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        heapifyCompare(arr, n, i, count_compare);
    }

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapifyCompare(arr, i, 0, count_compare);
    }

    return count_compare;
}

void measure()
{
    int n;
    int *a = initRandomArray(n);
    int count_compare = 0;

    cout << "Display?\nYes: 1\nNo: 0" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        printArray(a, n);
    }

    auto start = high_resolution_clock::now();
    count_compare = countHeapSortCompare(a, n);
    auto stop = high_resolution_clock::now();
    auto runtime = stop - start;
    cout << "Run time: " << chrono::duration<double, milli>(runtime).count() << endl;

    cout << "Comparision time: " << count_compare << endl;
    cout << "--------------------- " << endl;
    cout << "--------------------- " << endl;

    if (choice == 1)
    {
        printArray(a, n);
    }
}
