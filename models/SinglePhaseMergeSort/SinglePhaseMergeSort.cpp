#include "SinglePhaseMergeSort.h"

template <typename T>
SinglePhaseMergeSort<T>::SinglePhaseMergeSort(T *arr, int size) : Sort<T>(arr, size) {}

template <typename T>
void SinglePhaseMergeSort<T>::merge(T* start, T* mid, T* end)
{
    int leftSize = mid - start;
    int rightSize = end - mid;
    
    T* left = new T[leftSize];
    T* right = new T[rightSize];
    
    for (int i = 0; i < leftSize; ++i)
        left[i] = start[i];
    for (int i = 0; i < rightSize; ++i)
        right[i] = mid[i];

    int i = 0, j = 0, k = 0;
    
    // Merging process
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            start[k++] = left[i++];
        }
        else
        {
            start[k++] = right[j++];
        }
    }

    while (i < leftSize)
    {
        start[k++] = left[i++];
    }

    while (j < rightSize)
    {
        start[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

template <typename T>
void SinglePhaseMergeSort<T>::mergeSort(T* start, T* end)
{
    if (end - start <= 1)
        return;

    T* mid = start + (end - start) / 2;

    mergeSort(start, mid);
    mergeSort(mid, end);

    merge(start, mid, end);
}

template <typename T>
void SinglePhaseMergeSort<T>::sort()
{
    mergeSort(this->array, this->array + this->size);
}

template class SinglePhaseMergeSort<int>;
template class SinglePhaseMergeSort<double>;
