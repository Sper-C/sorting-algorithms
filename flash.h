#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

void swap(int &a, int &b);
void flashSort(int a[], int n);
int measureFlashComp(int *a, int n);
double measureFlashTime(int * a,int n);