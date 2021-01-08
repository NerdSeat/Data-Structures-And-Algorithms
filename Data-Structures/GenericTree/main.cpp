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
    //5 3 7 3 2 2 4 6 2 1 9 2 10 12 1 8 0 0 0 0 0 0
    int k = 2;
    Tree<int> tree;
    //std::unique_ptr<Node<int>> root = insert();
    tree.insert();
    tree.print();
    std::cout<<"The tree has "<<tree.countNodes()<<" nodes\n";
    std::cout<<"And the height of the tree is "<<tree.height()<<"\n";

    std::cout<<"all the nodes at depth "<<k<<" are\n";
    tree.printNodesAtLevel(k);

    std::cout<<"The number of leaf nodes is "<<tree.countLeafNodes()<<"\n";

    tree.preOrderTraversal();
    tree.postOrderTraversal();
    return 0;

}
