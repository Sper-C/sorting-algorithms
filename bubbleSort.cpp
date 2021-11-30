#include <iostream>
using namespace std;
// Hàm đổi chỗ hai phần tử
void Swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}
/*
     Tham sồ đầu vào của hàm:
     - Mảng: a[]
     - Số lượng phần tử trong mảng: n
*/
void bubbleSort(int a[], int n)
{
     // Chỉ cần xét từ 0 đến n-2 vì ta cần xét a[i] và a[i+1]
     for (int i = 0; i < n - 1; i++)
     {
          /*   
               Xét hai phần tử liên tiếp nhau trong dãy.
               Chỉ xét đến n-i-1 vì sau mỗi lần so sánh và đổi chỗ thì luôn đưa
               được phần tử lớn nhất ra cuối dãy và lần duyệt sau thì ta không cần 
               xét đến phần tử lớn nhất đó nữa
          */
          for (int j = 0; j < n - i - 1; j++)
          {
               // So sánh và đối chỗ hai phần tử liên tiếp nhau
               if (a[j] > a[j + 1])
               {
                    Swap(a[j], a[j + 1]);
               }
          }
     }
}

void bubbleSort_experiment(int a[], int n, int &count_cmp)
{
     for (int i = 0; ++count_cmp && i < n - 1; i++)
     {
          for (int j = 0; ++count_cmp && j < n - i - 1; j++)
          {
               if (++count_cmp && a[j] > a[j + 1])
               {
                    Swap(a[j], a[j + 1]);
               }
          }
     }
}

int main()
{
     int a[8] = {6, 5, 3, 1, 8, 7, 2, 4};
     bubbleSort(a, 8);
     for (int i = 0; i < 8; i++)
     {
          cout << a[i] << " ";
     }
     system("pause");
     return 0;
}