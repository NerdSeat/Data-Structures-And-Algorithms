#pragma once
#include "Node.h"

template<class T>
class LinkedList
{
    public:
        LinkedList();
        void insertHead(T d);
        void insertTail(T d);
        void remove(T d);
        void sort();
        void printList();
        int getSize()const;
    private:
        Node<T> *head;
        int size;
};
