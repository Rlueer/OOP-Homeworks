#ifndef MUSICCATALOG_H
#define MUSICCATALOG_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm> // For std::sort
#include <sstream>
#include "Catalog.h"
#include "Music.h"

using namespace std;

class MusicCatalog : public Catalog{
    private:
        string type; // Type of catalog
        string of;   // Description of catalog
        vector<Music> data; // Vector to store Music objects

    public:
        // Default constructor
        MusicCatalog();

        // Parameterized constructor
        MusicCatalog(string file, string ofile);

        // Destructor
        ~MusicCatalog();

        // Read and write data from a file
        void read_write_data(string file);

        // Print the contents of the vector
        void print_vector();

        // Search for a specific string in a specified field
        string search(string str, string field);

        // Sort the vector based on a specified field
        string sort(string field);

        // Read commands from a file
        void read_command(string file);

};
#endif