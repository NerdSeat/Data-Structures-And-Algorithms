#include<iostream>
#include<vector>

bool isPresent(std::vector<int> vec,int num)
{
    if(vec.size()==0)
        return false;
    if(vec[0]==num)
        return true;
    vec.erase(vec.begin());
    return isPresent(vec,num);
}

int main()
{
    int n = 6;
    std::vector<int> data = {2,4,6,8,10,12};
    std::vector<int> data2 = {4,2,8,733,1,5};

    if(isPresent(data,n))
        std::cout<<n<<" is in the array\n";
    else
        std::cout<<n<<" is not in the array\n";
    
    
    if(isPresent(data2,n))
        std::cout<<n<<" is in the array\n";
    else
        std::cout<<n<<" is not in the array\n";
}