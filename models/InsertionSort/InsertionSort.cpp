#include "InsertionSort.h"

template<typename T>
InsertionSort<T>::InsertionSort(T* arr, int s) : Sort<T>(arr, s) {}

template<typename T>
void InsertionSort<T>::sort() {
    for (int i = 1; i < this->size; i++) {
        T key = this->array[i];
        int j = i - 1;
        while (j >= 0 && this->array[j] > key) {
            this->array[j + 1] = this->array[j];
            j--;
        }
        this->array[j + 1] = key;
    }
}

template class InsertionSort<int>;
template class InsertionSort<double>;