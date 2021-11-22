#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

int *initRandomArray(int &n);
void printArray(int *a, int n);

void measure();