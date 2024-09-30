#ifndef SORT_H
#define SORT_H

class Sort
{
protected:
    int size;
    int *array;

public:
    Sort();
    Sort(int *arr, int s);
    void swap(int &a, int &b);
    int getSize() const;
    int &getItemById(int index) const;

    virtual void sort() = 0;

    void printArray() const;
};

#endif