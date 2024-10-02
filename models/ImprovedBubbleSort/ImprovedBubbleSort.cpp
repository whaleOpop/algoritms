#include "ImprovedBubbleSort.h"

template <typename T>
ImprovedBubbleSort<T>::ImprovedBubbleSort(T *arr, int s) : Sort<T>(arr, s) {}

template <typename T>
void ImprovedBubbleSort<T>::sort()
{
    bool swapped;
    for (int i = 0; i < this->size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < this->size - i - 1; j++)
        {
            if (this->array[j] > this->array[j + 1])
            {
                this->swap(this->array[j], this->array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

template class ImprovedBubbleSort<int>;
template class ImprovedBubbleSort<double>;