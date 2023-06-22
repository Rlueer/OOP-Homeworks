#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm> // For std::sort
#include <sstream>

#include "MusicCatalog.h"
#include "BookCatalog.h"
#include "MovieCatalog.h"
using namespace std;

class Catalog;
class Music;
class Book;
class Movie;
class BookCatalog;
class MovieCatalog;
class MusicCatalog;

bool isWordPresent(string sentence, string word)
{
    // To break the sentence in words
    stringstream s(sentence);
 
    // To temporarily store each individual word
    string temp;
 
    while (s >> temp) {
 
        // Comparing the current word
        // with the word to be searched
        if (temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}

int main(){
    // Open the file for reading
    ifstream inputFile("data.txt");
    string line;

    // Check if the file is successfully opened
    if(inputFile.is_open()){
        // Read the first line of the file
        getline(inputFile, line); 
    } 
    else {
        // Display an error message if the file couldn't be found
        cout<<"Could not find file\n";
    }

    // Check the value of the first line and create an appropriate catalog object
    if(line == "book")
        BookCatalog("data.txt", "output.txt"); // Create a BookCatalog object
    else if(line == "music")
        MusicCatalog("data.txt", "output.txt"); // Create a MusicCatalog object
    else if(line == "movie")
        MovieCatalog("data.txt", "output.txt"); // Create a MovieCatalog object
    
    // Print "done" to indicate the completion of the program

    // Return 0 to indicate successful execution of the program
    return 0;
}