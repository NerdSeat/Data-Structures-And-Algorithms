#ifndef NODE_H
#define NODE_H
template <typename T>
struct Node
{
    T data;
    Node *Next = nullptr;
    Node *Previous = nullptr;
};
#endif
