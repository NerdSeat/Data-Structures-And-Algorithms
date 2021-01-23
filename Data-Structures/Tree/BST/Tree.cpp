#include "Tree.h"

template<typename T>
Tree<T>::Tree()
{
    root = nullptr;
}
template<typename T>
Tree<T>::Tree(T d)
{
    this->root = newNode(d);
}
template<typename T>
Node<T>* Tree<T>::newNode(T d)
{
    Node<T>* node = new Node<T>(d);

    return node;
}
template<typename T>
void Tree<T>::insert(T d)
{
    if(root == nullptr)
    {
        root = newNode(d);
        return;
    }
    privateInsert(root,d);
}
template<typename T>
void Tree<T>::privateInsert(Node<T>* node, T d)
{
    if(node == nullptr)
        return;
    if(d<node->data)
    {
        if(node->left==nullptr)
        {
            node->left = newNode(d);
            return;
        }
        privateInsert(node->left,d);
    }
    else if(d>node->data)
    {
         if(node->right==nullptr)
        {
            node->right = newNode(d);
            return;
        }
        privateInsert(node->right,d);
    }
    else
        std::cout<<"Node is already in the tree\n";

}
template<typename T>
void Tree<T>::print()const
{
    privatePrint(root);
    std::cout<<'\n';
}
template<typename T>
void Tree<T>::privatePrint(Node<T>* node)const
{
    if(node==nullptr)
        return;
    privatePrint(node->left);
    std::cout<<node->data<<"\t";
    privatePrint(node->right);
}

template<typename T>
T Tree<T>::smallest()const
{
    return privateSmallest(root);
}
template<typename T>
T Tree<T>::privateSmallest(Node<T>* node)const
{
    if(node->left==nullptr)
        return node->data;
    return privateSmallest(node->left);
}
template<typename T>
bool Tree<T>::find(T d)const
{
    return privateFind(root,d);
}
template<typename T>
bool Tree<T>::privateFind(Node<T>* node, T d)const
{
    if(node==nullptr)
        return false;
    if(node->data == d)
        return true;
    if(d < node->data)
        return privateFind(node->left,d);
    else
        return privateFind(node->right,d);
    
}
template<typename T>
void Tree<T>::invert()
{
    privateInvert(root);
}
template<typename T>
void Tree<T>::privateInvert(Node<T>* node)
{
    if(node==nullptr)
        return;
    Node<T>* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    privateInvert(node->left);
    privateInvert(node->right);
}
template<typename T>
Tree<T>::~Tree()
{
    delete root;
}