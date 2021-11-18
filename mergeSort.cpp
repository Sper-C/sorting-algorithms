#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int randomNumber(int n)
{
    return rand() % (n - 1 + 1) + 1;
}

int *initRandomArray(int &n)
{
    cout << "How many elements?" << endl;
    cin >> n;
    cout << "Size of element?" << endl;
    int size;
    cin >> size;
    int *arr = new int[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = randomNumber(size);
    }
    return arr;
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int merge(int *a, int left, int mid, int right)
{
    int *temp = new int[right - left + 1];

    //*Mảng thứ nhất từ left đến mid, mảng thứ hai từ mid+1 đến right
    int k = 0;
    int i = left;
    int j = mid + 1;
    int count_compare = 0;

    //?Khi hai mảng con chưa xét đến phần tử cuối
    while (i <= mid && j <= right)
    {
        count_compare += 2;
        //?So sánh phần tử đầu mỗi mảng và cho vào mảng phụ
        if (++count_compare && a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    count_compare += 2;

    //?Chép các phần tử còn lại (nếu còn)
    while (++count_compare && i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (++count_compare && j <= right)
    {
        temp[k++] = a[j++];
    }

    //?Chép mảng phụ lại vào mảng chính
    for (int i = left; ++count_compare && i <= right; i++)
    {
        //*Index của a tính từ left
        a[i] = temp[i - left];
    }

    return count_compare;
}

int mergeSort(int *a, int left, int right)
{
    if (left >= right)
        return 1;

    //*Tìm vị trí giữa mảng để chia
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    return merge(a, left, mid, right);
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
    count_compare = mergeSort(a, 0, n - 1);
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

int main()
{
    measure();

    system("pause");
    return 0;
}
