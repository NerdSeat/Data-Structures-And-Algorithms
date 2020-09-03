#include "Stack.h"
template <typename T>
Stack<T>::Stack()
{
    head = nullptr;
    count=0;
}

template <typename T>
auto Stack<T>::pop()
{

    if (head == nullptr)
    {
        std::cout << "The stack is empty\n";
        exit(0);
    }
    T val = head->data;
    Node<T>* temp = head;
    head = head->link;
    delete temp;
    count--;
    return val;
}
template <typename T>
auto Stack<T>::top() const
{
    if (head == nullptr)
    {
        std::cout << "The stack is empty\n";
        exit(0);
    }
    return head->data;
}
template <typename T>
void Stack<T>::push(const T &d)
{
    Node<T> *node = createNode(d);
    if (head == nullptr)
        head = node;
    node->link = head;
    head = node;
    count++;
}
template <typename T>
Node<T>* Stack<T>::createNode(T d)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = d;
    newNode->link=nullptr;
    return newNode;
}
template <typename T>
bool Stack<T>::empty() const
{
    return count == 0;
}