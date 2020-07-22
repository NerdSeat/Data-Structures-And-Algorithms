//#include "LinkedList.h"
#include "DoublyLinkedList.cpp"
#include <iostream>
#include <string>

 int main()
{
    DoublyLinkedList<int> numbers;
    DoublyLinkedList<std::string> names;
    DoublyLinkedList<std::string> reverse;
    numbers.insertHead(5);
    numbers.insertHead(8);
    numbers.insertHead(1);
    numbers.insertHead(3);
    numbers.insertHead(2);
    //numbers.sort();
    numbers.printList();
    std::cout<<"The size of the integer list is: "<<numbers.getSize()<<std::endl;
    names.insertHead("Joseph");
    names.insertHead("Matt");
    names.insertHead("Dean");
    names.insertHead("Holden");
    names.insertHead("David");
    names.printList();
    std::cout<<"names printed in reverse \n";
    names.reversePrint();
    std::cout<<"The names entered in the tail of the list is :\n";
    reverse.insertTail("Joseph");
    reverse.insertTail("Matt");
    reverse.insertTail("Dean");
    reverse.insertTail("Holden");
    reverse.insertTail("David");
    reverse.printList();
    std::cout<<"The number of the people registered is: "<<names.getSize()<<std::endl;
    names.removeNode("Dean");
    std::cout<<"The number of the people registered is: "<<names.getSize()<<std::endl;
    names.printList();
}