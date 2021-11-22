#include "flash.h"

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int insertionSort(int *a, int n)
{
    int count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > x; j--)
        {
            //*So sánh với phần tử trước đó (i-1), nếu bé hơn thì bắt đầu dời chỗ.
            //*Dời chỗ cho đến khi gặp phần tử nhỏ hơn phần tử thứ i hồi nãy (x).
            a[j + 1] = a[j];
            count_compare += 2;
        }
        count_compare += 2;
        //*Sau đó chèn phần tử i hồi nãy (x) vào vị trí đã tìm ở vòng lặp trên.
        a[j + 1] = x;
    }
    return count_compare;
}

void flashSort(int a[], int n)
{
    //*Tính số bucket và khởi tạo chúng
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
    {
        l[i] = 0;
    }
    //*Tìm max và min
    int max = 0;
    int minVal = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == minVal)
        return;
    //*Đếm số phần tử trong bucket
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    //*Tính chỉ số index của phần tử cuối mỗi bucket
    for (int i = 1; i < m; i++)
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
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
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
    insertionSort(a, n);
}
