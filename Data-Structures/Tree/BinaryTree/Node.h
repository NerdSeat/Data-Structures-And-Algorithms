#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node(T d){this->data = d;}
    ~Node(){ delete left; delete right;}
};

#endif
