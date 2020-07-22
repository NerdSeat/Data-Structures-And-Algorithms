#include "Node.h"
#include <cstring>

template<typename T>
Node<T>::Node(int level,T& value)
{
    next = new Node*[level+1];
    memset(next,nullptr,sizeof(Node*) * (level+1));
    this->data = value;
}
template<typename T>
Node<T>::~Node()
{
    delete next;
}