#include "Catalog.h"


Catalog::Catalog() {
    // Default constructor implementation
}

Catalog::Catalog(string file) {
    // Parameterized constructor implementation
}

Catalog::~Catalog() {
    // Destructor implementation
}
string Catalog::getType(string file) {
    ifstream input(file); // Open the file for reading
    getline(input, type); // Read the first line (type of catalog) from the file
    input.close(); // Close the file
    return type; // Return the catalog type
}

vector<string> Catalog::read_data_and_write_to_vector(string dfile){
    ifstream inputFile(dfile); // Open the file for reading
    string d1,d2,d3,d4,d5,delimiter;
    vector<string> da;  // Vector to store the catalog data
    
    if (inputFile.is_open()) { // Check if the file is successfully opened
        string line,temp;
        int i=0,counter=0;   // Variables for finding the type of catalog

        while (getline(inputFile, line)) { // Read each line of the file
            if(i==0){
                type=line;  // Set the type of catalog
            }
            else{
                temp = line; // Save a copy of the line for error handling
                counter = std::count(line.begin(), line.end(), '\"'); // Count the number of double quotes in the line
                delimiter = "\" \""; // Set the delimiter for splitting the line
                
                // Extract the fields from the line based on the catalog type
                d1=line.substr(1, line.find(delimiter)-1); 
                line.erase(0, line.find(delimiter) + delimiter.length());  
                d2=line.substr(0,line.find(delimiter));
                line.erase(0, line.find(delimiter) + delimiter.length());  
                d3=line.substr(0,line.find(delimiter));
                line.erase(0, line.find(delimiter) + delimiter.length());  

                if(type=="movie"){
                    try{
                        if(counter!=10){
                            throw runtime_error("Exception: missing field\n");
                        }
                        d4=line.substr(0,line.find(delimiter));
                        line.erase(0, line.find("\"") + delimiter.length()); 
                        d5=line.substr(0,line.find("\""));
                        try{
                            for(int i=0;i<da.size();i=i+5){
                                if(da[i]==d1){
                                    // Throw an exception if a duplicate entry is found
                                    throw runtime_error("Exception: duplicate entry\n");
                                }
                            }
                            da.push_back(d1);
                            da.push_back(d2);
                            da.push_back(d3);
                            da.push_back(d4);
                            da.push_back(d5);

                        }catch(const runtime_error& e){
                            write_to_output(e.what(),"output.txt"); // Write the exception message to an output file
                            write_to_output(temp+"\n","output.txt");    // Write the original line to the output file
                        }
    
                    }catch(const runtime_error& e) {
                        write_to_output(e.what(),"output.txt"); // Write the exception message to an output file
                        write_to_output(temp+"\n","output.txt");// Write the original line to the output file
                    }       
                }
                else{
                    try{
                        if(counter!=8){
                            // Throw an exception if a field is missing
                            throw runtime_error("Exception: missing field\n");
                        }
                        d4=line.substr(0,line.find("\""));
                        try{
                            for(int i=0;i<da.size();i=i+5){
                                if(da[i]==d1){
                                    // Throw an exception if a field is missing
                                    throw runtime_error("Exception: duplicate entry\n");
                                }
                            }
                            da.push_back(d1);
                            da.push_back(d2);
                            da.push_back(d3);
                            da.push_back(d4);
                        }catch(const runtime_error& e){
                            write_to_output(e.what(),"output.txt"); // Write the exception message to an output file
                            write_to_output(temp+"\n","output.txt");// Write the original line to the output file
                        }
                        
                    }catch(const runtime_error& e) {
                        write_to_output(e.what(),"output.txt"); // Write the exception message to an output file
                        write_to_output(temp+"\n","output.txt");// Write the original line to the output file
                    }
                       
                }
            }
        
            i++;    
        }
        inputFile.close(); // Close the file
    } 
    else cout << "Failed to open the file." << endl;
        
    return da;
}

void Catalog::write_to_output(string line,string ofile){ 
    ofstream outputFile(ofile,std::ios::app);   // Open the file for appending
    if (outputFile.is_open()) { // Check if the file is successfully opened
        outputFile<<line;   // Write the line to the output file
    }
    else{
        cout<<"Error couldnt open "<<ofile<<endl;
    }
    outputFile.close();
}
