#include<iostream>

int zeroes(long long n)
{
    if(n==0)
        return 0;
    int zero = n%10;
    int num = n/10;
    if(zero==0&&num!=0)
        return 1+zeroes(num);
    return zeroes(num);
}

int main()
{
    std::cout<<zeroes(103204095)<<std::endl;
    return 0;
}