#include <iostream>
#include <stack>
#include <vector>
bool balanced(std::string str)
{
    std::stack<char> braces;
    bool balanceSoFar = true;
    int i = 0;
    while (balanceSoFar && i < str.length())
    {
        char c = str[i];
        if (c == '{')
        {
            braces.push(c);
        }
        else if (c == '}')
        {
            if (braces.empty())
            {
                balanceSoFar = false;
                break;
            }
            braces.pop();
        }
        ++i;
    }
    return balanceSoFar;
}

int main()
{
    std::vector<std::string> vec;
    std::string curl = "{this{is a{ balan}ced} string{}}";
    std::string unbal = "{this{is not {{}} a{ balan}ced} st}ring{}}";
    vec.push_back(curl);
    vec.push_back(unbal);
    for(auto x:vec)
        if(balanced(x))
            std::cout<<x<<" is a string with balanced braces\n";
        else
            std::cout<<x<<" is not a string with balanced braces\n";
    return 0;
}