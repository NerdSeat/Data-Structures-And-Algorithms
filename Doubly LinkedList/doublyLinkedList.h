#pragma once
#include "Node.h"
#include <iostream>
#include <cassert>
template<class T>
class doublyLinkedList
{
public:
    doublyLinkedList();
    bool isEmpty()const;
    void insert(T d);
    void remove(T d);
    void sort()const;
    void print()const;
    void printReverse()const;
    T peek()const;
    ~doublyLinkedList();
private:
    Node<T>* newNode(T d)const;
    Node<T>* head;
    Node<T>* tail;
    int size;
};
