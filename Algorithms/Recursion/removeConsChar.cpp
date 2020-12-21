#include<string>
#include<vector>
#include<iostream>

//Remove consecutive characters from a string
void remove(char data[])
{
    if(data[0]=='\0')
        return;
    if(data[0]==data[1])
    {
        for(int i=0;data[i]!='\0';i++)
        {
            data[i]=data[i+1];
        }
        remove(data);
    }
    else
    {
        remove(data+1);
    }
}
int main()
{
    char data[] ="aabddbccdabdc";
    std::cout<<data<<std::endl;
    remove(data);
    std::cout<<data<<std::endl;
}