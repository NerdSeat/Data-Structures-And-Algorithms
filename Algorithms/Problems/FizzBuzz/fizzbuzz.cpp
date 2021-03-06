#include "Range.hpp"

int main()
{
  int Fizz = 0,Buzz=0,FizzBuzz = 0;

  for(const auto i: Range(1,100))
    {
      if(i%15==0)
	FizzBuzz++;
      else if (i%5==0)
	Buzz++;
      else if (i%3==0)
	Fizz++;
    }
  std::cout<<"Fizz: "<<Fizz<<std::endl;
  std::cout<<"Buzz: "<<Buzz<<std::endl;
  std::cout<<"Fizzbuzz: "<<FizzBuzz<<std::endl;
  return 0;
}
