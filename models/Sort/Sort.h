#ifndef SORT_H
#define SORT_H

template <typename T>
class Sort
{
protected:
    int size;
    T *array;

public:
    Sort();
    Sort(T *arr, int s);

    int getSize() const;
    T &getItemById(int index) const;

    void swap(T &a, T &b);

    virtual void sort() = 0;

    void printArray() const;
};

#endif