#include "TwoPhaseMergeSort.h"

template <typename T>
TwoPhaseMergeSort<T>::TwoPhaseMergeSort(T *arr, int size) : Sort<T>(arr, size) {}

template <typename T>
void TwoPhaseMergeSort<T>::merge(T *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T *leftArr = new T[n1];
    T *rightArr = new T[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void TwoPhaseMergeSort<T>::mergeSort(T *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
void TwoPhaseMergeSort<T>::sort()
{
    mergeSort(this->array, 0, this->size - 1);
}

template class TwoPhaseMergeSort<int>;
template class TwoPhaseMergeSort<double>;
