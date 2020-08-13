#ifndef STACK_H
#define STACK_H
#include<iostream>
#include "Node.h"


template <typename T>
class Stack
{
private:
    Node<T>* head;
    unsigned int count;
    Node<T>* createNode(T );
public:
    Stack();
    T pop();
    T top()const;
    void push(T data);
    unsigned int size()const;

};

#endif