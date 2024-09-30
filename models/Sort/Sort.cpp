#include "Sort.h"
#include "iostream"

Sort::Sort() : size(0), array(nullptr) {}

Sort::Sort(int *arr, int s) : size(s), array(arr) {}

int Sort::getSize() const
{
    return size;
}

void Sort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int &Sort::getItemById(int index) const
{
    return array[index];
}

void Sort::printArray() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}