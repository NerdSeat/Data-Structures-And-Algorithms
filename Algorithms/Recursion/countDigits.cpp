#include<iostream>

int count(long long n)
{
    if(n/10==0)
        return 1;
    return 1+count(n/10);
}
int main()
{
    std::cout<<count(129032)<<std::endl;
    return 0;
}