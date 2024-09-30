#ifndef IMPROVE_BUBBLE_SORT_H
#define IMPROVE_BUBBLE_SORT_H

#include "../Sort/Sort.h"

template<typename T>
class ImprovedBubbleSort : public Sort<T> {
public:
    ImprovedBubbleSort(T* arr, int s);
    void sort() override;
};

#endif