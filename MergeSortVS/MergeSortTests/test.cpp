#include "pch.h"
#include <vector>
#include <algorithm>
#include <random>
#include "../MergeSortVS/MergeSort.h"

using namespace std;

// 1. Zachowuje tablicę niezmienioną, gdy jest już posortowana rosnąco
TEST(MergeSortTest, AlreadySortedAscending) {
    MergeSort<int> sorter;
    vector<int> arr = { 1, 2, 3, 4, 5, 10, 20 };
    vector<int> expected = { 1, 2, 3, 4, 5, 10, 20 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Potrafi posortować tablicę posortowaną w odwrotnej kolejności
TEST(MergeSortTest, ReverseOrder) {
    MergeSort<int> sorter;
    vector<int> arr = { 9, 7, 5, 3, 1, 0, -2 };
    vector<int> expected = { -2, 0, 1, 3, 5, 7, 9 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Poprawnie sortuje losową tablicę liczb
TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    vector<int> arr = { 42, 7, 19, 3, 88, 15, 64, 1, 29 };
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Poprawnie sortuje tablicę tylko z liczbami ujemnymi
TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    vector<int> arr = { -5, -100, -1, -42, -13, -7 };
    vector<int> expected = { -100, -42, -13, -7, -5, -1 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Poprawnie sortuje tablicę z liczbami ujemnymi i dodatnimi
TEST(MergeSortTest, NegativeAndPositiveNumbers) {
    MergeSort<double> sorter;
    vector<double> arr = { 12.5, -3.4, 0.0, -18.1, 7.2, 4.0, -0.5 };
    vector<double> expected = { -18.1, -3.4, -0.5, 0.0, 4.0, 7.2, 12.5 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(MergeSortTest, EmptyArrayNoThrow) {
    MergeSort<int> sorter;
    vector<int> arr = {};

    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortTest, SingleElement) {
    MergeSort<int> sorter;
    vector<int> arr = { 42 };
    vector<int> expected = { 42 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 8. Poprawnie sortuje tablicę z duplikatami liczb
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort<int> sorter;
    vector<int> arr = { 5, 2, 8, 2, 5, 1, 8, 5 };
    vector<int> expected = { 1, 2, 2, 5, 5, 5, 8, 8 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Poprawnie sortuje tablicę ujemną z duplikatami
TEST(MergeSortTest, NegativeWithDuplicates) {
    MergeSort<int> sorter;
    vector<int> arr = { -3, -10, -3, -1, -10, -7, -1 };
    vector<int> expected = { -10, -10, -7, -3, -3, -1, -1 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Poprawnie sortuje tablicę z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, NegativePositiveAndDuplicates) {
    MergeSort<int> sorter;
    vector<int> arr = { 4, -2, 0, 4, -5, -2, 7, 0, -5 };
    vector<int> expected = { -5, -5, -2, -2, 0, 0, 4, 4, 7 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(MergeSortTest, TwoElementsAscending) {
    MergeSort<int> sorter;
    vector<int> arr = { 10, 25 };
    vector<int> expected = { 10, 25 };

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(MergeSortTest, LargeArrayOver100Elements) {
    MergeSort<int> sorter;
    vector<int> arr;
    arr.reserve(150);

    mt19937 gen(12345);
    uniform_int_distribution<int> dist(1, 10000);
    for (int i = 0; i < 150; ++i) {
        arr.push_back(dist(gen));
    }

    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Poprawnie sortuje dużą tablicę (>100 elementów) z liczbami ujemnymi, dodatnimi i duplikatami
TEST(MergeSortTest, LargeArrayOver100MixedAndDuplicates) {
    MergeSort<int> sorter;
    vector<int> arr;
    arr.reserve(150);

    // Mały zakres [-25, 25] przy 150 elementach gwarantuje liczby ujemne, dodatnie, zero i liczne duplikaty
    mt19937 gen(67890);
    uniform_int_distribution<int> dist(-25, 25);
    for (int i = 0; i < 150; ++i) {
        arr.push_back(dist(gen));
    }

    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}