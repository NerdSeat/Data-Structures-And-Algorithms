#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
    T data;
    Node* link = nullptr;
};
#endif