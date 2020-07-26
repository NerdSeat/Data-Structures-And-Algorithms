#ifndef SKIPLIST_H
#define SKIPLIST_H
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include<ctime>
const float probability = 0.5;//node level probability
#define MAX_LEVEL 6
template <typename T>
class SkipList
{
private:
    typedef Node<T>* nodePtr;
    nodePtr* root[MAX_LEVEL];
    nodePtr* createNode(T data);
    int chooseLevel();
    inline float frand();
public:
    SkipList();
    ~SkipList();
    void insert(T data);
    bool search(T data);
    void remove(T data);
    
};

#endif