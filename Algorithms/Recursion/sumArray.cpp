#include<vector>
#include<iostream>

//return the sum of an array recursively
int ArraySum(std::vector<int> vec)
{
    if(vec.size()==0)
        return 0;
    if (vec.size()==1)
        return vec[0];
    int val = vec[0];
    vec.erase(vec.begin());
    return val + ArraySum(vec);
}

int main()
{
    std::vector<int> data = {2,4,6,8,10,12};
    std::vector<int> data2 = {4,2,6,733,1,5};
    std::cout<<"The sum of data is: "<<ArraySum(data)<<std::endl;
    std::cout<<"The sum of data2 is: "<<ArraySum(data2)<<std::endl;

    return 0;
}