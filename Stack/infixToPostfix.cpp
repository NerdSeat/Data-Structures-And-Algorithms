#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
//check if a string is a numeric string
bool operand(std::string &v)
{
    return !v.empty() && std::all_of(v.begin(), v.end(), ::isdigit);
}
// checks if an operand is a valid operand
bool notLegal(std::string &operand)
{
    return std::any_of(operand.begin(), operand.end(), ::isalpha);
}

bool higherPrecedence(std::string p1, std::string p2)
{
    bool prec = false;
    if (p1 == "-" && p2 == "*")
        return prec;
    else if (p1 == "+" && p2 == "*")
        return prec;
    if (p1 == "-" && p2 == "/")
        return prec;
    else if (p1 == "+" && p2 == "/")
        return prec;
    else if(p1=="("||p2=="(")
        return prec;
    else
        return prec = true;
}
std::string postfix(std::string &exp)
{
    std::map<std::string, std::string> operation;
    operation.insert(std::make_pair("+", "+"));
    operation.insert(std::make_pair("-", "-"));
    operation.insert(std::make_pair("*", "*"));
    operation.insert(std::make_pair("/", "/"));
    operation.insert(std::make_pair("(", "("));
    std::stringstream buffer(exp);
    std::string post = " ";
    std::stack<std::string> op;
    std::string word;

    while (getline(buffer, word, ' '))
    {
        if (notLegal(word))
        {
            return "not a legal expression\n";
        }
        if (operand(word))
            post += word + ' ';
        if (word == operation[word])
        {
            while (!op.empty() && higherPrecedence(op.top(), word))
            {
                post += op.top() + ' ';
                op.pop();
            }
            op.push(word);
        }
        if (word == ")")
        {
            while (!op.empty() && op.top()!="(")
            {
                post += op.top() + ' ';
                op.pop();
            }
            op.pop();
        }
    }
    while (!op.empty())
    {
        post += op.top() + ' ';
        op.pop();
    }
    return post;
}

int main()
{
    std::string expr_one = "( 45 + 23 * 2 ) / ( ( 30  * 4 ) - 100 )";
    std::string expr_two = "10 * 6 / 12 - 5 + 9";
    std::string expr_three = "45 + 23 +  t  * 2 / 5";
    std::vector<std::string> vec;
    vec.push_back(expr_one);
    vec.push_back(expr_two);
    vec.push_back(expr_three);
    for (auto x : vec)
        std::cout << postfix(x) << std::endl;
    return 0;
}