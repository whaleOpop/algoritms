#include "BubbleSort.h"

BubbleSort::BubbleSort(int* arr, int s) : Sort(arr, s) {}

void BubbleSort::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);  
            }
        }
    }
}