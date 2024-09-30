#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../Sort/Sort.h"

class InsertionSort : public Sort {
public:
    InsertionSort(int* arr, int s);
    void sort() override;
};

#endif