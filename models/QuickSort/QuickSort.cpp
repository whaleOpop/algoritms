#include "QuickSort.h"

template <typename T>
QuickSort<T>::QuickSort(T *arr, int s) : Sort<T>(arr, s) {}

template <typename T>
void QuickSort<T>::sort()
{
    quickSort(0, this->size - 1);
}

template <typename T>
void QuickSort<T>::quickSort(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(low, high);
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
}

template <typename T>
int QuickSort<T>::partition(int low, int high)
{
    T pivot = this->array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (this->array[j] <= pivot)
        {
            ++i;
            this->swap(this->array[i], this->array[j]);
        }
    }
    this->swap(this->array[i + 1], this->array[high]);
    return i + 1;
}

// Explicit template instantiation
template class QuickSort<int>;
template class QuickSort<double>;
