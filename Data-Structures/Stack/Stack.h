#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T>* head;
    Node<T>* createNode(T);
    uint16_t count;

public:
    Stack();
    auto pop();
    void push(const T &data);
    auto top() const;
    bool empty() const;
};

#endif