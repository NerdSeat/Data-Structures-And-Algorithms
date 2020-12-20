#include <iostream>

int mult(int m,int n)
{
    if(n==0||m==0)
        return 0;
    if(n==1)
        return m;
    return m + mult(m,n-1);
}

int main()
{
    int m=8,n=7;
    std::cout<<mult(m,n)<<std::endl;
    return 0;
}