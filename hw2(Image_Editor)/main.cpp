#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Pixel {
    int R;  // RED 
    int G;  // GREEN
    int B;  // BLUE
};

class Image_editor{
    private:
    string file_name; // the name of the PPM file being edited
    string p_type, height, width, max_int; // metadata of the PPM file
    vector<vector<Pixel>> pixels; // the 2D vector of pixels in the PPM image

    public:
    Image_editor(){ // default constructor
        menu(); // display the main menu
    }
    Image_editor& operator=(const Image_editor& other){ // assignment operator overloading
        if (this != &other) {   // check for self-assignment
        this->file_name=other.file_name;
        this->p_type=other.p_type;
        this->height=other.height;
        this->width=other.width;
        this->max_int=other.max_int;
        this->pixels=other.pixels;
        }
        return *this;
    }
    Image_editor(const Image_editor& other) {   // copy constructor
        file_name = other.file_name;
        p_type = other.p_type;
        height = other.height;
        width = other.width;
        max_int = other.max_int;
        pixels = other.pixels;
    }
    ~Image_editor() {   // destructor
    // No dynamic memory allocation in this class, so nothing to delete
    }

    void read_ppm_file(); // reads a PPM file and stores the data in the class
    void menu(); // displays the main menu of options for the user
    void convert_grayscale(); // converts the image to grayscale
    void save_ppm_file() const; // saves the edited image to a new PPM file
    bool float_checker(const string& str) const; // checks if a string can be converted to a float

};

/**
 * This function checks whether a given string represents a valid floating-point number
 * between 0.0 (inclusive) and 1.0 (exclusive).
 * 
 * @param str the string to be checked
 * @return true if the string represents a valid float between 0.0 and 1.0, false otherwise
 */
bool Image_editor::float_checker(const string& str) const{
    bool has_decimal = false;   // flag to track if a decimal point has been encountered
    bool has_digit = false;     // flag to track if at least one digit has been encountered

    // iterate through each character in the string
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        
        if (c == '.'){  // Check for decimal point
            if (has_decimal) return false;  
            has_decimal = true;
        }
        else if (c >= '0' && c <= '9'){    // Check for digit
            has_digit = true;
        }
        else return false;  // Invalid character
    }

    // If a valid float string has been encountered, check that it is between 0.0 and 1.0 (exclusive)
    if(has_digit==true &&(stof(str)>=1.0 || stof(str)<0.0)) return false;
    else return has_digit;
    // if the string has at least one digit, return true; otherwise, return false

}


