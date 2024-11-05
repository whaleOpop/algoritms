#include "ShakerSort.h"

template <typename T>
void ShakerSort<T>::sort()
{
    bool swapped = true;
    int start = 0;
    int end = this->size - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (this->array[i] > this->array[i + 1])
            {
                this->swap(this->array[i], this->array[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (this->array[i] > this->array[i + 1])
            {
                this->swap(this->array[i], this->array[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

template class ShakerSort<int>;
template class ShakerSort<double>;
