#include "flash.h"

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

int main(int agrc, char **argv)
{
    int n;
    int * a = initRandomArray(n);
    cout<<"-------------------------"<<endl;
    cout<<"Run time: "<< measureFlashTime(a,n)<<endl;
    cout<<"Comparison: "<<measureFlashComp(a,n)<<endl;
    
    system("pause");
    return 0;
}