void Image_editor::menu(){
    
    while(1){

    int choice,choice_2,choice_3,flag=0;
    cout<<"Main Menu\n"<<"0 - Exit\n"<<"1 - Open An Image(D)\n"<<"2 - Save Image Data(D)\n"<<"3 - Scripts(D)\n";
    cin>>choice;

    switch (choice)
    {
    case 0:    // Exit the program
        exit(0);
        break;
    case 1:     // Open an image file
        while(flag==0)
        {
        cout<<"OPEN AN IMAGE MENU\n"<<"0 - UP\n"<<"1 - Enter The Name Of The Image File\n";
        cin>>choice_2;
        switch (choice_2)
        {
        case 0:     // Go back to the main menu
            flag=1; 
            break;
        case 1: // Enter The Name Of The Image File
            read_ppm_file();
            break;
        }
        }
        break;
    case 2: // Save the image data to a file
        while(flag==0)
        {
        cout<<"SAVE IMAGE DATA MENU\n";
        cout<<"0 - UP\n"<<"1 - Enter A File Name\n";
        cin>>choice_2;
        switch (choice_2)
        {
        case 0: // Go back to the main menu
            flag=1;
            break;
        case 1: // Read the name of the output file from the console and save the image data to it
            save_ppm_file();
            break;
        }
        }
        break;
    case 3: // Execute a script
        while(flag==0)
        {
        int flag2=0;
        cout<<"SCRIPTS MENU\n";
        cout<<"0 - UP\n"<<"1 - Convert To Grayscale(D)\n";
        cin>>choice_2;
        switch (choice_2)
        {
        case 0: // Go back to the main menu
            flag=1;
            break;
        case 1: 
            while(flag2==0)
            {
            cout<<"CONVERT TO GRAYSCALE MENU\n"; 
            cout<<"0 - UP\n"<<"1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
            cin>>choice_3;
            switch (choice_3)
            {
            case 0: // Go back to the main menu
                flag2=1;
                break;
            case 1:  //Enter Coefficients For RED GREEN And BLUE Channels.
                convert_grayscale();
                break;
            }
            }
            break;
        }
        }
        break;

    }
    }

}
// This function reads in a PPM image file and stores its pixel data in a 2D vector of Pixels.
void Image_editor::read_ppm_file(){
    // Clear any existing pixel data from the vector.
    if(pixels.size()>0){ pixels.clear();}
    // Prompt the user for the filename and open the file for reading.
    string file_name;
    cin>>file_name;
    ifstream image;
    image.open(file_name);
     // If the file is successfully opened, read in the image metadata and pixel data.
    if(image.is_open()){
        image>>p_type>>width>>height>>max_int;
        vector<Pixel> a;
        // Read in the pixel data line by line, row by row.
        for (int i = 0; i<stoi(height); i++) {
            for (int j = 0; j<stoi(width); j++) {
            Pixel pixel;
            image >> pixel.R >> pixel.G >> pixel.B;
            a.push_back(pixel);
            }
        // Once a row of pixels has been read, add it to the 2D vector of Pixels.
        pixels.push_back(a);
        }
    }
    // Close the input file.
    image.close();
}
// This function converts an image to grayscale using coefficients for each color channel.
void Image_editor::convert_grayscale(){
    int flag=0;
    string R,G,B;
    float c_r,c_g,c_b;

    // Prompt the user to enter coefficients for each color channel and validate the input.
    do{
        // If this is not the first iteration of the loop, prompt the user to re-enter the coefficients.
        if(flag>0){cout<<"Please re_enter the coefficents\n";}
        cin>>R>>G>>B;
        flag++;
        

    }while(float_checker(R)==false ||float_checker(G)==false ||float_checker(B)==false);

    // Convert the string coefficients to floats.
    c_r=stof(R); c_g=stof(G); c_b=stof(B);

    for(int i=0;i<pixels.size();i++){
        int j=0;
        if(i!=0){j=pixels[i-1].size();}
        for(j;j<pixels[i].size();j++){
            // Calculate the new grayscale value for the pixel using the specified coefficients.
            pixels[i][j].R=c_r*pixels[i][j].R+c_g*pixels[i][j].G+c_b*pixels[i][j].B;
            // If the new grayscale value exceeds 254 (the maximum value for a pixel component), set it to 255.
            if(pixels[i][j].R>254)pixels[i][j].R=255;
             // Set the G and B components of the pixel to the new grayscale value.
            pixels[i][j].G=pixels[i][j].R;
            pixels[i][j].B=pixels[i][j].R;
        }   
    }
}

// This function saves the current state of the image to a PPM file.
void Image_editor::save_ppm_file()const{
    string ppm_file;
    cin>>ppm_file;
    // Open the output file stream and write the header information.
    ofstream image;
    image.open(ppm_file);
    if(image.is_open()){
        image<<p_type<<"\n" <<width<<" "<<height<<"\n" <<max_int<<"\n";
         // Loop through each row of the image and write the pixel data to the file.
        for(int i=0;i<pixels.size();i++){
            int j=0;
            if(i!=0){j=pixels[i-1].size();}
                // For subsequent rows, write each pixel component separated by a space, starting from the last column of the previous row.
                for(j;j<pixels[i].size();j++){
                image<<pixels[i][j].R<<" "<<pixels[i][j].G<<" "<<pixels[i][j].B<<" ";
                }
            // Write a newline character to start a new row.
            image<<"\n";
        }
    }
    // Close the output file stream.
    image.close();
}

int main(int argc, char** argv){
    
    Image_editor x;

    return 1;
}