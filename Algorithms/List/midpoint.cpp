#include<vector>
#include<iostream>
#include<string>

template<typename T>
struct Node
{
    T data;
    Node<T>* link = nullptr;
    Node(T d){this->data=d;}
};

template<typename T>
Node<T>* midpoint(Node<T>* node)
{
    Node<T>* slow = node;
    Node<T>* fast = node->link;
    while (slow!=nullptr)
    {
        if(fast==nullptr)
            return slow;
        else if(fast->link==nullptr)
            return slow->link;
        slow=slow->link;
        fast = fast->link->link;
    }
    return nullptr;
}

template<typename T>
void print(Node<T>* node)
{
    Node<T>* temp = node;
    while(temp!=nullptr)
    {
        std::cout<<temp->data<<"->";
        temp=temp->link;
    }
    std::cout<<"nullptr\n";
}

int main()
{
    Node<std::string>* list = new Node<std::string>("Joseph");
    list->link = new Node<std::string>("Thabo");
    list->link->link = new Node<std::string>("Mendy");
    list->link->link->link = new Node<std::string>("Robert");
    list->link->link->link->link = new Node<std::string>("Nicky");
    list->link->link->link->link->link = new Node<std::string>("Dave");
    print(list);
    Node<std::string>* temp = midpoint(list);
    print(temp);
   
    return 0;
}