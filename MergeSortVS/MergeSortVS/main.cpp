#include <iostream>
#include <vector>
#include "MergeSort.h"

using namespace std;

template <typename T>
void printArray(const vector<T>& arr) {
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << "\n";
}

int main() {
    // 1. Instancja dla liczb typu int
    MergeSort<int> intSorter;
    vector<int> intArray = { 38, -5, 27, 43, 3, -12, 9, 82, 10 };

    cout << "Tablica int przed sortowaniem: ";
    printArray(intArray);

    intSorter.sort(intArray);

    cout << "Tablica int po sortowaniu:    ";
    printArray(intArray);

    cout << "\n";

    // 2. Instancja dla liczb typu double
    MergeSort<double> doubleSorter;
    vector<double> doubleArray = { 3.14, -2.71, 0.0, 42.5, -10.25, 3.14, 1.618 };

    cout << "Tablica double przed sortowaniem: ";
    printArray(doubleArray);

    doubleSorter.sort(doubleArray);

    cout << "Tablica double po sortowaniu:    ";
    printArray(doubleArray);

    return 0;
}