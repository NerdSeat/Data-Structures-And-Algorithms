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
void SkipList<T>::insert(T data)
{
    nodePtr *newNode= createNode(data);
}
template<typename T>
inline float SkipList<T>:: frand()
{
    return (float)(rand()/ RAND_MAX);
}
template<typename T>
int SkipList<T>::chooseLevel()
{
    static bool first = true;
    if(first){
        srand((unsigned)time(NULL));
        first =false;
    }
    int level = log(frand())/log(1.-probability);

    if(level<MAX_LEVEL)
        return level;
    return MAX_LEVEL;
}
template<typename T>
SkipList<T>::~SkipList()
{
}
