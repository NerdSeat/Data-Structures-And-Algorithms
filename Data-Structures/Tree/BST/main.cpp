#include "Tree.cpp"
#include <vector>
#include <string>
int main()
{
    Tree<int> tree;
    std::vector<int> vec{7,6,8,1,4,3,2,9,12,10,5};
    for(int v : vec)
        tree.insert(v);
    Tree<std::string> names;
    std::vector<std::string> vecNames{"Joseph","Nicholl","Lisa","Matt","Dave","Rob"};
    int num = -10;

    if(tree.find(num))
        std::cout<<num<<" is in the tree\n";
    else
        std::cout<<num<<" is not in the tree\n";

    tree.print();
    std::cout<<"The smallest node in the tree is -> "<<tree.smallest()<<'\n';

    std::string worker = "Thandi";
    for(auto n : vecNames)
        names.insert(n);
    
    if(names.find(worker))
        std::cout<<worker<<" Works here \n";
    else
        std::cout<<"There is no record of" <<worker<<" in this company\n";
    
    std::cout<<"The first name is always "<<names.smallest()<<'\n';
    names.print();
    names.invert();
    std::cout<<"The inverted tree is now \n";
    names.print();

    return 0;
}