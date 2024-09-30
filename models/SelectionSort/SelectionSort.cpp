#include "SelectionSort.h"

SelectionSort::SelectionSort(int* arr, int s) : Sort(arr, s) {}

void SelectionSort::sort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}