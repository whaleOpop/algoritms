#include "Sort.h"
#include "iostream"

template <typename T>
Sort<T>::Sort() : size(0), array(nullptr) {}

template <typename T>
Sort<T>::Sort(T *arr, int s) : size(s), array(arr) {}

template <typename T>
int Sort<T>::getSize() const
{
    return size;
}

template <typename T>
T &Sort<T>::getItemById(int index) const
{
    return array[index];
}

template <typename T>
void Sort<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Sort<T>::printArray() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template class Sort<int>;
template class Sort<double>;