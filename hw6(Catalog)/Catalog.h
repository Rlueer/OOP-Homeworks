#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm> // For std::sort
#include <sstream>

using namespace std;

class Catalog{
    protected:
        string type; // Type of catalog
    
    public:
        // Default constructor
        Catalog();
        
        // Parameterized constructor
        Catalog(string file);
        
        // Destructor
        ~Catalog();
        
        // Read data from a file and write to a vector
        vector<string> read_data_and_write_to_vector(string dfile);
        
        // Get the type of catalog from a file
        string getType(string file);
        
        // Read commands from a file
        void read_command(string cfile);
        
        // Write a line to an output file
        void write_to_output(string line, string ofile);
};
#endif