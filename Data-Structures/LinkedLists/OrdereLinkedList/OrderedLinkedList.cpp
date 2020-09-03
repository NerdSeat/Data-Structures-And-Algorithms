#include "OrderedLinkedList.h"

template <typename T>
OrderedLinkedList<T>::OrderedLinkedList()
{
    head = tail = nullptr;
    size = 0;
}
template <typename T>
void OrderedLinkedList<T>::insert(const T &data)
{
    Node<T> *newNode = createNode(data);
    //if the list is empty, make the head and the tail point to the same node
    if (head == nullptr)
    {
        head = tail = newNode;
        size++;
        return;
    }
    //insert node at the head of the list
    if(newNode->data<=head->data)
    {
        newNode->next=head;
        head = newNode;
        size++;
        //if the list only has two nodes, make tail point to the second node
        if(head->next->next==nullptr)
            tail=head->next;
        return;
    }
    //insert node at the tail end of the list
    if(tail->data<=data)
    {
        tail->next = newNode;
        tail=tail->next;
        size++;
        return;
    }
    //insert node somewhere in the middle
    Node<T> *trail = head;
    Node<T> *forward = head->next;
    while (forward != nullptr)
    {
        if (data>= trail->data && data <= forward->data)
        {
            trail->next = newNode;
            newNode->next = forward;
            size++;
            if(newNode->next==nullptr)
                tail = newNode;
            return;
        }
        trail = trail->next;
        forward = forward->next;
    }
    tail->next = newNode;
    tail = tail->next;
    size++;
}
template <typename T>
Node<T> *OrderedLinkedList<T>::createNode(const T &data)
{
    Node<T> *temp = new Node<T>();
    temp->data = data;
    return temp;
}
template <typename T>
void OrderedLinkedList<T>::remove(const T &data)
{
    Node<T> *temp = head;
    if (head->data == data)
    {
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node<T> *forward = head->next;
    {
        while (forward != nullptr)
        {
            if (forward->data == data)
            {
                temp->next =forward->next;
                delete forward;
                size--;
                return;
            }
        }
    }
}
template <typename T>
bool OrderedLinkedList<T>::search(const T &data) const
{
    if (head == nullptr)
    {
        std::cout << "The list is empty\n";
        return false;
    }
    if (head->data == data)
        return true;
    Node<T> *temp = head->next;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}
template <typename T>
bool OrderedLinkedList<T>::isEmpty() const
{
    return head == nullptr;
}
template <typename T>
void OrderedLinkedList<T>::print() const
{
    if (head == nullptr)
    {
        std::cout << "The list is empty\n";
        return;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp=temp->next;
    }
    std::cout << std::endl;
}
template <typename T>
unsigned int OrderedLinkedList<T>::getSize() const
{
    return size;
}
template <typename T>
OrderedLinkedList<T>::~OrderedLinkedList()
{
    Node<T> *temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}