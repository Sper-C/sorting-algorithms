#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

int heapSort(int *arr, int n);
int measureHeapComp(int *a, int n);
double measureHeapTime(int *a, int n);