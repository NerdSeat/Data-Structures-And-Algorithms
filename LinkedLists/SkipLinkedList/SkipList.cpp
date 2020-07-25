#include "SkipList.h"
template<typename T>
SkipList<T>::SkipList()
{
    for(int i=0;i<MAX_LEVEL;i++)
    {
        root[i]=nullptr;
    }
}
template<typename T>
SkipList<T>::~SkipList()
{
}