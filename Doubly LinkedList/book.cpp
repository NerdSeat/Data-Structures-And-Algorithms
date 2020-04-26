#include "book.h"

book::book()
{
    title = "";
    author ="";
    year =0;
}
book::book(const std::string &t,const std::string &a,int y)
:title(t),author(a),year(y){}
inline std::string book::getAuthor()const
{return author;}
inline std::string book::getTitle()const
{return title;}
inline int book::getYear()const
{return year;}

std::ostream& operator <<(std::ostream &print,const book& b)
{
    std::cout<<b.title<<"\t"<<b.author<<"\t"<<b.year<<std::endl;
    return print;
}
inline void book::setAuthor(std::string a)
{author = a;}
inline void book::setTitle(std::string t)
{title=t;}
inline void book::setYear(int y)
{year=y;}
inline bool operator>(const book& b1,const book& b2)
{
    return b1.title>b2.title;
}
inline bool operator==(const book& b1,const book& b2)
{
    return b1.title==b2.title;
}
book::~book()
{}