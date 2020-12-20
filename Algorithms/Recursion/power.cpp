#include<iostream>

int pow(int x,int n)
{
    if(x==0)
        return 0;
    if(n==0||x==1)
        return 1;
    if(n==1)
        return x;
    return x*pow(x,n-1);
}

int main()
{
    int x = 2,n=8;
    std::cout<<pow(x,n)<<std::endl;
    return 0;
}
