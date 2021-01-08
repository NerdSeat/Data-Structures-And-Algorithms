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
    int privateHeight(Node<T>*)const;
    void privatePrintNodesAt(Node<T>*,int)const;
    int privateCountLeafNodes(Node<T>*)const;
    void privatePreOrderTraversal(Node<T>*)const;

public:
    Tree();
    ~Tree();
    void insert();
    void print()const;
    int countNodes()const;
    int height()const;
    void printNodesAtLevel(int k)const;
    int countLeafNodes()const;
    void preOrderTraversal()const;
};
#endif