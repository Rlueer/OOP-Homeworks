#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
using namespace std;
// Declaration of the Book class
class Music{
    // Allowing BookCatalog class to access private members of Book
    friend class MusicCatalog;
    // Private member variables
    private:
    string title,artist,year,genre;
    // Public member functions
    public:
    // Default constructor
    Music(){}
    // Parameterized constructor
    Music(string t,string a,string y,string g)
    :title(t),artist(a),year(y),genre(g){}
};

#endif