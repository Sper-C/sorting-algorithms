#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

int mergeSort(int *a, int left, int right);
int measureMergeComp(int *a, int n);
double measureMergeTime(int *a, int n);