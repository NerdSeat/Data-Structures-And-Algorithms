/* Convert a given string to integer using recursion*/

#include<iostream>
#include<string>

int toInt(std::string num)
{
    if(num.size()==0)
        return 0;
    if(num.size()==1)
        return num[0]-'0';
/* the call stack for "123893" will look like 
toInt("12389")*10 + 3 -> 123890+3 =123893 -> final return value
toInt("1238")*10 + 9 -> 12380+9 = 12389 ^
toInt("123")*10 + 8 -> 1230+8 = 1238 ^
toInt("12")*10 + 3 -> 120+3 = 123 ^
toInt("1")*10 + 2 ->10+2 = 12 ^
*/
    return toInt(num.substr(0,num.length()-1))*10 + 
            num[num.length()-1]-'0';
}
int main()
{
    std::string number = "123893";
    std::cout<<toInt(number)<<std::endl;
   return 0;
}