#include "array.h"
#include <string>

template<class T>
array<T>::array(int cap)
:capacity(cap){
    arr = new T[capacity];
    size = 0;
}

template<class T>
void array<T>::insert(T data)
{
    if(size==capacity)
    {
        capacity*=2;
        T *new_arr = new T[capacity];
        for(int i=0;i<size;i++)
        {
            new_arr[i]=arr[i];
        }
        delete[] arr;
        arr=new_arr;
    }
    arr[size]=data;
    size++;
}
template<class T>
void array<T>::remove(T data)
{
    int tempIndex;
    for(int i=0;i<=size;i++)
    {
        if(arr[i]==data)
        {
            tempIndex = i;
            break;
        }
    }
    while(tempIndex<size)
    {
        arr[tempIndex]=arr[tempIndex+1];
        tempIndex++;
    }
    //delete arr[size-1];
    size--;
}
template<class T>
void array<T>::print()const
{
    std::cout<<"[";
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"] \n";
}
template<class T>
bool array<T>::isEmpty()const
{return size==0;}
template<class T>
int array<T>::getSize()const
{return size;}
template<class T>
array<T>::~array()
{delete[] arr;}