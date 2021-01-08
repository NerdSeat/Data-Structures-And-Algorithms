#ifndef NODE_H
#define NODE_H
#include<vector>
#include<memory>

template<typename T>
struct Node
{
    T data;
    std::vector<Node<T>*> children;
    Node(T d){this->data = d;}

};

#endif

