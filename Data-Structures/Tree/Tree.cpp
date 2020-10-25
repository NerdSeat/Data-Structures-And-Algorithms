#include "Tree.h"

template<class T>
Tree<T>::Tree()
{
    root = nullptr;
    size = 0;
}
template<class T>
Tree<T>::Tree(T d)
{
    root->data = d;
    root->left = nullptr;
    root->right = nullptr;
    size = 1;
}
template<class T>
void Tree<T>::insert(T val)
{
    privateInsert(root,val);
}
template<class T>
void Tree<T>::privateInsert(Node<T>* node,T val)
{
    if(root==nullptr)
    {
        root = newNode(val);
        return;
    }
    else if(val<node->data)
    {
        if(node->left!=nullptr)
            privateInsert(node->left,val);
        else
        {
            node->left = newNode(val);
        }
        
    }
    else if(val>node->data)
    {
        if(node->right!=nullptr)
            privateInsert(node->right,val);
        else
        {
            node->right = newNode(val);
        }
        
    }
    else 
        std::cout<<"The node "<<val<<" has already been added\n";
}
template<class T>
Node<T>* Tree<T>::newNode(T d)
{
    Node<T>* node = new Node<T>();
    node->data = d;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
template<class T>
void Tree<T>::display()const
{
    privateDisplay(root);
}
template<class T>
void Tree<T>::privateDisplay(Node<T>* node)const
{
    if(root==nullptr)
    {
        std::cout<<"The Tree is empty\n";
        return;
    }
    if(node->left!=nullptr)
        privateDisplay(node->left);

    std::cout<<node->data<<"\t";

    if(node->right!=nullptr)
        privateDisplay(node->right);
    
}
template<class T>
bool Tree<T>::empty()const
{
    return (root->left==nullptr and root->right==nullptr);
}
template<class T>
Tree<T>::~Tree()
{

}
template<class T>
Node<T>* Tree<T>::returnNode(T d)const
{
    return privateReturnNode(root,d);
}
template<class T>
Node<T>* Tree<T>::privateReturnNode(Node<T>* node, T val)const
{
    if(node!=nullptr)
    {
        if(val==node->data)
            return node;
        else
        {
            if(val<node->data)
            {
                return privateReturnNode(node->left,val);
            }
            else
            {
                return privateReturnNode(node->right,val);
            }
        }      
    }
    else
        return nullptr;
}
template<class T>
void Tree<T>::displayChildren(T d)const
{
    Node<T>* parent = returnNode(d);
    if(parent==nullptr)
    {
        std::cout<<"The node "<<d<<" is not in the tree\n";
        return;
    }
    std::cout<<"The parent node is "<<d<<"\n";
    if(parent->left==nullptr && parent->right==nullptr)
    {
        std::cout<<d<<" is a leaf node\n";
        return;
    }
    if(parent->left!=nullptr)
        std::cout<<"left child: "<<parent->left->data<<"\n";
    else 
        std::cout<<d<<" has no left child\n";
    if(parent->right!=nullptr)
        std::cout<<"right child: "<<parent->right->data<<"\n";
    else 
        std::cout<<d<<" has no right child\n";
}
template<class T>
T Tree<T>::FindSmallestNode()const
{
    return privateFindSmallestNode(root);
}
template<class T>
T Tree<T>::privateFindSmallestNode(Node<T>* node)const
{
    if(root==nullptr)
    {
        std::cout<<"The tree is empty\n";
        return -1000;
    }
    if(node->left!=nullptr)
        return privateFindSmallestNode(node->left);
    else
        return node->data;
}