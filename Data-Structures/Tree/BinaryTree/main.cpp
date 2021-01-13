#include "BinaryTree.cpp"
#include <iostream>

int main()
{
    BinaryTree<int> tree;
    tree.insert();
    tree.print();
    std::cout<<"The size of the tree is: "<<tree.size()<<'\n';
    std::cout<<"The height of the tree is "<<tree.height()<<'\n';
    int val1 = 31,val2 = 53;
    if(tree.find(val1))
        std::cout<<val1<<" is in the tree\n";
    else
        std::cout<<val1<<" is not in the tree\n";
    if(tree.find(val2))
        std::cout<<val2<<" is in the tree\n";
    else
        std::cout<<val2<<" is not in the tree\n";
    return 0;
}
