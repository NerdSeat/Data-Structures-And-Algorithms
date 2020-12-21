#include<iostream>
#include<vector>

void print(std::vector<int> vec)
{
    if(vec.size()==0)
        return;
    std::cout<<vec[vec.size()-1]<<"\t";
    vec.pop_back();
    print(vec);
}

void print2(std::vector<int> vec,int i=0)
{
    if(i==vec.size())
        return;
    print2(vec,++i);
    std::cout<<vec[i-1]<<"\t";

}

int main()
{
    int n = 6;
    std::vector<int> data = {2,4,6,8,10,6,12,6};
    std::vector<int> data2 = {6,4,2,6,8,733,1,5};

    print(data);
    std::cout<<std::endl;

    print2(data2);
    std::cout<<std::endl;
    return 0;
}
