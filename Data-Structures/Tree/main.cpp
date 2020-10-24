#include <vector>
#include "Tree.cpp"

int main()
{
    std::vector<int> vals = {50,76,21,4,32,64,15,52,14,100,2,3,70,87,80};
    Tree<int> tree;
    std::cout<<"printing the tree before adding data\n";
    tree.display();
    std::cout<<std::endl;
    for(auto x: vals)
        tree.insert(x);
    std::cout<<"printing the tree after adding data\n";
    tree.display();
    std::cout<<std::endl;
    tree.displayChildren(100);
    tree.displayChildren(5);
}