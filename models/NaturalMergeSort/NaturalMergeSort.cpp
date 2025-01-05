#include "NaturalMergeSort.h"

template <typename T>
void NaturalSort<T>::sort()
{
    // Run detection
    int runs = detectRuns();

    if (runs == 1)
        return; // Already sorted

    // Perform QuickSort on large subarrays
    quickSort(0, this->size - 1);

    // Insertion sort small subarrays
    insertionSort(0, runs - 1);
}

template <typename T>
int NaturalSort<T>::detectRuns() const
{
    int runs = 1;
    bool isRun = true;

    for (int i = 0; i < this->size - 1; ++i)
    {
        if (this->array[i] > this->array[i + 1])
        {
            isRun = false;
            runs++;
        }
    }

    return runs;
}

template <typename T>
void NaturalSort<T>::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

template <typename T>
T NaturalSort<T>::partition(int low, int high)
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
    return this->array[i + 1];
}

template <typename T>
void NaturalSort<T>::insertionSort(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = this->array[i];
        int j = i - 1;

        while (j >= left && this->array[j] > key)
        {
            this->swap(this->array[j], this->array[j + 1]);
            j--;
        }

        this->array[j + 1] = key;
    }
}