#include "Tree.cpp"
#include <iostream>
#include "Node.h"
#include <memory>

/*template<typename T>
std::unique_ptr<Node<T>> newNode(T d)
{
    std::unique_ptr<Node<T>> node = std::make_unique<Node<T>>(d);
    return node;
}
template<typename T>
void print(const std::unique_ptr<Node<T>>& root)
{
    if(root==nullptr)
        return;
    //print the parent node
    std::cout<<root->data<<": ";
    //print all the child nodes under the parent node
    for(int i =0; i<root->children.size();++i)
        std::cout<<root->children[i]->data<<" ";
    std::cout<<std::endl;

    for(int i = 0; i<root->children.size(); ++i)
        print(root->children.at(i));
    
}

template<typename T>
std::unique_ptr<Node<T>> insert()
{
    
    T child;
    std::cout<<"Enter node: ";
    std::cin>>child;
    std::unique_ptr<Node<T>> root = newNode(child);
    std::size_t nodes;
    std::cout<<"How many nodes does "<<child<<" have?";
    std::cin>>nodes;
    for(std::size_t i = 0; i < nodes; ++i)
    {
        std::unique_ptr<Node<T>> childNode = insert();
        root->children.push_back(childNode);
    }
    return root;
}
*/
int main()
{
    Tree<int> tree;
    //std::unique_ptr<Node<int>> root = insert();
    tree.insert();
    tree.print();
    std::cout<<"The tree has "<<tree.countNodes()<<" nodes\n";

    return 0;

}