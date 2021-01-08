#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include<memory>
#include<queue>
#include<iostream>
template <typename T>
class Tree
{
private:
    Node<T>* root;
    Node<T>* newNode(T d) const;
    void privatePrint(Node<T>*)const;
    void levelOrderPrint()const;
    int privateCountNodes(Node<T>*) const;

public:
    Tree();
    ~Tree();
    void insert();
    void print()const;
    int countNodes()const;
};
#endif