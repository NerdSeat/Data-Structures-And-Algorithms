#ifndef GenericTree_H
#define GenericTree_H
#include "Node.h"
#include<memory>
#include<queue>
#include<iostream>
template <typename T>
class GenericTree
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
    void privatePostOrderTraversal(Node<T>*)const;
    void deleteGenericTree(Node<T>*);

public:
    GenericTree();
    ~GenericTree();
    void insert();
    void print()const;
    int countNodes()const;
    int height()const;
    void printNodesAtLevel(int k)const;
    int countLeafNodes()const;
    void preOrderTraversal()const;
    void postOrderTraversal()const;
};
#endif