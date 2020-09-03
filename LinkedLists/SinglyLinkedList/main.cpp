#include "LinkedList.cpp"
#include <iostream>
#include <string>
int main()
{
    LinkedList<int> numbers;
    LinkedList<std::string> names;
    //LinkedList<std::string> reverse;
    numbers.addToHead(5);
    numbers.addToHead(8);
    numbers.addToHead(1);
    numbers.addToHead(3);
    numbers.addToHead(2);
    //numbers.sort();
    numbers.printList();
    std::cout << "The size of the integer list is: " << numbers.getSize() << std::endl;
    names.addToTail("Joseph");
    names.addToTail("Matt");
    names.addToTail("Dean");
    names.addToTail("Holden");
    names.addToTail("David");
    names.printList();
    std::cout << "The number of the people registered is: " << names.getSize() << std::endl;
    names.removeNode("David");
    names.removeNode("Joseph");
    std::cout << "The number of the people registered is: " << names.getSize() << std::endl;
    names.printList();
    return 0;
}