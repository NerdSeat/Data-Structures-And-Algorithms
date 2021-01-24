#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T d){this->data = d; this->left=nullptr; this->right=nullptr;}
    ~Node(){delete left; delete right;}
};
