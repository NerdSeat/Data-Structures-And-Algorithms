#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>

std::string remAdjacent(std::string val)
{
    std::string res = "";
    /*std::stack<char> result;
    for(char c: val)
    {
        if(!result.empty() && result.top()==c)
        {
            result.pop();
        }
        else
        {
            result.push(c);
        }
    }
    while(!result.empty())
    {
        res.push_back(result.top());
        result.pop();
    }
    std::reverse(res.begin(),res.end());
*/
//Simulate an inplace stack on the input string
    int stackPointer = -1;
    for(int i=0;i<val.size();i++)
    {
        if(stackPointer== -1 || val[stackPointer]!=val[i])
        {
            stackPointer++;
            val[stackPointer]=val[i];
        }
        else
            stackPointer--;
    }
    for(int i = 0; i<=stackPointer;i++)
        res.push_back(val[i]);
    return res;
}
int main()
{
    std::vector<std::string> duplicates{"abbaca","aaabbbcd","Mississippi","trees","aaabb"};
    for(auto d: duplicates)
        std::cout<<remAdjacent(d)<<std::endl;
    return 0;
}