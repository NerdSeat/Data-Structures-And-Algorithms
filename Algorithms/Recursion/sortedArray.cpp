#include<vector>
#include<iostream>

//check if array is sorted in ascending order
bool isSorted(std::vector<int>& vec)
{
    if(vec.size()==0||vec.size()==1)
        return true;
    if(vec[0]>vec[1])
        return false;
    vec.erase(vec.begin());
    return isSorted(vec);
}

int main()
{
    std::vector<int> data = {2,4,6,8,10,12};
    std::vector<int> data2 = {4,2,6,733,1,5};

    if(isSorted(data))
        std::cout<<"Data is sorted\n";
    else
        std::cout<<"Data is not sorted\n";

    if(isSorted(data2))
        std::cout<<"Data2 is sorted\n";
    else
        std::cout<<"Data2 is not sorted\n";

   return 0;
}