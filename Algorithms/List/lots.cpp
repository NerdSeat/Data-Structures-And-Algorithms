/*You are given a list, L, and another list, P, containing integers sorted in ascending
order. The operation printLots(L,P) will print the elements in L that are in positions
specified by P. For instance, if P = 1, 3, 4, 6, the elements in positions 1, 3, 4, and 6
in L are printed. Write the procedure printLots(L,P). You may use only the public
STL container operations. What is the running time of your procedure?
*/

#include<iostream>
#include<list>
#include<string>
template<typename T>
void printLots(std::list<T> L,std::list<int> P)
{
  int index;
  for(auto x =P.begin();x!=P.end();x++)
    {
      index = *x;
      auto it = L.begin();
      std::cout<<*(next(it,index))<<"\t";
    }
  std::cout<<std::endl;
}

int main()
{
  std::list<std::string> names;
  names.push_back("Joseph");
  names.push_back("Tracy");
  names.push_back("Anne");
  names.push_back("Matt");
  names.push_back("Dave");
  names.push_back("Thando");
  std::list<int> lot;
  lot.push_back(1);
  lot.push_back(3);
  lot.push_back(5);
  printLots(names, lot);
  return 0;
}
