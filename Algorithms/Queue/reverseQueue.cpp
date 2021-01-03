#include<queue>
#include<stack>
#include<iostream>

template<typename T>
std::queue<T> reverse(std::queue<T> stuff)
{
    std::stack<T> temp;
    while (!stuff.empty())
    {
        temp.push(stuff.front());
        stuff.pop();
    }
    while (!temp.empty())
    {
        stuff.push(temp.top());
        temp.pop();
    }
    return stuff;
    
}
int main()
{
    std::queue<std::string> list;
    std::vector<std::string> names{"Joseph","Lisa","Nichol","Andrea","Matt","Dave","Lucy"};
    for (auto n: names)
        list.push(n);
    
    std::queue<std::string> newQueue = reverse(list);

    while (!list.empty())
    {
        std::cout<<list.front()<<"\t";
        list.pop();
    }
    std::cout<<"\n";
    while (!newQueue.empty())
    {
        std::cout<<newQueue.front()<<"\t";
        newQueue.pop();
    }
    std::cout<<"\n";    
    
    return 0;
}