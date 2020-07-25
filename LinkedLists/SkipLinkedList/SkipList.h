#ifndef SKIPLIST_H
#define SKIPLIST_H
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

const int MAX_LEVEL = 6;
template <typename T>
class SkipList
{
private:
    typedef Node<T>* nodePtr;
    nodePtr* root[MAX_LEVEL];
    nodePtr* createNode(T data);
    int chooseLevel();

public:
    SkipList();
    ~SkipList();
    void insert(T data);
    bool search(T data);
    
};

#endif