#ifndef EXCHANGE_SORT_H
#define EXCHANGE_SORT_H

#include "../Sort/Sort.h"

template<typename T>
class ExchangeSort : public Sort<T> {
public:
    ExchangeSort(T* arr, int s);
    void sort() override;
};


#endif 
