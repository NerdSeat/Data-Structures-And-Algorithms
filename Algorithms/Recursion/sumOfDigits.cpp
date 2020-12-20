#include<iostream>

int sumOfDig(long long n)
{
    if(n==0)
        return 0;
    int lastDig = n%10;
    return lastDig + sumOfDig(n/10);
}

int main()
{
    long long num = 89346578465;
    std::cout<<sumOfDig(num)<<std::endl;
    return 0;

}