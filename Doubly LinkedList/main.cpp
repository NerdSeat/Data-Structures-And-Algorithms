#include "doublyLinkedList.cpp"
#include "book.h"
#include <iostream>
int main()
{   doublyLinkedList<book> library;
    book Maths("Transcendental calculus","Stewart",2003);
    book Economics("Wealth of Nations","Adam Smith",1776);
    book History("Tides of War","Steven Presfield",2000);
    book Physics("Relitivity:Special and General Theory","Albert Einstein",1916);
    book Fiction("Adventures of Oliver Twist","Charles Dickens",1839);
    book CompSci("Computer Organisation and Architecture","William Stallings",2013);
    book Geography("History of Techtonation","Joseph Bliss",2020);
    library.insert(Maths);
    library.insert(Physics);
    library.insert(Economics);
    library.insert(Fiction);
    library.insert(CompSci);
    library.insert(Geography);
    library.insert(History);
    library.print();
    //library.printReverse();
    library.sort();
    library.print();
    //library.remove(Physics);
   // library.remove(CompSci);
   // library.print();
    return 0;
}