#include "Stack.cpp"

#include<iostream>

int main()
{
    Stack<int> stack;
    stack.push(8);
    stack.push(4);
    stack.push(3);
    stack.push(5);
    stack.pop();

    std::cout<<stack.top()<<std::endl;
    return 0;
}