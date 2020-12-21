#include<string>
#include<vector>
#include<iostream>


bool isPalindrome(std::string data)
{
    if(data.size()==0||data.size()==1)
        return true;
    if(data[0]!=data[data.size()-1])
        return false;
    data.erase(data.begin());
    data.erase(data.end()-1);
    return isPalindrome(data);
}

int main()
{
    std::string pali = "Anomaly";
    std::string stringPali = "markram";
    std::string stringPali2 = "SAAS";
    if(isPalindrome(pali))
        std::cout<<pali<<" is a palindrome \n";
    else
        std::cout<<pali<<" is not a palindrome \n";

    if(isPalindrome(stringPali))
        std::cout<<stringPali<<" is a palindrome\n";
    else
        std::cout<<stringPali<<" is not a palindrome \n";

    if(isPalindrome(stringPali2))
        std::cout<<stringPali2<<" is a palindrome\n";
    else
        std::cout<<stringPali2<<" is not a palindrome \n";

    
    return 0;
}