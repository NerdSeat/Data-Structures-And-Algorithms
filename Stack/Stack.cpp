#include "Stack.h"
template<class T>
Stack<T>::Stack()
{
    top = new Node<T>;
    top ->link= nullptr;
    size = 0;
}
template<class T>
void Stack<T>::push(const T &data)
{
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->link = top;
    top = temp;
    size++;
}
template<class T>
void Stack<T>::pop()
{
    if(isEmpty())
    {
        std::cout<<"The stack is empty\n";
        exit(0);
    }
    std::cout<<top->data<<std::endl;
    Node<T>* temp = top->link;
    delete top;
    top = temp;
}
template<class T>
int Stack<T>::get_size()const
{
    return size;
}
template<class T>
bool Stack<T>::isEmpty()const
{
    return size ==0;
}
template<class T>
void Stack<T>::print()const
{
    Node<T>* trav = top;
    std::cout<<"top->";
    while (trav->link!=nullptr)
    {
        std::cout<<trav->data<<"->";
        trav=trav->link;
    }
    std::cout<<std::endl;
}
template<class T>
Stack<T>::~Stack()
{

}