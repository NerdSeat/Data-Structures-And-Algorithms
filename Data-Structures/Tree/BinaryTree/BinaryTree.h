#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <iostream>
#include <queue>
#include<utility>
#include <stack>
#include<vector>
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
    void privatePreorderTraversal(Node<T>*)const;
    void privatePreorderTraversalIterative()const;
    void privatePostOrderTraversal(Node<T>*)const;
    int privateHeight(Node<T>*)const;
    bool privateFind(Node<T>*, T)const;
    T privateMin(Node<T>*)const;
    T privateMax(Node<T>*)const;
    int privateCountLeafNodes(Node<T>*)const;
    std::pair<int,int> privateDiameter(Node<T>*)const;
    bool privatePath(Node<T>* n, T d,std::vector<T>&v)const;
public:
    BinaryTree();
    ~BinaryTree();
    void insert();
    void print()const;
    unsigned int size()const;
    void inorderTraversal()const;
    void preorderTraversal()const;
    void postOrderTraversal()const;
    int height()const;
    bool find(T d)const;
    T min()const;
    T max()const;
    int countLeafNodes()const;
    int diameter()const;
    void path(T d)const;

};

#endif
