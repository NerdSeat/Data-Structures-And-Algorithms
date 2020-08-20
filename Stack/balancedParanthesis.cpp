#include <iostream>
#include <stack>
#include <vector>
#include<map>
#include<algorithm>

bool balanced(std::string str)
{
    std::map<char, char> values;
    values.insert(std::make_pair('(', ')'));
    values.insert(std::make_pair('{', '}'));
    values.insert(std::make_pair('[', ']'));
    std::stack<char> braces;
    //bool balanceSoFar = true;
    int i = 0;
    while (i < str.length())
    {
        char c = str[i];
        if (values.count(c))
        {
            braces.push(c);
        }
        else if(c==')'||c=='}'||c==']')
        {
            if (braces.empty())
                return false;
            if(c!=values[braces.top()])
                return false;
            braces.pop();
        }
        ++i;
    }
    return braces.empty();
}

int main()
{
    std::vector<std::string> vec;
    std::string curl = "{this{is (a{ )balan}ced} string{}}";
    std::string unbal = "(()[])";
    vec.push_back(curl);
    vec.push_back(unbal);
    for (auto x : vec)
        if (balanced(x))
            std::cout << x << " is a string with balanced braces\n";
        else
            std::cout << x << " is not a string with balanced braces\n";

    std::map<char, char> values;
    values.insert(std::make_pair('(', ')'));
    values.insert(std::make_pair('{', '}'));
    values.insert(std::make_pair('[', ']'));
    char c = '[';
    std::cout << values.count(c) << std::endl;
    std::cout << values[c] << std::endl;
    return 0;
}