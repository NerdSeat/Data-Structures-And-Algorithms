#include "BinaryTree.cpp"
#include <iostream>

int main()
{
    BinaryTree<int> tree;
    tree.insert();
    tree.print();
    std::cout<<"The size of the tree is: "<<tree.size();
    return 0;
}
