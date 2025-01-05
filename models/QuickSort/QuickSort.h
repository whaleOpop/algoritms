#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../Sort/Sort.h"

template <typename T>
class QuickSort : public Sort<T>
{
public:
    QuickSort(T *arr, int s);
    void sort() override;

private:
    void quickSort(int low, int high);
    int partition(int low, int high);
};

#endif
