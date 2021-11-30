#include "flash.h"

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void insertionSort(int *a, int n)
{
    for (int i = 1;i < n; i++)
    {
        int x = a[i];
        int j;
        //*Dời chỗ các phần tử để tìm vị trí phù hợp cho x
        for (j = i - 1; j >= 0 && a[j] > x; j--)
        {

            a[j + 1] = a[j];
        }
        //*Chèn x vào vị trí phù hợp
        a[j + 1] = x;
    }
}

void flashSort(int a[], int n)
{
    //*Tìm số bucket
    int m = int(0.45 * n);
    int *l = new int[m];
    //*Khởi tạo mảng các bucket
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
    //*Đếm số phần tử mỗi bucket
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    //*Tính vị trí cuối cùng của mỗi bucket
    for (int i = 1; i < m; i++)
    {
        l[i] += l[i - 1];
    }
    //*Tiến hành hoán vị
    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        //*Khi phần tử nằm đúng phân lớp thì bỏ qua
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        //*Đưa phần tử về đúng phân lớp
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
    //*Insertion Sort cho các phân lớp
    insertionSort(a, n);
}
