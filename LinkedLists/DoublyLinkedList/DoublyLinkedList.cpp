#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}
template <typename T>
void DoublyLinkedList<T>::insertHead(T data)
{
    Node<T> *node = createNode(data);
    if (isEmpty())
    {
        head = node;
        tail = head;
        size++;
        return;
    }
    node->Next = head;
    head->Previous = node;
    head = node;
    size++;
}
template <typename T>
void DoublyLinkedList<T>::insertTail(T data)
{
    Node<T> *node = createNode(data);
    if (isEmpty())
    {
        tail = node;
        head = tail;
        size++;
        return;
    }
    tail->Next = node;
    node->Previous = tail;
    tail = node;
    size++;
}
template <typename T>
Node<T> *DoublyLinkedList<T>::createNode(T data)
{
    Node<T> *node = new Node<T>();
    node->data = data;
    return node;
}
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0;
}
template <typename T>
bool DoublyLinkedList<T>::isInList(T data)
{
    if(head==nullptr)
        return false;
    Node<T>* temp = head;
    if(temp->data==data)
    {
        return true;
    }
    while(temp->Next!=nullptr)
    {
        if(temp->data ==data)
            return true;
        temp = temp->Next;
    }
    return false;
}
template <typename T>
void DoublyLinkedList<T>::removeNode(T data)
{
    Node<T> *trailNode = head;
    if (data == head->data)
    {
        head = head->Next;
        head->Previous = nullptr;
        delete trailNode;
        size--;
        return;
    }
    if(data==tail->data)
    {
        trailNode = tail;
        tail=tail->Previous;
        tail->Next = nullptr;
        delete trailNode;
        size--;
        return;
    }
    Node<T> *remNode = head->Next; //node to be removed
    while(remNode->Next->Next!=nullptr)//the loop doesn't check the last node as that been checked above. don't really need to worry about it though as the function will not get here if the node to be deleted is the last node.
    {
        if(remNode->data ==data){
            trailNode->Next = remNode->Next;
            remNode->Next->Previous = trailNode;
            delete remNode;
            size--;
            return;
        }
        trailNode=trailNode->Next;
        remNode=remNode->Next;
    }
}
template <typename T>
void DoublyLinkedList<T>::printList()
{
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->Next;
    }
    std::cout << std::endl;
}
template <typename T>
unsigned int DoublyLinkedList<T>::getSize()
{
    return size;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* temp = head;
    while(head!=nullptr)
    {
        std::cout<<head->data<<" is being deallocated from the list\n";
        head=head->Next;
        delete temp;
        temp = head;
    } 
}
template <typename T>
void DoublyLinkedList<T>::reversePrint()
{
    Node<T> *temp = tail;
    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->Previous;
    }
    std::cout << std::endl;
}