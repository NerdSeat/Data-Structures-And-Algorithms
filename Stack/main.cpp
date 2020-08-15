#include "Stack.cpp"
#include <iostream>
#include <algorithm>
#include <stack>
int main()
{
    std::stack<int> vals;
    Stack<int> my_stack;
    my_stack.push(8);
    my_stack.push(4);
    my_stack.push(3);
    my_stack.push(5);
    std::cout << "The values in the custom stack are\n";
    while (!my_stack.empty())
    {
        std::cout << my_stack.top() << std::endl;
        my_stack.pop();
    }

    std::cout << "The values in the stl stack are \n";
    vals.push(7);
    vals.push(4);
    vals.push(5);
    vals.push(9);
    while (!vals.empty())
    {
        std::cout << vals.top() << std::endl;
        vals.pop();
    }
    return 0;
}