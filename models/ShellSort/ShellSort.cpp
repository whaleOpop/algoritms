#include "ShellSort.h"

template <typename T>
ShellSort<T>::ShellSort(T *arr, int s) : Sort<T>(arr, s) {}

template <typename T>
void ShellSort<T>::sort()
{
    for (int gap = this->size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < this->size; ++i)
        {
            T temp = this->array[i];
            int j;
            for (j = i; j >= gap && this->array[j - gap] > temp; j -= gap)
            {
                this->array[j] = this->array[j - gap];
            }
            this->array[j] = temp;
        }
    }
}


template class ShellSort<int>;
template class ShellSort<double>;
