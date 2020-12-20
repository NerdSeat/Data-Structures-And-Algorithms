#include<vector>
#include<iostream>

int index(std::vector<int> vec,int num,int i=0)
{
    if(vec.size()==0)
        return -1;
    if(vec[0]==num)
        return i;
    vec.erase(vec.begin());
    return index(vec,num,i+1);
    
}

int main()
{
    int n = 6;
    std::vector<int> data = {2,4,6,8,10,12};
    std::vector<int> data2 = {4,2,8,733,1,5};
    std::cout<<n<<" is at index "<<index(data,n)<<" in data\n";
    std::cout<<n<<" is at index "<<index(data2,n)<<" in data2\n";
    return 0;
}