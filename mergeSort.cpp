#include "merge.h"

void merge(int *a, int left, int mid, int right)
{
    //*Khởi tạo mảng phụ
    int *temp = new int[right - left + 1];

    int k = 0;
    int i = left;
    int j = mid + 1;

    //*Trộn mảng chính vào mảng phụ
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    //*Trộn các phần còn lại của mảng trái
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    //*Trộn các phần còn lại của mảng phải
    while (j <= right)
    {
        temp[k++] = a[j++];
    }
    //*Sao chép mảng phụ vào mảng chính
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i - left];
    }
}

void mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        //*chia mảng
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        //*Trộn mảng
        merge(a, left, mid, right);
    }
}
