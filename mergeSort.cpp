#include "merge.h"

int merge(int *a, int left, int mid, int right)
{
    int *temp = new int[right - left + 1];

    //*Mảng thứ nhất từ left đến mid, mảng thứ hai từ mid+1 đến right
    int k = 0;
    int i = left;
    int j = mid + 1;

    //?Khi hai mảng con chưa xét đến phần tử cuối
    while (i <= mid && j <= right)
    {
        //?So sánh phần tử đầu mỗi mảng và cho vào mảng phụ
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    //?Chép các phần tử còn lại (nếu còn)
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= right)
    {
        temp[k++] = a[j++];
    }

    //?Chép mảng phụ lại vào mảng chính
    for (int i = left; i <= right; i++)
    {
        //*Index của a tính từ left
        a[i] = temp[i - left];
    }
}

int mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        //*Tìm vị trí giữa mảng để chia
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        return merge(a, left, mid, right);
    }
}


