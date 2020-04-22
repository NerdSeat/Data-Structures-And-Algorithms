/*This class is just to demonstrate the functionality of the dynamic
array created earlier*/
#include "array.h"
#include<string>

class book
{
public:
    book();
    book(const std::string &t,const std::string &a,const int year);
    int getYear()const;
    std::string getTitle()const;
    std::string getAuthor()const;
    void setTitle(const std::string t);
    void setAuthor(const std::string a);
    void setYear(int y);
    friend std::ostream& operator <<(std::ostream &print,const book& b);
    friend bool operator>(const book& b1,const book& b2);
    ~book();
private:
    std::string author;
    std::string title;
    int year;
};


