#include "../models/SelectionSort/SelectionSort.h"
#include "catch2/catch_all.hpp"

template <typename T>
void runSelectionSortTest(T *array, int size, T *expected)
{
    if (array == nullptr || expected == nullptr)
    {
        REQUIRE(size == 0); // Проверка на пустой массив
        return;
    }

    SelectionSort<T> sorter(array, size);
    sorter.sort();

    for (int i = 0; i < size; ++i)
    {
        REQUIRE(array[i] == expected[i]);
    }
}

TEST_CASE("Selection sort sorts integer array", "[selection_sort]")
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    runSelectionSortTest(array, 7, expected);
}

TEST_CASE("Selection sort sorts double array", "[selection_sort]")
{
    double array[] = {64.1, 34.2, 25.3, 12.4, 22.5, 11.6, 90.7};
    double expected[] = {11.6, 12.4, 22.5, 25.3, 34.2, 64.1, 90.7};
    runSelectionSortTest(array, 7, expected);
}

TEST_CASE("Selection sort handles empty array", "[selection_sort]")
{
    int *array = nullptr;
    int *expected = nullptr;
    runSelectionSortTest(array, 0, expected);
}

TEST_CASE("Selection sort handles single element array", "[selection_sort]")
{
    int array[] = {42};
    int expected[] = {42};
    runSelectionSortTest(array, 1, expected);
}

TEST_CASE("Selection sort handles already sorted array", "[selection_sort]")
{
    int array[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    runSelectionSortTest(array, 5, expected);
}

TEST_CASE("Selection sort handles reverse sorted array", "[selection_sort]")
{
    int array[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    runSelectionSortTest(array, 5, expected);
}

TEST_CASE("Selection sort handles duplicates", "[selection_sort]")
{
    int array[] = {3, 1, 2, 3, 2};
    int expected[] = {1, 2, 2, 3, 3};
    runSelectionSortTest(array, 5, expected);
}
