#include "LinkedList.cpp"
#include <iostream>
#include <string>
#include<vector>

int main()
{
    LinkedList<int> numbers;
    LinkedList<std::string> names;
    std::vector<std::string> strings{"Joseph","Matt","Dean","Holden","David","Nichol"};
    std::vector<int> digits{5,8,1,3,2,7};
    for(auto d :digits)
        numbers.push_back(d);
    numbers.print();

    std::cout << "The size of the integer list is: " << numbers.getSize() << std::endl;

    for(auto s: strings)
        names.push_back(s);
        std::string random = "Candice";
    names.insert_at(random,3);
    std::cout<<"The names as they were added to the list\n";
    names.print();

    std::cout<<"The names again in reverse order\n";
    names.reverse();
    names.print();

    std::cout<<"The names after sorting the list \n";
    names.sort();
    names.print();
    
    std::cout << "The number of people registered is: " << names.getSize() << std::endl;
    names.remove("David");
    names.remove("Joseph");
    std::cout << "The number of people registered after removing two names is: " << names.getSize() << std::endl;
    names.print();
    
    return 0;
}
