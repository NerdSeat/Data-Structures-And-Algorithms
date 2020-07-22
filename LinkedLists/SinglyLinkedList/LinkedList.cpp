#include "LinkedList.h"
#include "Node.h"
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename T>
void LinkedList<T>::addToHead(T data)
{
    Node<T> *newNode = createNode(data);
    if (isEmpty())
    {
        head = newNode;
        tail = head;
        size++;
        return;
    }
    newNode->next = head;
    head = newNode;
    size++;
}
template <typename T>
void LinkedList<T>::addToTail(T data)
{
    Node<T> *newNode = createNode(data);
    if (isEmpty())
    {
        head = newNode;
        tail = head;
        size++;
        return;
    }
    Node<T>* tailNode = tail;
    tail = newNode;
    tailNode->next = tail;
    size++;
}
template <typename T>
Node<T> *LinkedList<T>::createNode(T data)
{
    Node<T> *node = new Node<T>();
    node->data = data;
    return node;
}
template <typename T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}
template <typename T>
void LinkedList<T>::removeNode(T data)
{
    if (!isInList(data))
    {
        std::cout << data << " is not in the list.\n";
        return;
    }
    Node<T> *temp1 = head;
    if (head->data == data)
    {
        head = head->next;
        delete temp1;
        size--;
        return;
    }
    Node<T> *temp2 = head->next;
    while (temp2 != nullptr)
    {
        if (temp2->data == data)
        {
            temp1->next = temp2->next;
            delete temp2;
            size--;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}
template <typename T>
bool LinkedList<T>::isInList(T data)
{
    if (isEmpty())
        return false;
    Node<T> *temp = head->next;
    if (head->data == data)
        return true;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}
template <typename T>
void LinkedList<T>::sortList()
{
}
template <typename T>
void LinkedList<T>::printList()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << std::endl;
}
template <typename T>
unsigned int LinkedList<T>::getSize()
{
    return size;
}
template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    delete tail;
}
