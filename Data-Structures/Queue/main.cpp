#include "Queue.cpp"
#include <iostream>
#include <algorithm>
#include <queue>
int main()
{
    std::queue<int> vals;
    Queue<int> my_queue;
    my_queue.push(8);
    my_queue.push(4);
    my_queue.push(3);
    my_queue.push(5);
    std::cout << "The values in the custom queue are\n";
    while (!my_queue.empty())
    {
        std::cout << my_queue.front() << std::endl;
        my_queue.pop();
    }

    std::cout << "The values in the stl queue are \n";
    vals.push(7);
    vals.push(4);
    vals.push(5);
    vals.push(9);
    while (!vals.empty())
    {
        std::cout << vals.front() << std::endl;
        vals.pop();
    }
    return 0;
}