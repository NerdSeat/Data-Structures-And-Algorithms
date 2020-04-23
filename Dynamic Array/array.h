#pragma once
#include <iostream>
#include <cassert>
#include <string>

template<class T>
class array
{
public:
    array(int cap);
    void insert(T data);
    void remove(T data);
    bool isEmpty()const;
    void print()const;
    int getSize()const;
    void sort()const;
    ~array();
private:
    int size;
    int capacity;
    T *arr;
};
