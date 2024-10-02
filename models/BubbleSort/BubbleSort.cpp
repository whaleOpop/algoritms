#include "BubbleSort.h"

template <typename T>
BubbleSort<T>::BubbleSort(T *arr, int s) : Sort<T>(arr, s) {}

template <typename T>
void BubbleSort<T>::sort()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        for (int j = 0; j < this->size - i - 1; j++)
        {
            if (this->array[j] > this->array[j + 1])
            {
                this->swap(this->array[j], this->array[j + 1]);
            }
        }
    }
}

template class BubbleSort<int>;
template class BubbleSort<double>;