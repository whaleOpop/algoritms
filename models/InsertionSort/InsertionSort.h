#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../Sort/Sort.h"

template<typename T>
class InsertionSort : public Sort<T> {
public:
    InsertionSort(T* arr, int s);
    void sort() override;
};


#endif