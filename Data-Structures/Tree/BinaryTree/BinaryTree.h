#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"


template <typename T>
class BinaryTree
{
private:
    Node<T>* root;
protected:
    Node<T>* newNode(T d);
public:
    BinaryTree();
    ~BinaryTree();
//    void insert();

};



#endif