#include "BinaryTree.cpp"
#include <iostream>

int main()
{
    BinaryTree<int> tree;
    tree.insert();
    tree.print();
    std::cout<<"The size of the tree is: "<<tree.size()<<'\n';
    std::cout<<"The height of the tree is "<<tree.height()<<'\n';
    return 0;
}
