#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;
// Declaration of the Book class
class Movie{
    // Allowing BookCatalog class to access private members of Book
    friend class MovieCatalog;
    // Private member variables
    private:
    string title,director,year,genre,starring;  
    // Public member functions
    public:
    // Default constructor
    Movie(){}
    // Parameterized constructor
    Movie(string t,string d,string y,string g,string s)
    :title(t),director(d),year(y),genre(g),starring(s){}
};
#endif