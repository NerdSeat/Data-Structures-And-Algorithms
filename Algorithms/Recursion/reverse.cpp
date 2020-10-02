#include <iostream>
#include <string>
#include <vector>

void reverse(std::string &word,int k)
{
  
  static int i=0;
  if(k==word.length())
    {
      std::cout<<std::endl;
      return;
     }
  std::cout<<i<<"\t";
  reverse(word,k+1);
 if(i<=k)
   std::swap(word[i++], word[k]);


}

int main()
{
  std::vector<std::string> words;
  words.push_back("Comment");
  words.push_back("Statement");
  words.push_back("Results");
  for(auto x:words)
   {
    std::cout<<std::endl;
    reverse(x,0);
    std::cout<<x;
    }
  std::cout<<std::endl;
}
