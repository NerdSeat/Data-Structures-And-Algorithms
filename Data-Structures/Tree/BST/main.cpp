#include "Tree.cpp"
#include <vector>
int main()
{
    Tree<int> tree;
    std::vector<int> vec{7,6,8,1,4,3,2,9,12,10,5};
    for(int v : vec)
        tree.insert(v);
    
    tree.print();
    std::cout<<"The smallest node in the tree is -> "<<tree.smallest()<<'\n';
    return 0;
}