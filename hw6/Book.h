#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;
// Declaration of the Book class
class Book{
    // Allowing BookCatalog class to access private members of Book
    friend class BookCatalog;
    // Private member variables
    private:
    string title,authors,year,tags;
    // Public member functions
    public:
    // Default constructor
    Book(){}
    // Parameterized constructor
    Book(string t,string a,string y,string ta)
    :title(t),authors(a),year(y),tags(ta){}
};
#endif