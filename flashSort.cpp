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
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
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
    insertionSort(a, n);
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
    // count_compare = flashSort(a, n);
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
