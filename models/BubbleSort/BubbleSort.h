#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../Sort/Sort.h"

class BubbleSort : public Sort {
public:
    BubbleSort(int* arr, int s);
    void sort() override;
};

#endif