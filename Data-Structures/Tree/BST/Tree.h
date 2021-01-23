#pragma once
#include "Node.h"
#include<iostream>
template <typename T>
class Tree
{
private:
    Node<T>* root;
    Node<T>* newNode(T d);
    void privateInsert(Node<T>*, T);
    void privatePrint(Node<T>*)const;
    T privateSmallest(Node<T>*)const;
public:
    Tree(T d);
    Tree();
    ~Tree();
    void insert(T d);
    void print()const;
    T smallest()const;
    
};
