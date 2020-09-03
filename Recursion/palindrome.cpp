#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
bool isPalindrome(std::string str)
{
    bool palindrome = false;
    //en empty string or a string of length one is a palindrome
    if (str.length() <= 1)
        return true;
    if (str.front() == str.back())
        palindrome = isPalindrome(str.substr(1, str.length() - 2));
    return palindrome;
}

int main()
{
    std::vector<std::string> palindromes = {"deed", "markram", "tut tut","11011","0021200","213132","pulslup"};
    for (auto x : palindromes)
    {
        if (isPalindrome(x))
            std::cout << x << " is a palindrome\n";
        else
            std::cout << x << " is not a palindrome\n";
    }
    return 0;
}