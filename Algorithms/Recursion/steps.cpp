/*
write a function to that returns the number of ways to climb 
a staircase of size n steps.
The function will take n as an input argument and return the number of ways
to climb the staircase

one can take a jump of 1,2 or 3 steps at a time.
*/

#include<iostream>

int countWays(int n)
{
    if(n<=2)
        return n;
    if(n==3)
        return 4;
    return countWays(n-1) + countWays(n-2) + countWays(n-3);
    
}
int main()
{

    std::cout<<countWays(5)<<std::endl;
    return 0;
}