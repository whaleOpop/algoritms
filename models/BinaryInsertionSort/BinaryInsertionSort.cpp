#include "BinaryInsertionSort.h"

template <typename T>
int binarySearch(T *array, T item, int low, int high)
{
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == item)
            return mid + 1;
        else if (array[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

template <typename T>
void BinaryInsertionSort<T>::sort()
{
    for (int i = 1; i < this->size; ++i)
    {
        T selected = this->array[i];
        int j = i - 1;


        int loc = binarySearch(this->array, selected, 0, j);

        while (j >= loc)
        {
            this->array[j + 1] = this->array[j];
            --j;
        }
        this->array[j + 1] = selected;
    }
}

template class BinaryInsertionSort<int>;
template class BinaryInsertionSort<double>;
