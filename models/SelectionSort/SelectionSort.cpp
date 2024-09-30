#include "SelectionSort.h"

template<typename T>
SelectionSort<T>::SelectionSort(T* arr, int s) : Sort<T>(arr, s) {}

template<typename T>
void SelectionSort<T>::sort() {
    for (int i = 0; i < this->size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < this->size; j++) {
            if (this->array[j] < this->array[minIndex]) {
                minIndex = j;
            }
        }
        this->swap(this->array[i], this->array[minIndex]);  
    }
}

template class SelectionSort<int>;
template class SelectionSort<double>;