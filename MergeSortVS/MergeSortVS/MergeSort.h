#pragma once
#include <vector>
#include <cstddef>

using namespace std;

/**
 * @file MergeSort.h
 * @brief Definicja oraz implementacja szablonowej klasy MergeSort.
 */

 /**
  * @class MergeSort
  * @brief Klasa realizująca algorytm sortowania przez scalanie (Merge Sort).
  * @tparam T Typ danych przechowywanych w sortowanej tablicy (np. int, long int, double, float).
  */
template <typename T>
class MergeSort {
public:
    /**
     * @brief Sortuje przekazaną tablicę (wektor) rosnąco.
     *
     * Dla tablic pustych oraz jednoelementowych metoda kończy działanie
     * bez modyfikacji danych i bez rzucania wyjątków.
     *
     * @param arr Referencja do wektora elementów typu T do posortowania.
     */
    void sort(vector<T>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    /**
     * @brief Rekurencyjnie dzieli tablicę na dwie podtablice i je sortuje.
     * @param arr Referencja do sortowanego wektora.
     * @param left Indeks początku aktualnego przedziału.
     * @param right Indeks końca aktualnego przedziału.
     */
    void mergeSort(vector<T>& arr, size_t left, size_t right) {
        if (left >= right) {
            return;
        }

        size_t mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    /**
     * @brief Scala dwie posortowane podtablice w jedną posortowaną całość.
     * @param arr Referencja do wektora zawierającego podtablice.
     * @param left Indeks początku lewej podtablicy.
     * @param mid Indeks końca lewej podtablicy.
     * @param right Indeks końca prawej podtablicy.
     */
    void merge(vector<T>& arr, size_t left, size_t mid, size_t right) {
        size_t leftSize = mid - left + 1;
        size_t rightSize = right - mid;

        vector<T> leftArr(leftSize);
        vector<T> rightArr(rightSize);

        for (size_t i = 0; i < leftSize; ++i) {
            leftArr[i] = arr[left + i];
        }
        for (size_t j = 0; j < rightSize; ++j) {
            rightArr[j] = arr[mid + 1 + j];
        }

        size_t i = 0;
        size_t j = 0;
        size_t k = left;

        while (i < leftSize && j < rightSize) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            }
            else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        while (i < leftSize) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        while (j < rightSize) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }
};