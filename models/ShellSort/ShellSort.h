#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "../Sort/Sort.h"

template <typename T>
class ShellSort : public Sort<T>
{
public:
    ShellSort(T *arr, int s);
    void sort() override;
};

#endif
