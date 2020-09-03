#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include<iostream>
template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(T data);
    unsigned int size;
public:
    // Default ctor
    LinkedList();
    //ctor initialised with atleast one value
    ~LinkedList();
    void addToHead(T data);
    void addToTail(T data);
    void removeNode(T data);
    void sortList();
    bool isInList(T data);
    bool isEmpty();
    void printList();
  T* begin()const;
  T* end()const;

  unsigned int getSize();
};
#endif
