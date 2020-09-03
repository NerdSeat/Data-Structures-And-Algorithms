#ifndef NODE_H
#define NODE_H
#include<memory>
template<typename _Tp>
struct Node
{
    _Tp data;
    Node* link;
};
#endif