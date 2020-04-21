//#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>
#include <string>

 int main()
{
    LinkedList<int> numbers;
    LinkedList<std::string> names;
    LinkedList<std::string> reverse;
    numbers.insertHead(5);
    numbers.insertHead(8);
    numbers.insertHead(1);
    numbers.insertHead(3);
    numbers.insertHead(2);
    numbers.sort();
    numbers.printList();
    std::cout<<"The size of the integer list is: "<<numbers.getSize()<<std::endl;
    names.insertHead("Joseph");
    names.insertHead("Matt");
    names.insertHead("Dean");
    names.insertHead("Holden");
    names.insertHead("David");
    names.printList();
    std::cout<<"The number of the people registered is: "<<names.getSize()<<std::endl;
    names.remove("Joseph");
    names.printList();

    std::cout<<"The number of the people registered is: "<<names.getSize()<<std::endl;
    names.sort();
    names.printList();
    reverse.insertTail("Joseph");
    reverse.insertTail("Matt");
    reverse.insertTail("Dean");
    reverse.insertTail("Holden");
    reverse.insertTail("David");
    reverse.printList();
    
    return 0;
}
