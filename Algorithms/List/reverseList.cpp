
#include <iostream>
#include <string>
template<class T>

struct Node
{
  T data;
  Node<T>* link;
  Node(T d){
    data = d;
    link = nullptr;
  }
};

template<class T>
Node<T>* reverse(Node<T> *head)
{
  Node<T> *previous = nullptr;
  Node<T> *current = head;
  Node<T> *next = nullptr;

  while(current!=nullptr)
    {
      next = current->link;
      current->link = previous;
      previous=current;
      current = next;
    }
  head = previous;
  return head;
}

template<class T>
Node<T>* recursive_reverse(Node<T>* head)
{
  if(head==nullptr|| head->link==nullptr)
    return head;
  Node<T>* temp = recursive_reverse(head->link);
  head->link->link = head;
  head->link=nullptr;
  return temp;
}


template<class T>
void print(Node<T>* head)
{
  Node<T>* temp = head;
  while(temp!=nullptr)
    {
      std::cout<<temp->data<<"\t";
      temp = temp->link;
    }
}
int main()
{
  Node<std::string>* list = new Node<std::string>("Joseph");
  list->link = new Node<std::string>("Thabo");
  list->link->link = new Node<std::string>("Mendy");
  list->link->link->link = new Node<std::string>("Robert");
  print(list);
  Node<std::string>* reversedList =  recursive_reverse(list);
  std::cout<<"\nThe list after calling the reverse function\n";
  print(reversedList);
  std::cout<<std::endl;
  return 0;
}
