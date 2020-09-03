#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include<iostream>
#include<cassert>
template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(const T& d);
    std::size_t size;
public:
    Queue();
    void pop();
    void push(const T&  data);
    T front()const;
    bool empty()const;
    ~Queue();
};
#endif