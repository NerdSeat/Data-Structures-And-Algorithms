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

    std::cout<<"The maximum node is "<<tree.max()<<'\n';
    std::cout<<"The minimum node is "<<tree.min()<<'\n';
    std::cout<<"The number of leaf nodes is "<<tree.countLeafNodes()<<'\n';
    std::cout<<"The diameter of the tree is "<<tree.diameter()<<'\n';

    tree.path(66);
    tree.path(6);
    tree.path(13);

    return 0;
}
/*
25 15 50 10 22 35 70 4 12 18 24 31 44 66 90 -1 5 6 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/