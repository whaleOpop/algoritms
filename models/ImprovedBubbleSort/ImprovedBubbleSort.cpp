
#include "ImprovedBubbleSort.h"

ImprovedBubbleSort::ImprovedBubbleSort(int* arr, int s) : Sort(arr, s) {}

void ImprovedBubbleSort::sort() {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);  
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}