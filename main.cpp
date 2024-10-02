#include "Models/SelectionSort/SelectionSort.h"
#include <iostream>

int main()
{

    double doubleArr[] = {64.5, 34.1, 25.2, 12.8, 22.0, 11.5, 90.3};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    SelectionSort<double> selectionSort(doubleArr, doubleSize);
    selectionSort.sort();
    std::cout << "Sorted array using Selection Sort (double): ";
    selectionSort.printArray();

    return 0;
}
