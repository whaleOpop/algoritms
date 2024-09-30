#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../Sort/Sort.h"

template<typename T>
class SelectionSort : public Sort<T> {
public:
    SelectionSort(T* arr, int s);
    void sort() override;
};


#endif 