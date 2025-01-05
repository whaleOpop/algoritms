// NaturalSort.h

#pragma once

#include "../Sort/Sort.h"

template <typename T>
class NaturalSort : public Sort<T>
{
public:
    NaturalSort(T *arr, int s) : Sort<T>(arr, s) {}

    void sort() override;

private:
    int detectRuns() const;
    void quickSort(int low, int high);
    T partition(int low, int high);
    void insertionSort(int left, int right);
};

// Specializations
template class NaturalSort<int>;
template class NaturalSort<double>;
