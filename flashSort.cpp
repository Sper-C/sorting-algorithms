#include "flash.h"

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > x; j--)
        {
            //*So sánh với phần tử trước đó (i-1), nếu bé hơn thì bắt đầu dời chỗ.
            //*Dời chỗ cho đến khi gặp phần tử nhỏ hơn phần tử thứ i hồi nãy (x).
            a[j + 1] = a[j];
        }
        //*Sau đó chèn phần tử i hồi nãy (x) vào vị trí đã tìm ở vòng lặp trên.
        a[j + 1] = x;
    }
}

void flashSort(int *a, int n)
{
    //*Khởi tạo các bucket
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    //*Tìm max và min
    int min = a[0];
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    //*Chỉ có một phần tử thì kết thúc
    if (max == min)
        return;
    //*Đếm số phần tử trong xô
    double c1 = (double)(m - 1) / (a[max] - min);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - min));
        l[k]++;
    }
    //*Tính index cuối cùng của từng bucket
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
    //*Hoán vị các phần tử
    int hold = a[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;
    while (move < n - 1)
    {
        while(j > (l[k]-1))
        {
            j++;
        }
        
        flash = a[j];
        while(j!=l[k])
        {
            double c1 = (double)(m - 1) / (a[max] - min);
            int k = int(c1 * (a[j] - min));
            hold = a[t=--l[k]];
            a[t] = hold;
            flash = hold;
            move++;
        }
    }
    //*Insertion Sort
    insertionSort(a, n);
}
