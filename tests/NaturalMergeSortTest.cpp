#include "../models/NaturalMergeSort/NaturalMergeSort.h"
#include "catch2/catch_all.hpp"
#include <cmath>

template<typename T>
void runNaturalSortTest(T* array, int size, T* expected) {
    if (array == nullptr || expected == nullptr) {
        REQUIRE(size == 0); // Проверка для пустого массива
        return;
    }

    NaturalSort<T> sorter(array, size);
    sorter.sort();

    for (int i = 0; i < size; ++i) {
        const double epsilon = 1e-6;
        REQUIRE(std::abs(array[i] - expected[i]) < epsilon * std::abs(expected[i]) || std::abs(array[i] - expected[i]) < epsilon);
    }
}

TEST_CASE("NaturalSort sorts integer array") {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    runNaturalSortTest(array, 7, expected);
}

TEST_CASE("NaturalSort sorts double array") {
    double array[] = {64.1, 34.2, 25.3, 12.4, 22.5, 11.6, 90.7};
    double expected[] = {11.6, 12.4, 22.5, 25.3, 34.2, 64.1, 90.7};
    runNaturalSortTest(array, 7, expected);
}

TEST_CASE("NaturalSort handles empty array") {
    int* array = nullptr;
    int* expected = nullptr;
    runNaturalSortTest(array, 0, expected);
}

TEST_CASE("NaturalSort handles single-element array") {
    int array[] = {42};
    int expected[] = {42};
    runNaturalSortTest(array, 1, expected);
}

TEST_CASE("NaturalSort handles already sorted array") {
    int array[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    runNaturalSortTest(array, 5, expected);
}

TEST_CASE("NaturalSort handles reverse sorted array") {
    int array[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    runNaturalSortTest(array, 5, expected);
}

TEST_CASE("NaturalSort handles duplicates") {
    int array[] = {3, 1, 2, 3, 2};
    int expected[] = {1, 2, 2, 3, 3};
    runNaturalSortTest(array, 5, expected);
}
