#pragma once

#include "Node.h"
#include<iostream>
#include<vector>
template <typename T>
class Tree
{
private:
    Node<T>* root;
    Node<T>* newNode(T d);
    void privateInsert(Node<T>*, T);
    void privatePrint(Node<T>*)const;
    T privateSmallest(Node<T>*)const;
    bool privateFind(Node<T>*,T)const;
    void privateInvert(Node<T>*);
    bool privateValid(Node<T>*)const;
    void privateRange(Node<T>*,T,T,std::vector<T>&)const;
public:
    Tree(T d);
    Tree();
    ~Tree();
    void insert(T d);
    void print()const;
    T smallest()const;
    bool find(T )const;
    void invert();
    bool valid()const;
    std::vector<T> range(T ,T)const;
    
};
