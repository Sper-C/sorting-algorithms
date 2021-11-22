#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

void printArray(int *a, int n);
int *initRandomArray(int &n);
void swap(int &a, int &b);
void insertionSort(int *a, int n);
void flashSort(int *a, int n);
void measure();