#include "merge.h"

int mergeExper(int *a, int left, int mid, int right, int &count_compare)
{
    int *temp = new int[right - left + 1];

    int k = 0;
    int i = left;
    int j = mid + 1;

    while ((++count_compare && i <= mid) && (++count_compare && j <= right))
    // while (i <= mid && j <= right)
    {
        if (++count_compare && a[i] <= a[j])
        // if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
        count_compare += 1;
    }
    while (++count_compare && i <= mid)
    // while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (++count_compare && j <= right)
    // while (j <= right)
    {
        temp[k++] = a[j++];
    }

    for (int i = left; ++count_compare && i <= right; i++)
    // for (int i = left; i <= right; i++)
    {
        a[i] = temp[i - left];
    }
}

void mergeSortExper(int *a, int left, int right, int &count_compare)
{
    if (++count_compare && left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortExper(a, left, mid, count_compare);
    mergeSortExper(a, mid + 1, right, count_compare);
    mergeExper(a, left, mid, right, count_compare);
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
    mergeSortExper(a, 0, n - 1,count_compare);
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