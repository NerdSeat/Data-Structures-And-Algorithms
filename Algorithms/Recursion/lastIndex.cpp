#include<iostream>
#include<vector>

int lastIndex(std::vector<int> vec,int num,int index=-1,int i=0)
{
    //This if statement will return -1 if the array is empty or num is not in the array
    if(vec.size()==0)
        return index;
    if(vec[0]==num)
        index = i;
    vec.erase(vec.begin());
    return lastIndex(vec,num,index,++i);
}

int lastIndex2(std::vector<int> vec,int num)
{
    if(vec.size()==0)
        return -1;
    if(vec[vec.size()-1]==num)
        return vec.size()-1;
    vec.pop_back();
    return lastIndex(vec,num);
}
int main()
{
    int n = 6;
    std::vector<int> data = {2,4,6,8,10,6,12,6};
    std::vector<int> data2 = {6,4,2,6,8,733,1,5};
    std::cout<<n<<"'s last index is at "<<lastIndex(data,n)<<" in data using the check from front function\n";
    std::cout<<n<<"'s last index is at "<<lastIndex(data2,n)<<" in data2 using the check from front function\n";

    //using the second function
    std::cout<<n<<"'s last index is at "<<lastIndex2(data,n)<<" in data using the check from the back function\n";
    std::cout<<n<<"'s last index is at "<<lastIndex2(data2,n)<<" in data2 using the check from the back function\n";
}