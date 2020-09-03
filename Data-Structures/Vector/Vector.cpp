#include "Vector.h"

template <typename T>
Vector<T>::Vector(std::size_t c)
{
    count = c;
    data = new T[cap];
}
template <typename T>
Vector<T>::Vector()
{
    count =0;
    data = new T[cap];
}
template <typename T>
Vector<T>::Vector(const Vector &v)
{
    cap = v.cap;
    count = v.count;
    data = new T[cap];
    std::copy(v.data, v.data + cap, data);
}
template <typename T>
Vector<T> &Vector<T>::operator=(Vector v)
{
    std::swap(*this, v);
    return *this;
}
template <typename T>
std::size_t Vector<T>::size() const
{
    return this->count;
}
template <typename T>
std::size_t Vector<T>::capacity() const
{
    return this->cap;
}
template <typename T>
void Vector<T>::push_back(T d)
{
    if (count > cap - 1)
        copy();
    data[count] = d;
    count++;
}
template <typename T>
void Vector<T>::copy()
{
    cap *=2;
    T *new_data = new T[cap];
    std::copy(data, data + cap, new_data);
    delete[] data;
    data = new_data;
}
template<typename T>
T* Vector<T>::begin()
{
    return data;
}
template<typename T>
T* Vector<T>::end()
{
    return data+count;
}
template <typename T>
T Vector<T>::operator[](unsigned i)
{
    return *(data + i);
}
template<typename T>
bool Vector<T>::empty()const
{
    return count==0;
}
template<typename T>
Vector<T>::~Vector()
{
    delete[] data;
}
