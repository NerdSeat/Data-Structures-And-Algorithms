#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>

std::string remAdjacent(const std::string& val)
{
    std::stack<char> result;
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
    std::string res = " ";
    while(!result.empty())
    {
        res +=result.top();
        result.pop();
    }
    std::reverse(res.begin(),res.end());
    return res;
}
int main()
{
    std::vector<std::string> duplicates{"abbaca","aaabbbcd","Mississippi","trees","aaabb"};
    for(auto d: duplicates)
        std::cout<<remAdjacent(d)<<std::endl;
    return 0;
}