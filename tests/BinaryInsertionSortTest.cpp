#include "../models/BinaryInsertionSort/BinaryInsertionSort.h"
#include "catch2/catch_all.hpp"

template <typename T>
void runBinaryInsertionSortTest(T *array, int size, T *expected)
{
    if (array == nullptr || expected == nullptr)
    {
        REQUIRE(size == 0); // Check for empty array
        return;
    }

    BinaryInsertionSort<T> sorter(array, size);
    sorter.sort();

    for (int i = 0; i < size; ++i)
    {
        REQUIRE(array[i] == expected[i]);
    }
}

TEST_CASE("BinaryInsertionSort sorts integer array", "[binary_insertion_sort]")
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    runBinaryInsertionSortTest(array, 7, expected);
}

TEST_CASE("BinaryInsertionSort sorts double array", "[binary_insertion_sort]")
{
    double array[] = {64.1, 34.2, 25.3, 12.4, 22.5, 11.6, 90.7};
    double expected[] = {11.6, 12.4, 22.5, 25.3, 34.2, 64.1, 90.7};
    runBinaryInsertionSortTest(array, 7, expected);
}

TEST_CASE("BinaryInsertionSort handles empty array", "[binary_insertion_sort]")
{
    int *array = nullptr;
    int *expected = nullptr;
    runBinaryInsertionSortTest(array, 0, expected);
}

TEST_CASE("BinaryInsertionSort handles single-element array", "[binary_insertion_sort]")
{
    int array[] = {42};
    int expected[] = {42};
    runBinaryInsertionSortTest(array, 1, expected);
}

TEST_CASE("BinaryInsertionSort handles already sorted array", "[binary_insertion_sort]")
{
    int array[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    runBinaryInsertionSortTest(array, 5, expected);
}

TEST_CASE("BinaryInsertionSort handles reverse sorted array", "[binary_insertion_sort]")
{
    int array[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    runBinaryInsertionSortTest(array, 5, expected);
}

TEST_CASE("BinaryInsertionSort handles duplicates", "[binary_insertion_sort]")
{
    int array[] = {3, 1, 2, 3, 2};
    int expected[] = {1, 2, 2, 3, 3};
    runBinaryInsertionSortTest(array, 5, expected);
}
