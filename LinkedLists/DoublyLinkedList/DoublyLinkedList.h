#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    unsigned int size;
    Node<T>* createNode(T data);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertHead(T data);
    void insertTail(T data);
    bool isEmpty();
    bool isInList(T data);
    void removeNode(T data);
    void printList();
    void reversePrint();
    unsigned int getSize();
};

#endif