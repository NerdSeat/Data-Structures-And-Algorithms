#include "doublyLinkedList.h"

template<class T>
doublyLinkedList<T>::doublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<class T>
Node<T>* doublyLinkedList<T>::newNode(T d)const
{
    Node<T>* temp = new Node<T>();
    temp->next = nullptr;
    temp->previous = nullptr;
    temp->data = d;
    return temp;
}
template<class T>
void doublyLinkedList<T>::insert(T d)
{
    if(head==nullptr)
    {
        head = newNode(d);
        tail = head;
        size++;
        return;
    }
    Node<T>* temp = newNode(d);
    //inserts the node at the head of the link
    temp->next=head;
    head->previous=temp;
    head = temp;
    size++;
}
template<class T>
void doublyLinkedList<T>::print()const
{
    Node<T> *trav = head;
    std::cout<<"[";
    while(trav!=nullptr)
    {
        std::cout<<trav->data;
        trav = trav->next;
    }
    std::cout<<"]"<<std::endl;
}
template<class T>
void doublyLinkedList<T>::printReverse()const
{
    Node<T> *trav = tail;
    std::cout<<"[";
    while(trav!=nullptr)
    {
        std::cout<<trav->data;
        trav=trav->previous;
    }
    std::cout<<"]"<<std::endl;
}
template<class T>
void doublyLinkedList<T>::sort()const
{

}
template<class T>
void doublyLinkedList<T>::remove(T d)
{
    Node<T> *temp = new Node<T>();
    if(head->data==d)
    {
        temp=head->next;
        delete head;
        head=temp;
        size--;
        return;
    }
    if(tail->data==d)
    {
        temp=tail->previous;
        delete tail;
        tail=temp;
        size--;
        return;
    }
    Node<T>* trail = new Node<T>();
    trail=head;
    temp = head->next;
    while (temp!=nullptr)
    {
        if(temp->data==d)
        {
            trail->next=temp->next;
            delete temp;
            size--;
            return;
        }
        trail=trail->next;
        temp=temp->next;
    }
    std::cout<<d<<" is not in the list."<<std::endl;
}
template<class T>
inline T doublyLinkedList<T>::peek()const
{
    assert(head!=nullptr);
    return head->data;
}
template<class T>
inline bool doublyLinkedList<T>::isEmpty()const
{
    return size==0;
}
template<class T>
doublyLinkedList<T>::~doublyLinkedList()
{
    delete head;
    delete tail;
}