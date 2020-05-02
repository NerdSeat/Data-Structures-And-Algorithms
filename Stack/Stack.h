#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>
template<class T>
class Stack
{
private:
    Node<T> * top;
    int size;
public:
    Stack();
    ~Stack();
    void push(const T &d);
    T pop();
    int get_size()const;
    bool isEmpty()const;
    void print()const;
};
#endif
