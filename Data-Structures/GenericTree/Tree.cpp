#include "Tree.h"

template<typename T>
Tree<T>::Tree()
{
    root = nullptr;
}
template<typename T>
void Tree<T>::insert()
{
    std::queue<Node<T>*> queueNodes;
    T rootNode;
    std::cout<<"Enter the root node:\t";
    std::cin>>rootNode;
    root = newNode(rootNode);
    queueNodes.push(root);

    while(!queueNodes.empty())
    {
        Node<T>* front = queueNodes.front();
        queueNodes.pop();
        std::cout<<"How many child nodes does "<<front->data<<" have? ";
        std::size_t nodes;
        std::cin>>nodes;
        for(int i = 1; i <= nodes; ++i)
        {
            std::cout<<"Enter the "<<i<<"th node:\t";
            T child;
            std::cin>>child;
            Node<T>* childNode = newNode(child);
            queueNodes.push(childNode);
            front->children.push_back(childNode);
        }
    }
}

template<typename T>
void Tree<T>:: print()const
{
    //privatePrint(root);
    levelOrderPrint();
    std::cout<<"\n";
}
template<typename T>
void Tree<T>::privatePrint(Node<T>* node)const
{
    if(node==nullptr){
        std::cout<<"The tree is empty\n";
        return;
    }
    //print the parent node
    std::cout<<node->data<<": ";
    //print all the child nodes under the parent node
    for(int i =0; i<node->children.size();++i)
        std::cout<<node->children[i]->data<<" ";
    std::cout<<std::endl;

    for(int i = 0; i<node->children.size(); ++i)
        privatePrint(node->children.at(i));
}
template<typename T>
void Tree<T>::levelOrderPrint()const
{
    Node<T>* node = root;
    std::queue<Node<T>*> nodes;
    nodes.push(node);
    while(!nodes.empty())
    {
        Node<T>* top = nodes.front();
        std::cout<<top->data<<": ";
        nodes.pop();
        for(int i = 0; i <top->children.size();++i)
        {
            nodes.push(top->children[i]);
            std::cout<<top->children.at(i)->data<<" ";
        }
        std::cout<<"\n";
    }

}
template<typename T>
Node<T>* Tree<T>::newNode(T d)const
{
    Node<T>* node  = new Node<T>(d);
    return node;
}
template<typename T>
Tree<T>::~Tree()
{
    
}
template<typename T>
int Tree<T>::countNodes()const
{
    return privateCountNodes(root);
}
template<typename T>
int Tree<T>::privateCountNodes(Node<T>* node)const
{
    if(node==nullptr)
        return 0;
    int sum = 1;
    for(int i = 0; i<node->children.size();++i)
    {
        sum += privateCountNodes(node->children[i]);
    }
    return sum;
}
template<typename T>
int Tree<T>::height()const
{
    return privateHeight(root);
}
template<typename T>
int Tree<T>::privateHeight(Node<T>* node)const
{
    if(node==nullptr)
        return 0;
    int maxHeight = 0;
    for(int i = 0; i<node->children.size(); ++i)
    {
        int childHeight = privateHeight(node->children[i]);
        maxHeight = maxHeight > childHeight ? maxHeight : childHeight;
    }
    return maxHeight + 1;//max height plus the root node
}