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