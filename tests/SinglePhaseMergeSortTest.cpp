#include "../models/SinglePhaseMergeSort/SinglePhaseMergeSort.h"
#include "catch2/catch_all.hpp"

template <typename T>
void runSinglePhaseMergeSortTest(T *array, int size, T *expected)
{
    if (array == nullptr || expected == nullptr)
    {
        REQUIRE(size == 0); // Check for empty array
        return;
    }

    SinglePhaseMergeSort<T> sorter(array, size);
    sorter.sort();

    for (int i = 0; i < size; ++i)
    {
        REQUIRE(array[i] == expected[i]);
    }
}

TEST_CASE("SinglePhaseMergeSort sorts integer array", "[single_phase_merge_sort]")
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    runSinglePhaseMergeSortTest(array, 7, expected);
}

TEST_CASE("SinglePhaseMergeSort sorts double array", "[single_phase_merge_sort]")
{
    double array[] = {64.1, 34.2, 25.3, 12.4, 22.5, 11.6, 90.7};
    double expected[] = {11.6, 12.4, 22.5, 25.3, 34.2, 64.1, 90.7};
    runSinglePhaseMergeSortTest(array, 7, expected);
}

TEST_CASE("SinglePhaseMergeSort handles empty array", "[single_phase_merge_sort]")
{
    int *array = nullptr;
    int *expected = nullptr;
    runSinglePhaseMergeSortTest(array, 0, expected);
}

TEST_CASE("SinglePhaseMergeSort handles single-element array", "[single_phase_merge_sort]")
{
    int array[] = {42};
    int expected[] = {42};
    runSinglePhaseMergeSortTest(array, 1, expected);
}

TEST_CASE("SinglePhaseMergeSort handles already sorted array", "[single_phase_merge_sort]")
{
    int array[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    runSinglePhaseMergeSortTest(array, 5, expected);
}

TEST_CASE("SinglePhaseMergeSort handles reverse sorted array", "[single_phase_merge_sort]")
{
    int array[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    runSinglePhaseMergeSortTest(array, 5, expected);
}

TEST_CASE("SinglePhaseMergeSort handles duplicates", "[single_phase_merge_sort]")
{
    int array[] = {3, 1, 2, 3, 2};
    int expected[] = {1, 2, 2, 3, 3};
    runSinglePhaseMergeSortTest(array, 5, expected);
}
