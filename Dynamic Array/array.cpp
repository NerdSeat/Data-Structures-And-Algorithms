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
    int tempIndex = -1;
    for(int i=0;i<=size;i++)
    {
        if(arr[i]==data)
        {
            tempIndex = i;
            break;
        }
    }
    if(tempIndex==-1)
    {
        std::cout<<data<<" is not in the list"<<std::endl;
        return;
    }
    while(tempIndex<size)
    {
        arr[tempIndex]=arr[tempIndex+1];
        tempIndex++;
    }
    size--;
    std::cout<<data<<" has been removed from the list"<<std::endl;

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
void array<T>::sort()const
{
    T current; int j;
    for(int i=1;i<size;i++)
    {
        current=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>current)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=current;
    }
}
template<class T>
bool array<T>::isEmpty()const
{return size==0;}
template<class T>
int array<T>::getSize()const
{return size;}
template<class T>
inline array<T>::~array()
{delete[] arr;}