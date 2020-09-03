#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
bool numeric(std::string &v)
{
    return !v.empty() && std::all_of(v.begin(), v.end(), ::isdigit);
}

auto result(std::string &fix)
{
    std::stringstream buffer(fix);
    std::string word;
    std::stack<std::string> list;
    double res, val1, val2;
    while (getline(buffer, word, ' '))
    {
        if (word == "+")
        {
            assert(list.size() >= 2);
            val1 = std::stod(list.top());
            list.pop();
            val2 = std::stod(list.top());
            list.pop();
            res = val1 + val2;
            list.push(std::to_string(res));
        }
        else if (word == "-")
        {
            assert(list.size() >= 2);
            val1 = std::stod(list.top());
            list.pop();
            val2 = std::stod(list.top());
            list.pop();
            res = val1 - val2;
            list.push(std::to_string(res));
        }
        else if (word == "*")
        {
            assert(list.size() >= 2);
            val1 = std::stod(list.top());
            list.pop();
            val2 = std::stod(list.top());
            res = val1 * val2;
            list.pop();
            list.push(std::to_string(res));
        }
        else if (word == "/")
        {
            assert(list.size() >= 2);
            val1 = std::stod(list.top());
            list.pop();
            val2 = std::stod(list.top());
            res = val1 / val2;
            list.pop();
            list.push(std::to_string(res));
        }
        if (numeric(word))
        {
            list.push(word);
        }
    }
    auto value = list.top();
    list.pop();
    if (!list.empty())
    {
        std::cout << "Invalid operation\n";
        exit(0);
    }
    return value;
}

int main()
{
    std::string read = "6 5 2 3 + 8 * + 3 + *";
    std::string another = "12 46 / 3  5 - *";
    std::string another_one = "12  46 / 3  5 - * 7";

    // read a string line and store each word from the line into a vector
    std::vector<std::string> stringList;

    stringList.push_back(another);
    stringList.push_back(read);
    stringList.push_back(another_one);
    /*    std::stringstream buffer(read);
    std::string eachWord;

    while (getline(buffer, eachWord, ' '))
    {
        stringList.push_back(eachWord);
    }
*/
    for (auto x : stringList)
    {
        std::cout << x << " ";
        std::cout << " =  " << result(x) << std::endl;
    }
    return 0;
}
