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
LinkedList<T>::LinkedList(unsigned int n, T d)
{
    head = createNode(d);
    tail = head;    
    size = n;
    Node<T>* temp = head;
    for(int i = 0; i < n; ++i)
        tail->link = createNode(d);
}
template <typename T>
void LinkedList<T>::push_front(T data)
{
    Node<T> *newNode = createNode(data);
    if (empty())
    {
        head = newNode;
        tail = head;
        size++;
        return;
    }
    newNode->link = head;
    head = newNode;
    size++;
}
template<typename T>
void LinkedList<T>::insert_at(T data, int n)
{
    assert(head!=nullptr);
    assert(size>=n);
    Node<T> *temp = head;
    int i = 0;

    Node<T>* node = createNode(data);
    while( i < n-1 &&temp != nullptr)
    {
        temp=temp->link;
        i++;
    }
    node->link = temp->link;
    temp->link = node;
    
}
template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node<T> *newNode = createNode(data);
    if (empty())
    {
        head = newNode;
        tail = head;
        size++;
        return;
    }
    tail->link = newNode;
    tail = tail->link;
    size++;
}
template <typename T>
Node<T> *LinkedList<T>::createNode(T data)
{
    Node<T> *node = new Node<T>();
    node->data = data;
    return node;
}

template<typename T>
Node<T>* LinkedList<T>::getHead()const
{
  return head;
}
template<typename T>
Node<T>* LinkedList<T>::getTail()const
{
  return tail;
}

template <typename T>
bool LinkedList<T>::empty()
{
    return size == 0;
}
template <typename T>
void LinkedList<T>::remove(T data)
{
    if (!find(data))
    {
        std::cout << data << " is not in the list.\n";
        return;
    }
    Node<T> *temp1 = head;
    if (head->data == data)
    {
        head = head->link;
        delete temp1;
        size--;
        return;
    }
    Node<T> *temp2 = head->link;
    while (temp2 != nullptr)
    {
        if (temp2->data == data)
        {
            temp1->link = temp2->link;
            delete temp2;
            size--;
            return;
        }
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
}

template<typename T>
void LinkedList<T>::reverse()
{
    tail = head;
    
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;
    
    while(curr!=nullptr)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T>
bool LinkedList<T>::find(T data)
{
    if (empty())
        return false;

    if (head->data == data)
        return true;

    Node<T> *temp = head->link;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return true;
        temp = temp->link;
    }
    return false;
}

template <typename T>
void LinkedList<T>::sort()
{
    int length = size;
    mergeSort(head,length);
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "-> ";
        temp = temp->link;
    }
    std::cout <<"nullptr"<< std::endl;
}

template <typename T>
unsigned int LinkedList<T>::getSize()const
{
    return size;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = head;
    while (head != nullptr)
    {
        head = head->link;
        delete temp;
        temp = head;
    }
}

template<typename T>
void LinkedList<T>::mergeSort(Node<T>* node,int l)
{
    if(node==nullptr)
        return;
    int mid = l/2;
    
}
