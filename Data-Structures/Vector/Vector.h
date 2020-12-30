#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <algorithm>
template <typename T>

class Vector
{
private:
    std::size_t count;   //number of items in the vector
    std::size_t cap = 2; //deafault capacity of the vector
    T *data;             //pointer to the first index in the array
    void copy();

public:
    Vector(std::size_t);
    Vector(std::size_t,T d);
    Vector();
    ~Vector();
    Vector(const Vector &v);
    Vector<T> &operator=(Vector);
    T* begin();
    T* end();
    T operator[](unsigned i);
    std::size_t size() const;
    std::size_t capacity() const;
    void push_back(T d);
    bool empty() const;

    template <typename _Tp>
    friend void swap(Vector<_Tp> &v1, Vector<_Tp> &v2);
};
#endif