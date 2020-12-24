#include<iostream>
#include<string>
#include<vector>

void subStrings(std::string input,const std::string& output)
{
    if(input.length()==0)
    {
        std::cout<<output<<std::endl;
        return;
    }
    subStrings(input.substr(1),output);
    subStrings(input.substr(1),output+input[0]);
}

int main()
{
    std::string input = "abc", output="";
    subStrings(input,output);
  //  std::cout<<output<<std::endl;

}