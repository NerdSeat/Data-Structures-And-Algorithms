#include <iostream>
#include <stack>
#include <string>
#include <vector>

//Determines whether a given string is in the language
//language is L{s$s'} such that s' =reverse(s) and $ is a special character that separates s and s'
bool language(std::string str)
{
    bool isInLanguage = false;
    char c;
    std::stack<char> left, right;
    int i = 0;
    int sp = int(str.find('$'));
    int j=sp+1;
    while (i < sp)
    {
        left.push(str[i]);
        i++;
    }

    while (j < str.length())
    {
        if(str[j]!=left.top())
            break;
        if(!left.empty())
            left.pop();
        j++;
    }
    if((j==str.length())&&left.empty())
        isInLanguage=true;

    return isInLanguage;
}

int main()
{
    std::vector<std::string> vec;
    std::string v1 = "eeaa$aaee", v2 = "ABAB$B1ABA", v3 = "1001$01011";
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    for (auto x : vec)
        if (language(x))
            std::cout << x << " is in the language\n";
        else
            std::cout << x << " is not in the language\n";

    return 0;
}