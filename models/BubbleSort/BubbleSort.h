#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../Sort/Sort.h"

template <typename T>
class BubbleSort : public Sort<T>
{
public:
    BubbleSort(T *arr, int s);
    void sort() override;
};

#endif