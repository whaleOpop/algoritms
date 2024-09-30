#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../Sort/Sort.h"

class SelectionSort : public Sort {
public:
    SelectionSort(int* arr, int s);
    void sort() override;
};

#endif 