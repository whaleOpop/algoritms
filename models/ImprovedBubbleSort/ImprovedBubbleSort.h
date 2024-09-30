#ifndef IMPROVE_BUBBLE_SORT_H
#define IMPROVE_BUBBLE_SORT_H

#include "../Sort/Sort.h"

class ImprovedBubbleSort : public Sort {
public:
    ImprovedBubbleSort(int* arr, int s);
    void sort() override;
};

#endif