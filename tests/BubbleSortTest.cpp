#include "../models/BubbleSort/BubbleSort.h"
#include "catch2/catch_all.hpp"

template <typename T>
void runBubbleSortTest(T *array, int size, T *expected)
{
    if (array == nullptr || expected == nullptr)
    {
        REQUIRE(size == 0); // Проверка на пустой массив
        return;
    }

    BubbleSort<T> sorter(array, size);
    sorter.sort();

    for (int i = 0; i < size; ++i)
    {
        REQUIRE(array[i] == expected[i]);
    }
}

TEST_CASE("BubbleSort sorts integer array", "[bubble_sort]")
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    runBubbleSortTest(array, 7, expected);
}

TEST_CASE("BubbleSort sorts double array", "[bubble_sort]")
{
    double array[] = {64.1, 34.2, 25.3, 12.4, 22.5, 11.6, 90.7};
    double expected[] = {11.6, 12.4, 22.5, 25.3, 34.2, 64.1, 90.7};
    runBubbleSortTest(array, 7, expected);
}

TEST_CASE("BubbleSort handles empty array", "[bubble_sort]")
{
    int *array = nullptr;
    int *expected = nullptr;
    runBubbleSortTest(array, 0, expected);
}

TEST_CASE("BubbleSort handles single-element array", "[bubble_sort]")
{
    int array[] = {42};
    int expected[] = {42};
    runBubbleSortTest(array, 1, expected);
}

TEST_CASE("BubbleSort handles already sorted array", "[bubble_sort]")
{
    int array[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    runBubbleSortTest(array, 5, expected);
}

TEST_CASE("BubbleSort handles reverse sorted array", "[bubble_sort]")
{
    int array[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    runBubbleSortTest(array, 5, expected);
}

TEST_CASE("BubbleSort handles duplicates", "[bubble_sort]")
{
    int array[] = {3, 1, 2, 3, 2};
    int expected[] = {1, 2, 2, 3, 3};
    runBubbleSortTest(array, 5, expected);
}
