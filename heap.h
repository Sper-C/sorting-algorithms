#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

void printArray(int *a, int n);
int *initRandomArray(int &n);
void measure();