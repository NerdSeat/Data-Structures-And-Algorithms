#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}
template<typename T>
Node<T>* BinaryTree<T>::newNode(T d)
{
    Node<T>* node = new Node<T>(d);
    return node;
}
template<typename T>
void BinaryTree<T>::insert()
{
    //root = privateInsert();
    iterativeInsert();
}
template<typename T>
Node<T>* BinaryTree<T>::privateInsert()
{
    std::cout<<"Enter node data: ";
    T nodeData;
    std::cin>> nodeData;
    if(nodeData == -1)
        return nullptr;
    Node<T>* node = newNode(nodeData);
    node->left = privateInsert();
    node->right = privateInsert();
    return node;
}
template<typename T>
void BinaryTree<T>::iterativeInsert()
{
    std::cout<<"Enter the root node: ";
    T rootData;
    std::cin>>rootData;
    std::queue<Node<T>*> queueInsert;
    root = newNode(rootData);
    queueInsert.push(root);
    while(!queueInsert.empty())
    {
        T leftData , rightData;
        Node<T>* temp = queueInsert.front();
        queueInsert.pop();
        std::cout<<"Enter the left Node for "<<temp->data<<" -1 to make it a leaf node: ";
        std::cin>>leftData;
        std::cout<<"Enter the right Node for "<<temp->data<<" -1 to make it a leaf node: ";
        std::cin>>rightData;
        Node<T>* leftNode = nullptr;
        Node<T>* rightNode = nullptr;
        if(leftData!=-1)
        {
            leftNode = newNode(leftData);
            queueInsert.push(leftNode);
        }
        if(rightData!=-1)
        {
            rightNode = newNode(rightData);
            queueInsert.push(rightNode);
        }
        temp->left = leftNode;
        temp->right = rightNode;
    }
}
template<typename T>
void BinaryTree<T>::print()const
{
    //privatePrint(root);

    levelOrderPrint();
    preorderTraversal();
    inorderTraversal();
    postOrderTraversal();
}
template<typename T>
void BinaryTree<T>::privatePrint(Node<T>* node)const
{
    if(node == nullptr)
        return;
    std::cout<<node->data<<": ";
    if(node->left!=nullptr)
        std::cout<<"L "<<node->left->data<<"\t";
    if(node->right!=nullptr)
        std::cout<<"R "<<node->right->data<<"\t";
    std::cout<<"\n";
    privatePrint(node->left);
    privatePrint(node->right);
}
template<typename T>
void BinaryTree<T>::levelOrderPrint()const
{
    std::cout<<"Level order traversal\n";
    std::queue<Node<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        Node<T>* temp = q.front();
        std::cout<<temp->data<<"\t";
        q.pop();
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    std::cout<<"\n";
}
template<typename T>
unsigned int BinaryTree<T>::size()const
{
    return privateCountNodes(root);
}

template<typename T>
unsigned int BinaryTree<T>::privateCountNodes(Node<T>* node)const
{
    if(node==nullptr)
        return 0;
    return 1 + privateCountNodes(node->left) + privateCountNodes(node->right);
}

template<typename T>
void BinaryTree<T>::inorderTraversal()const
{
    std::cout<<"Inorder traversal using recursion\n";
    privateInorderTraversal(root);
    std::cout<<"\n";
    std::cout<<"Inorder traversal iterative solution\n";
    privateInorderTraversalIterative();
    std::cout<<"\n";
}
template<typename T>
void BinaryTree<T>::privateInorderTraversal(Node<T>* node)const
{
    if(node==nullptr)
        return;
    privateInorderTraversal(node->left);
    std::cout<<node->data<<"\t";
    privateInorderTraversal(node->right);
}
template<typename T>
void BinaryTree<T>::privateInorderTraversalIterative()const
{
    Node<T>* curr = root;
    std::stack<Node<T>*> stack;
    while(curr!=nullptr ||!stack.empty() )
    {
        while(curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        std::cout<<curr->data<<"\t";
        stack.pop();
        curr = curr->right;
    }
    std::cout<<"\n";
}
template<typename T>
void BinaryTree<T>::preorderTraversal()const
{
    std::cout<<"Preorder Traversal recursive solution\n";
    privatePreorderTraversal(root);
    std::cout<<"\n";
    std::cout<<"Preorder Traversal iterative solution\n";
    privatePreorderTraversalIterative();
    std::cout<<"\n";
}
template<typename T>
void BinaryTree<T>::privatePreorderTraversal(Node<T>* node)const
{
    if(node==nullptr)
        return;
    std::cout<<node->data<<"\t";
    privatePreorderTraversal(node->left);
    privatePreorderTraversal(node->right);
}
template<typename T>
void BinaryTree<T>::privatePreorderTraversalIterative()const
{
    Node<T>* node = root;
    std::stack<Node<T>*> stack;
    while (node!=nullptr || !stack.empty())
    {
        while(node!=nullptr)
        {
            std::cout<<node->data<<"\t";
            stack.push(node->right);
            node = node->left;
        }
        node = stack.top();
        stack.pop();
    }

}
template<typename T>
void BinaryTree<T>::postOrderTraversal()const
{
    std::cout<<"Post order traversal, recursive solution\n";
    privatePostOrderTraversal(root);
    std::cout<<"\n";
}
template<typename T>
void BinaryTree<T>::privatePostOrderTraversal(Node<T>* node)const
{
    if(node==nullptr)
        return;
    privatePostOrderTraversal(node->left);
    privatePostOrderTraversal(node->right);
    std::cout<<node->data<<"\t";

}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
}
template<typename T>
int BinaryTree<T>::height()const
{
    return privateHeight(root);
}
template<typename T>
int BinaryTree<T>::privateHeight(Node<T>* node)const
{
    if(node==nullptr)
        return 0;
    int left = privateHeight(node->left);
    int right = privateHeight(node->right);
    return 1 + std::max(left,right);
}
template<typename T>
bool BinaryTree<T>::find(T data)const
{
    return privateFind(root,data);
}
template<typename T>
bool BinaryTree<T>::privateFind(Node<T>* node,T data)const
{
    if(node==nullptr)
        return false;
    if(node->data==data)
        return true;
    return (privateFind(node->right,data)||privateFind(node->left,data));

}
