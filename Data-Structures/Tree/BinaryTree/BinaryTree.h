#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <iostream>
#include <queue>
#include <stack>
template <typename T>
class BinaryTree
{
private:
    Node<T>* root;
protected:
    Node<T>* newNode(T d);
    Node<T>* privateInsert();
    void iterativeInsert();
    void privatePrint(Node<T>*)const;
    void levelOrderPrint()const;
    unsigned int privateCountNodes(Node<T>*)const;
    void privateInorderTraversal(Node<T>*)const;
    void privateInorderTraversalIterative()const;

public:
    BinaryTree();
    ~BinaryTree();
    void insert();
    void print()const;
    unsigned int size()const;
    void inorderTraversal()const;

};

#endif
