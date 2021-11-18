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

// To heapify a subtree rooted with node i, which is an index in arr.
// n is size of heap
int heapify(int *arr, int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        return 5 + heapify(arr, n, largest);
    }
}

// main function to do heap sort
int heapSort(int *arr, int n)
{
    int count_compare = 0;

    // Build heap (rearrange array) from middle to beginning of the array
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        count_compare += heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        count_compare += heapify(arr, i, 0);
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
    count_compare = heapSort(a, n);
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
