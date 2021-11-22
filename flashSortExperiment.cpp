#include "flash.h"

int flashSortExperi(int a[], int n)
{
    int count_compare = 0;
    //*Tính số bucket và khởi tạo chúng
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0;++count_compare && i < m; i++)
    {
        l[i] = 0;
    }
    //*Tìm max và min
    int max = 0;
    int minVal = a[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare&& a[i] < minVal)
            minVal = a[i];
        if (++count_compare&&a[i] > a[max])
            max = i;
    }
    if (++count_compare && a[max] == minVal)
        return count_compare;
    //*Đếm số phần tử trong bucket
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0;++count_compare && i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    //*Tính chỉ số index của phần tử cuối mỗi bucket
    for (int i = 1; ++count_compare && i < m; i++)
    {
        l[i] += l[i - 1];
    }
    //*Hoán vị để sắp xếp
    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++count_compare && nmove < n - 1)
    {
        while (++count_compare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++count_compare && k < 0)
            break;
        while (++count_compare && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    //*Insertion sort từng bucket
    count_compare += insertionSort(a, n);
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
    count_compare = flashSortExperi(a, n);
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

