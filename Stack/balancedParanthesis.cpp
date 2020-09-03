#include <iostream>
#include <stack>
#include <vector>
#include<map>

bool balanced(std::string str)
{
    std::map<char, char> values;
    values.insert(std::make_pair('(', ')'));
    values.insert(std::make_pair('{', '}'));
    values.insert(std::make_pair('[', ']'));
    std::stack<char> braces;
    bool bal = false;
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
            if (c!=values[braces.top()]||braces.empty())
                return bal;
            braces.pop();
        }
        ++i;
    }
    return bal=braces.empty();
}

int main()
{
    std::vector<std::string> vec;
    std::string curl = "{this{is a{ba([()])lan}ced} string{}}";
    std::string unbal = "{(({})][])}";
    vec.push_back(curl);
    vec.push_back(unbal);
    for (auto x : vec)
        if (balanced(x))
            std::cout << x << " is a string with balanced paranthesis\n";
        else
            std::cout << x << " is not a string with balanced paranthesis\n";

    return 0;
}