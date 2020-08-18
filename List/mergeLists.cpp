#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

//merge two sorted stl singly linked lists into one sorted singly linked list.

std::forward_list<int> merge(std::forward_list<int> list1, std::forward_list<int> list2)
{
    std::forward_list<int> list;
    auto l_one = list1.begin(), l_two = list2.begin();
//This is if else statement is necessary to initialise the begining of the list for the insert_after statement.
//The forward list can either insert at the front, or after some pointer
    if (*l_one <= *l_two)
    {
        list.push_front(*l_one);
        ++l_one;
    }
    else
    {
        list.push_front(*l_two);
        ++l_two;
    }

    auto it = list.begin();
    while (l_one != list1.end() && l_two != list2.end())
    {
        if (*l_one <= *l_two)
        {
            list.insert_after(it,*l_one);
            l_one++;
        }
        else
        {
            list.insert_after(it,*l_two);
            l_two++;
        }
        ++it;
    }

    while (l_one != list1.end())
    {
        list.insert_after(it,*l_one);
        l_one++;
        ++it;
    }
    while (l_two != list2.end())
    {
        list.insert_after(it,*l_one);
        l_two++;
        ++it;
    }
    return list;
}
int main()
{
    std::forward_list<int> l1 = {2, 4, 5, 8, 9, 14, 18, 34, 45};
    std::forward_list<int> l2 = {1, 3, 5, 6, 11, 12};
    std::forward_list<int> list = merge(l1, l2);

    for (auto x : list)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
