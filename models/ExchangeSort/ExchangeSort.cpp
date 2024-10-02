#include "ExchangeSort.h"

template <typename T>
ExchangeSort<T>::ExchangeSort(T *arr, int s) : Sort<T>(arr, s) {}

template <typename T>
void ExchangeSort<T>::sort()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        for (int j = i + 1; j < this->size; j++)
        {
            if (this->array[j] < this->array[i])
            {
                this->swap(this->array[i], this->array[j]);
            }
        }
    }
}

template class ExchangeSort<int>;
template class ExchangeSort<double>;
