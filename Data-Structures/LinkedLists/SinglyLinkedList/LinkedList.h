#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include<cassert>
template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  Node<T> *createNode(T data);
  unsigned int size;

protected:
  Node<T>* mergeSort(Node<T>*);
  Node<T>* merge(Node<T>*,Node<T>*);
  


public:
  // Default ctor
  LinkedList();
  //ctor initialised with n elements, all equal to d
  LinkedList(unsigned int n, T d);
  ~LinkedList();
  void push_front(T data);
  void insert_at(T data, int n);
  void push_back(T data);
  void remove(T data);
  void reverse();
  void sort();
  bool find(T data);
  bool empty();
  void print();
  void erase();
  Node<T> *getHead() const;
  Node<T> *getTail() const;
  unsigned int getSize() const;
};
#endif
