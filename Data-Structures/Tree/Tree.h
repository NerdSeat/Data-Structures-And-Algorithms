#pragma once
#include "Node.h"
#include<iostream>

template<class T>
class Tree
{
private:
    Node<T>* root;
    std::size_t size;
    Node<T>* newNode(T d);
    void privateInsert(Node<T>* n,T val);
    void privateDisplay(Node<T>* node)const;
    Node<T>* privateReturnNode(Node<T>* node,T val)const;
public:
    Tree();
    Tree(T data);
    ~Tree();
    void display()const;
    void insert(T val);
    void remove(T val);
    bool search(T val)const;
    bool empty()const;
    Node<T>* returnNode(T d)const;
    void displayChildren(T d)const;
};