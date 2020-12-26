/*
    Write a function that takes in a string and print the permutations of
    the given string.
*/

#include<iostream>
#include<string>

void swap(char & a, char &b)
{
    char temp = a;
    a=b;
    b=temp;
}

void permutations(std::string val, int i=0)
{
    if(val[i]=='\0')
    {
        std::cout<<val<<std::endl;
        return;
    }
    //fix the first letter and call the recursion on the remaining letters
    for(int j = i;val[j]!='\0';j++)
    {
        swap(val[j],val[i]);
        permutations(val,i+1);
        swap(val[j],val[i]);
    }
}

int main()
{
    std::string vals = "cabc";
    permutations(vals);
}