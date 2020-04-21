#include "array.cpp"

int main()
{
    array<int> list(3);
    list.insert(3);
    list.insert(8);
    list.insert(2);
    list.insert(7);
    list.insert(9);
    std::cout<<"The size of the array is: "<<list.getSize()<<std::endl;
    list.print();
    list.remove(9);
    list.remove(2);
    std::cout<<"The size of the array is: "<<list.getSize()<<std::endl;
    list.print();
    return 0;
}