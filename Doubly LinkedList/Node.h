//doubly linked list node
#ifndef NODE_H
#define NODE_H
template<class T>
struct Node{
T data;
Node<T>* next;
Node<T>* previous;
};
#endif