#include<vector>
#include<iostream>

void positions(std::vector<int> vec,int num,int i=0)
{
    if(vec.size()==i)
        return;
    if(vec[i]==num)
        std::cout<<"\t"<<i<<"\t";
    positions(vec,num,++i);
}
int main()
{
    int n = 6;
    std::vector<int> data = {2,4,6,8,10,6,12,6};
    std::vector<int> data2 = {6,4,2,6,8,733,1,5};
    
    std::cout<<n<<" occurs at index ";
    positions(data,6);
    std::cout<<" in data \n";

    std::cout<<n<<" occurs at index ";
    positions(data2,6);
    std::cout<<" in data2 \n";
    
}