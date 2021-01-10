//#include "BinaryTree.h"
#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node(T d){this->data = d;}
    ~Node(){ delete left; delete right;}
};

template<typename T>
void print(Node<T>* r)
{
    if(r == nullptr)
        return;

    std::cout<<r->data<<":";
    if(r->left!=nullptr)
        std::cout<<"L "<<r->left->data<<" ";
    if(r->right!=nullptr)
        std::cout<<"R "<<r->right->data<<" ";
    std::cout<<"\n";
    print(r->left);
    print(r->right);

}

int main()
{
    Node<int>* root = new Node<int>(5);
    Node<int>* left = new Node<int>(3);
    Node<int>* right = new Node<int>(7);
    root->left = left;
    root->right = right;
    print(root);

    delete root;
    return 0;
}