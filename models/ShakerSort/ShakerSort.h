#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

#include "../Sort/Sort.h"

template <typename T>
class ShakerSort : public Sort<T>
{
public:
    ShakerSort(T *arr, int s) : Sort<T>(arr, s) {}
    void sort() override;
};

#endif 
