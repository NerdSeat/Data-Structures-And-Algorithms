#include <iostream>
#include <string>
/*
write fizz when a value is divisible by 3, buzz when a value is divisible by 5
and fizzbuzz when a value is divisible by both 3 and 5
 */

std::string divisor(int number)
{
  std::string val1 = "buzz";
  std::string val = "fizz";
  std::string valval1 = "fizzbuzz";

   if (number%15==0)
     return valval1;
   else  if(number%5==0)
     return val1;
   else if (number%3==0)
     return val;
   else
     return std::to_string(number);
}


int main()
{
  int number = 50;
  for(int i =1;i<=number;i++)
    {
      std::cout<<divisor(i)<<std::endl;
    }
  
  return 0;
}

