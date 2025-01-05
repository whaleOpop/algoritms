#ifndef SINGLE_PHASE_MERGE_SORT_H
#define SINGLE_PHASE_MERGE_SORT_H

#include "../Sort/Sort.h"

template <typename T>
class SinglePhaseMergeSort : public Sort<T>
{
private:

    void merge(T* start, T* mid, T* end);

   
    void mergeSort(T* start, T* end);

public:
    SinglePhaseMergeSort(T *arr, int size);
    void sort() override;
};

#endif
