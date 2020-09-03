#include "OrderedLinkedList.cpp"

int main()
{
    OrderedLinkedList<int> numbers;
    OrderedLinkedList<std::string> names;
    OrderedLinkedList<std::string> reverse;
    numbers.insert(5);
    numbers.insert(8);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(2);
    numbers.print();

    std::cout << "The size of the integer list is: " << numbers.getSize() << std::endl;
    names.insert("Joseph");
    names.insert("Matt");
    names.insert("Dean");
    names.insert("Holden");
    names.insert("David");
    std::cout << "The number of the people registered is: " << names.getSize() << std::endl;
    names.print();
    names.remove("David");

    std::cout << "The number of the people registered is: " << names.getSize() << std::endl;
    names.print();
    return 0;
}