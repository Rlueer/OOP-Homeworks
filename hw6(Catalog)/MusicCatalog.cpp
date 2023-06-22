#include "MusicCatalog.h"

    MusicCatalog::MusicCatalog(){}
    MusicCatalog::MusicCatalog(string file,string ofile){
        type="Music";
        of=ofile;
        write_to_output("Catalog Read: " + type + "\n", of); // Write catalog type to the output file
    read_write_data(file); // Read and write data from the input file
    read_command("commands.txt"); // Read and execute commands from the command file
    }
    MusicCatalog::~MusicCatalog(){}
    void MusicCatalog::read_write_data(string file){
        // Read data from the file and store it in a vector
        vector<string> a=Catalog::read_data_and_write_to_vector(file);
        if(a.size()==0){
            cout<<"No data\n";
            exit(1);// Exit the program if there is no data
        }
        write_to_output(to_string(a.size()/4)+" unique entries\n",of);// Write the number of unique entries to the output file

        for(int i=0;i<a.size();i=i+4){
            Music s(a[i],a[i+1],a[i+2],a[i+3]);// Create a Book object using the data from the vector
            data.push_back(s);// Add the Book object to the data vector
        }
    }
    void MusicCatalog::print_vector(){
        // Print the data stored in the Book objects in the data vector
        for(int i=0;i<data.size();i++){
            cout<<data[i].title<<" "<<data[i].artist<<" "<<data[i].year<<" "<<data[i].genre<<endl;
            
        }
    }
    string MusicCatalog::search(string str,string field){
        int a,index=-1;
        string temp="";

        for(int i=0;i<data.size();i++){
            if(field=="title" && data[i].title==str){
                index=i;// Store the index of the found item
            }
            else if(field=="artist" && data[i].artist==str){
                index=i;// Store the index of the found item
            }
            else if(field=="year" && data[i].year==str){
                index=i;// Store the index of the found item
            }
            else if(field=="genre" && data[i].genre==str){
                index=i;// Store the index of the found item
            }
        }
        if(index==-1){
            try{// Throw an exception if the item is not found
                throw runtime_error("Exception: command is wrong\n");
            }catch(const runtime_error& e){
                write_to_output(e.what(),of);// Write the exception message to the output file
            } 
        }
        else{
            temp+="\""+data[index].title+"\" \""+data[index].artist+"\" \""+
            data[index].year+"\" \" "+data[index].genre+"\" ";
        }
        write_to_output("Search \""+str+"\" in \""+field+"\"\n",of);// Write the search query to the output file
        write_to_output(temp + "\n", of); // Write the search result to the output file
        return temp;
    }
    string MusicCatalog::sort(string field){
        int a,index;
        string temp;
        vector <string> ddd;

        for(int i=0;i<data.size();i++){

            if(field=="title"){
                ddd.push_back(data[i].title);// Store the specified field data in a separate vector
            }
            else if(field=="artist"){
                ddd.push_back(data[i].artist);// Store the specified field data in a separate vector
            }
            else if(field=="year"){
                ddd.push_back(data[i].year);// Store the specified field data in a separate vector
            }
            else if(field=="genre"){
                ddd.push_back(data[i].genre);// Store the specified field data in a separate vector
            }
        }

        std::sort(ddd.begin(),ddd.end());// Sort the separate vector
        
        for(int i=0;i<data.size();i++){
            for(int j=0;j<data.size();j++){
            if(field=="title" && ddd[i]==data[j].title){
                index=j;// Find the index of the sorted item in the original data vector
            }
            else if(field=="artist" && ddd[i]==data[j].artist){
                index=j;// Find the index of the sorted item in the original data vector
            }
            else if(field=="year" && ddd[i]==data[j].year){
                index=j;// Find the index of the sorted item in the original data vector
            }
            else if(field=="genre" && ddd[i]==data[j].genre){
                index=j;// Find the index of the sorted item in the original data vector
            }
            }
        temp+="\""+data[index].title+"\" \""+data[index].artist+"\" \""+
        data[index].year+"\" \" "+data[index].genre+"\"\n";// Build the sorted string
        }
        return temp;
    }
    void MusicCatalog::read_command(string file){
        ifstream inputFile(file); // Open the file for reading
        vector <string> a1,a2,b1;
        string first,temp,tline;
    
    if (inputFile.is_open()) { // Check if the file is successfully opened
        string line;
        int i=0;int j=0;
        while (getline(inputFile, line)) { // Read each line of the file
            tline=line;
            first = line.substr(0, line.find("\"")-1); 
            line.erase(0, line.find("\"") + 1);

            if(first=="search"){
                try{    
                a1.push_back(line.substr(0, line.find("\" ")));
                line.erase(0, line.find("\" ") + 2);
                temp=line.substr(0, line.find(" \""));
                line.erase(0, line.find(" \"") + 2);
                a2.push_back(line.substr(0, line.find("\"")));
                
                if(temp!="in"){
                    throw runtime_error("Exception: command is wrong\n");
                }
                if(a2[i]=="title" || a2[i]=="artist" ||a2[i]=="year" ||a2[i]=="genre"){
                }
                else{
                    throw runtime_error("Exception: command is wrong\n");
                }
                search(a1[i],a2[i]);
                i++;
                }catch(const runtime_error& e){
                    write_to_output(e.what(),of);
                    write_to_output(tline+"\n",of);
                } 
            }
            else if(first=="sort"){
                b1.push_back(line.substr(0, line.find("\"")));

                try{
                    int flag=0;
                    for(int j=0;j<data.size();j++){
                        if(b1[0]=="title"||b1[0]=="artist"||b1[0]=="year"||b1[0]=="genre")flag=1;
                    }
                    if(flag==0){
                        throw runtime_error("Exception: command is wrong\n");
                    }
                    write_to_output("sort \""+b1[0]+"\"\n",of);// Write the sorted result to the output file
                    write_to_output(sort(b1[0]),of);// Write the sorted result to the output file
                }catch(const runtime_error& e){
                    write_to_output(e.what(),of);// Write the sorted result to the output file
                    write_to_output("sort \""+b1[0]+"\"\n",of);// Write the sorted result to the output file
                }    
                j++; 
            }
            else{
                try{// Throw an exception if the command is invalid
                    throw runtime_error("Exception: command is wrong\n");
                }catch(const runtime_error& e){
                    write_to_output(e.what(),of);// Write the exception message to the output file
                    write_to_output(tline,of);// Write the erroneous command to the output file
                }   
            }
        }
        inputFile.close(); // Close the file
    } 
    else 
        cout << "Failed to open the file." << endl;
    }