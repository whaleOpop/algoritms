#ifndef TWO_PHASE_MERGE_SORT_H
#define TWO_PHASE_MERGE_SORT_H

#include "../Sort/Sort.h"

template <typename T>
class TwoPhaseMergeSort : public Sort<T>
{
private:
    void merge(T *arr, int left, int mid, int right);
    void mergeSort(T *arr, int left, int right);

public:
    TwoPhaseMergeSort(T *arr, int size);
    void sort() override;
};

#endif
