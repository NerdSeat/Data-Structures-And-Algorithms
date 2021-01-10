#include "GenericTree.h"

template<typename T>
GenericTree<T>::GenericTree()
{
    root = nullptr;
}
template<typename T>
void GenericTree<T>::insert()
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
void GenericTree<T>:: print()const
{
    privatePrint(root);
    //levelOrderPrint();
    std::cout<<"\n";
}
template<typename T>
void GenericTree<T>::privatePrint(Node<T>* node)const
{
    if(node==nullptr){
        std::cout<<"The GenericTree is empty\n";
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
void GenericTree<T>::levelOrderPrint()const
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
Node<T>* GenericTree<T>::newNode(T d)const
{
    Node<T>* node  = new Node<T>(d);
    return node;
}

template<typename T>
int GenericTree<T>::countNodes()const
{
    return privateCountNodes(root);
}
template<typename T>
int GenericTree<T>::privateCountNodes(Node<T>* node)const
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
int GenericTree<T>::height()const
{
    return privateHeight(root);
}
template<typename T>
int GenericTree<T>::privateHeight(Node<T>* node)const
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
template<typename T>
void GenericTree<T>::printNodesAtLevel(int k)const
{
    privatePrintNodesAt(root,k);
    std::cout<<"\n";
}
template<typename T>
void GenericTree<T>::privatePrintNodesAt(Node<T>* node,int k)const
{
    if(node==nullptr)
        return;
    if(k==0)
    {
        std::cout<<node->data<<"\t";
        return;
    }
    for(int i = 0; i < node->children.size();++i)
    {
        privatePrintNodesAt(node->children[i],k-1);
    }
}
template<typename T>
int GenericTree<T>::countLeafNodes()const
{
    return privateCountLeafNodes(root);
}
template<typename T>
int GenericTree<T>::privateCountLeafNodes(Node<T>* node)const
{
    if(node==nullptr)
        return 0;
    if(node->children.size()==0)
        return 1;
    int nodes = 0;
    for(int i = 0;i<node->children.size();++i)
    {
        nodes += privateCountLeafNodes(node->children[i]);
    }
    return nodes;
}
template<typename T>
void GenericTree<T>::preOrderTraversal()const
{
    std::cout<<"Preorder traversal\n";
    privatePreOrderTraversal(root);
    std::cout<<"\n";
}
template<typename T>
void GenericTree<T>::privatePreOrderTraversal(Node<T>* node)const
{
    if(node==nullptr)
        return;
    std::cout<<node->data<<"\t";
    for(int i = 0; i<node->children.size();++i)
        privatePreOrderTraversal(node->children[i]);
}
template<typename T>
void GenericTree<T>::postOrderTraversal()const
{
    std::cout<<"Post order Traversal \n";
    privatePostOrderTraversal(root);
    std::cout<<"\n";
}
template<typename T>
void GenericTree<T>::privatePostOrderTraversal(Node<T>* node)const
{
    if(node==nullptr)
        return;
    for(int i = 0;i<node->children.size();++i)
        privatePostOrderTraversal(node->children[i]);
    std::cout<<node->data<<"\t";
}
template<typename T>
void GenericTree<T>::deleteGenericTree(Node<T>* node)
{
    if(node==nullptr)
        return;
    for(int i = 0; i<node->children.size(); ++i)
        deleteGenericTree(node->children[i]);
    delete node;

}
template<typename T>
GenericTree<T>::~GenericTree()
{
    delete root;
}