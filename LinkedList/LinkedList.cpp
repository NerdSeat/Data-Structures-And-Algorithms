#include "LinkedList.h"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList()
{
   head = nullptr;
   size=0;
}
template<class T>
void LinkedList<T>::insertHead(T d)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = d;
    newNode->link = head;
    head = newNode;
    size++; 
}
template<class T>
void LinkedList<T>::insertTail(T d)
{
    Node<T>* newNode = new Node<T>();
    Node<T>* temp = new Node<T>();
    newNode->data = d;
    newNode->link = nullptr;

    if(size==0)
    {
        head=newNode;
        size++;
        return;
    }
    temp = head;
    while (temp->link != nullptr)
    {
        temp=temp->link;
    }
    temp->link = newNode;
    size++;
}
template<class T>
void LinkedList<T>::printList()
{
    Node<T>* trav = new Node<T>();
    trav = head;
    while (trav != nullptr)
    {
        std::cout<<trav->data<<'\t';
        trav = trav->link;
    }
    std::cout<<std::endl;
}

//linear sort for simplicity 
template<class T>
void LinkedList<T>::sort()
{
    T data;
    Node<T>* trav = new Node<T>();
    Node<T>* trail = new Node<T>();
    trav =head->link;
    trail = head;
    while (trav != nullptr)
    {
      if(trail->data > trav->data)
	{
	  data = trav->data;
	  trav->data = trail->data;
	  trail->data = data;
	}
      trav = trav->link;
      trail=trail->link;
    }
}
template<class T>
void LinkedList<T>::remove(T d)
{
    Node<T>* temp,*trail;

//remove node at the head of the list
    if(head->data==d)
    {
        temp=head;
        head=head->link;
        delete temp;
        size--;
        return;
    }

    temp=head->link;
    trail = head;
    while (temp != nullptr)
    {
        if(temp->data==d)
        {
            trail->link = temp->link;
            delete temp;
            size--;
            return;
        }
        trail = trail->link;
        temp = temp->link;
    }
        std::cout<<d<<" is not in the list\n";
}
template<class T>
int LinkedList<T>::getSize()const
{
    return size;
}