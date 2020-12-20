#include<iostream>
#include<cmath>

//returns the geometric sum of 1/2^n from k=0 to k=n;
double gSum(int k)
{
    if(k==0)
        return 1;
    return 1/pow(2,k) + gSum(k-1);
}

int main()
{
    printf("%f\n",gSum(12));
    return 0;
}