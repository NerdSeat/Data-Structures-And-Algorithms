#include "Queue.h"
template <typename T>
Queue<T>::Queue()
{
    size = 0;
    head =new Node<T>();
    tail = head;
}
template <typename T>
void Queue<T>::pop()
{
    assert(!empty());
    Node<T> *temp = head;
    head = head->link;
    delete temp;
    size--;
}
template <typename T>
void Queue<T>::push(const T &d)
{
    Node<T> *temp = createNode(d);
    tail->link = temp;
    tail = temp;
    if (empty())
        head = temp;
    size++;
}
template<typename T>
T Queue<T>::front()const
{
    return head->data;
}
template<typename T>
bool Queue<T>::empty()const
{
    return size==0;
}
template<typename T>
Node<T>* Queue<T>::createNode(const T& d)
{
    Node<T>* node = new Node<T>();
    node->data = d;
    return node;
}
template<typename T>
Queue<T>::~Queue()
{
    Node<T>* temp = head;
    while(temp!=nullptr){
        head = head->link;
        delete temp;
        temp = head;
    }
}