#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class OrderedLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(const T& data);
    unsigned int size;

public:
    OrderedLinkedList();
    void insert(const T& data);
    void remove(const T& data);
    bool isEmpty()const;
    bool search(const T& data)const;
    void print()const;
    unsigned int getSize()const;
    ~OrderedLinkedList();


};
#endif