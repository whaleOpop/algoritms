#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "../Sort/Sort.h"

template <typename T>
class BinaryInsertionSort : public Sort<T>
{
public:
    BinaryInsertionSort(T *arr, int s) : Sort<T>(arr, s) {}
    void sort() override;
};

#endif 