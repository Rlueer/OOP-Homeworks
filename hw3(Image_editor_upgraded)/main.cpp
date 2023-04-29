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

class ppmImage{
    private:
    string file_name; // the name of the PPM file being edited
    string p_type, f_height, f_width, max_int; // metadata of the PPM file
    vector<vector<Pixel>> ppm_data; // the 2D vector of ppm_data in the PPM image

    public:
    ppmImage(){ // default constructor
        p_type="P3";
        f_width="0";
        f_height="0";
        width=0;
        height=0;
        max_int="255";
    }
    ppmImage& operator=(const ppmImage& other){ // assignment operator overloading
        if (this != &other) {   // check for self-assignment
        this->file_name=other.file_name;
        this->p_type=other.p_type;
        this->f_height=other.f_height;
        this->f_width=other.f_width;
        this->max_int=other.max_int;
        this->ppm_data=other.ppm_data;
        height=stoi(f_height);
        width=stoi(f_width);
        }
        return *this;
    }
    ppmImage(const ppmImage& other) {   // copy constructor
        file_name = other.file_name;
        p_type = other.p_type;
        f_height = other.f_height;
        f_width = other.f_width;
        max_int = other.max_int;
        ppm_data = other.ppm_data;
        height=stoi(f_height);
        width=stoi(f_width);
    }
    ~ppmImage() {   // destructor
    // No dynamic memory allocation in this class, so nothing to delete
    }

    int read_ppm_file(const string c_file_name); // reads a PPM file and stores the data in the class
    void menu(); // displays the main menu of options for the user
    void convert_grayscale(); // converts the image to grayscale
    int save_ppm_file(const string c_file_name)const; // saves the edited image to a new PPM file
    bool float_checker(const string& str) const; // checks if a string can be converted to a float

    private:
    int width,height;

    public:
    //A constructor which takes a ppm file name as argument and creates object form file.
    ppmImage(const string c_file_name){  
        if(read_ppm_file(c_file_name)==0)exit(1);
    }
    //A constructor which creates an object according to the given dimensions.
    ppmImage(int wid,int heig){
        if(ppm_data.size()>0){ ppm_data.clear();}// Clear any existing pixel data from the vector.
        Pixel pixel;
        pixel.R=255;pixel.G=255;pixel.B=255;
        p_type="P3";
        max_int="255";
        height=heig;
        width=wid;
        f_height=to_string(heig);
        f_width=to_string(wid);
        
        vector<Pixel> a;
        for (int i = 0; i<width; i++) {
            for (int j = 0; j<height; j++) {
                a.push_back(pixel);
            }
            ppm_data.push_back(a);
        }
    }

    // Accessors
    int getWidth() const;
    int getHeight() const;
    Pixel getPixel(int width, int height) const;

    // Mutators
    void setWidth(int width);
    void setHeight(int height);
    void setPixel(int width, int height, const Pixel& pixel);
    
    void print_dimensions()const;
    ppmImage& operator+(const ppmImage& other);
    ppmImage& operator-(const ppmImage& other);
    int& operator()(int row,int column,int color_channel);
    friend ostream& operator<<(ostream& os ,const ppmImage& other);

};

#pragma region PA2 FUNCTIONS 

bool ppmImage::float_checker(const string& str) const{
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
//menu
void ppmImage::menu(){
    
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
            string file_name;
            cin>>file_name;
            read_ppm_file(file_name);
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
            string ppm_file;
            cin>>ppm_file;
            save_ppm_file(ppm_file);
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
// This function reads in a PPM image file and stores its pixel data in a 2D vector of Ppm_data.
int ppmImage::read_ppm_file(const string c_file_name){
    // Clear any existing pixel data from the vector.
    if(ppm_data.size()>0){ ppm_data.clear();}
    // Prompt the user for the filename and open the file for reading.
    ifstream image;
    image.open(c_file_name);
     // If the file is successfully opened, read in the image metadata and pixel data.
    if(image.is_open()){
        image>>p_type>>f_width>>f_height>>max_int;
        // Read in the pixel data line by line, row by row.
        for (int i = 0; i<stoi(f_width); i++) {
            vector<Pixel> a;
            for (int j = 0; j<stoi(f_height); j++) {
            Pixel pixel;
            image >> pixel.R >> pixel.G >> pixel.B;
            a.push_back(pixel);
            }
        // Once a row of ppm_data has been read, add it to the 2D vector of Ppm_data.
        ppm_data.push_back(a);
        }
    }
    else {
        cout<<c_file_name<<" doesnt exists\n";
        return 0; 
    }
    
    width=stoi(f_width);
    height=stoi(f_height);
    image.close();
    return 1;
}
// This function converts an image to grayscale using coefficients for each color channel.
void ppmImage::convert_grayscale(){
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

    for(int i=0;i<ppm_data.size();i++){
        int j=0;
        if(i!=0){j=ppm_data[i-1].size();}
        for(j;j<ppm_data[i].size();j++){
            // Calculate the new grayscale value for the pixel using the specified coefficients.
            ppm_data[i][j].R=c_r*ppm_data[i][j].R+c_g*ppm_data[i][j].G+c_b*ppm_data[i][j].B;
            // If the new grayscale value exceeds 254 (the maximum value for a pixel component), set it to 255.
            if(ppm_data[i][j].R>254)ppm_data[i][j].R=255;
             // Set the G and B components of the pixel to the new grayscale value.
            ppm_data[i][j].G=ppm_data[i][j].R;
            ppm_data[i][j].B=ppm_data[i][j].R;
        }   
    }
}
// This function saves the current state of the image to a PPM file.
int ppmImage::save_ppm_file(const string c_file_name)const{
    ofstream image;
    image.open(c_file_name);
    if(image.is_open()){
        image<<p_type<<"\n" <<f_width<<" "<<f_height<<"\n" <<max_int<<"\n";
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
            image<<ppm_data[i][j].R<<" "<<ppm_data[i][j].G<<" "<<ppm_data[i][j].B<<" ";
            }
            image<<"\n";
        }
    }
    else{return 0;}
    image.close();
    return 1;
}

#pragma endregion

#pragma region Accessors & Mutators

// Definition of a member function that returns the width of the ppmImage object.
int ppmImage::getWidth()const{
    return width;
}

// Definition of a member function that returns the height of the ppmImage object.
int ppmImage::getHeight()const{
    return height;
}

// Definition of a member function that returns a copy of the Pixel object at the specified
// coordinates in the ppm_data array.
Pixel ppmImage::getPixel(int width, int height) const{
    return ppm_data[width][height];
}

// Definition of a member function that sets the width of the ppmImage object.
void ppmImage::setWidth(int wid){
    width=wid;
}

// Definition of a member function that sets the height of the ppmImage object.
void ppmImage::setHeight(int heig){
    height=heig;
}

// Definition of a member function that sets the Pixel object at the specified coordinates
// in the ppm_data array.
void ppmImage::setPixel(int width, int height, const Pixel& pixel){
    ppm_data[width][height]=pixel;
}

// Definition of a member function that prints the dimensions (width and height) of the ppmImage object to the console.
void ppmImage::print_dimensions()const{
    cout<<"("<<width<<","<<height<<")"<<endl;
}

#pragma endregion 

#pragma region Operator Overloads

ppmImage& ppmImage::operator+(const ppmImage& other){
    height=stoi(f_height);
    width=stoi(f_width);
    if(f_width==other.f_width && f_height==other.f_height){
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                ppm_data[i][j].R+=other.ppm_data[i][j].R;
                ppm_data[i][j].G+=other.ppm_data[i][j].G;
                ppm_data[i][j].B+=other.ppm_data[i][j].B;
                if(ppm_data[i][j].R>254)ppm_data[i][j].R=255;
                if(ppm_data[i][j].G>254)ppm_data[i][j].G=255;
                if(ppm_data[i][j].B>254)ppm_data[i][j].B=255;
            }
        }
        /*for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                cout<<ppm_data[i][j].R<<" "<<ppm_data[i][j].G<<" "<<ppm_data[i][j].B<<" ";
            }
            cout<<"\n";
        }*/
    }
    else {
        this->ppm_data.clear();
        this->f_height="0";
        this->f_width="0";
        this->height=0;
        this->width=0;
    }
    return *this;
}

ppmImage& ppmImage::operator-(const ppmImage& other){
    height=stoi(f_height);
    width= stoi(f_width);
    if(f_width==other.f_width && f_height==other.f_height){
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                ppm_data[i][j].R-=other.ppm_data[i][j].R;
                ppm_data[i][j].G-=other.ppm_data[i][j].G;
                ppm_data[i][j].B-=other.ppm_data[i][j].B;
                if(ppm_data[i][j].R<1)ppm_data[i][j].R=0;
                if(ppm_data[i][j].G<1)ppm_data[i][j].G=0;
                if(ppm_data[i][j].B<1)ppm_data[i][j].B=0;
            }
        }
        /*for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                cout<<ppm_data[i][j].R<<" "<<ppm_data[i][j].G<<" "<<ppm_data[i][j].B<<" ";
            }
            cout<<"\n";
        }*/
    }
    else {
        this->ppm_data.clear();
        this->f_height="0";
        this->f_width="0";
        this->height=0;
        this->width=0;
    }
    return *this;
}

ostream& operator<<(ostream& os ,const ppmImage& obj){
    os<<obj.p_type<<"\n" <<obj.f_width<<" "<<obj.f_height<<"\n" <<obj.max_int<<"\n";
    // If the image dimensions are valid (greater than 0), output the color values
    // of each pixel in the ppm_data array to the output stream.
    if(stoi(obj.f_height)>0 && stoi(obj.f_width)>0){
        // Iterate over the rows and columns of the ppm_data array.
        for(int i=0;i<obj.width;i++){
            for(int j=0;j<obj.height;j++){
                 // Output the R, G, and B values of the current pixel to the output
                // stream, separated by spaces.
            os<<obj.ppm_data[i][j].R<<" "<<obj.ppm_data[i][j].G<<" "<<obj.ppm_data[i][j].B<<" ";
            }
            os<<"\n";
        }
    }
    else os<<"\n";
    return os;
}

int& ppmImage::operator()(int row,int column,int color_channel){
    if(color_channel==1)    return ppm_data[row][column].R;
    else if(color_channel==2)   return ppm_data[row][column].G;
    else if(color_channel==3)   return ppm_data[row][column].B;
    else cout<<"error"; 
}

#pragma endregion 

#pragma region Standalone Functions

int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){

    if(destination_object.read_ppm_file(source_ppm_file_name)==1)return 1;
    else return 0;
}

int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){
    if(source_object.save_ppm_file(destination_ppm_file_name)==1)return 1;
    else return 0;
}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){
    ppmImage obj1,obj2,obj3;
    obj1.read_ppm_file(filename_image1);
    obj2.read_ppm_file(filename_image2);
    obj3=obj2+obj1;
    obj3.save_ppm_file(filename_image3);
    if(obj3.getHeight()==0 || obj3.getWidth()==0)return 0;
    return 1;
}

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){
    ppmImage obj1,obj2,obj3;
    obj1.read_ppm_file(filename_image1);
    obj2.read_ppm_file(filename_image2);
    obj3=obj2-obj1;
    obj3.save_ppm_file(filename_image3);
    if(obj3.getHeight()==0 || obj3.getWidth()==0)return 0;
    return 1;
}

int test_print(const string filename_image1){
    // Declare a variable "obj1" of type "ppmImage"
    ppmImage obj1;
    if(obj1.read_ppm_file(filename_image1)==0)return 0;
    cout<<obj1;
    return 1;
}

int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){
    int x=0,y=0;
    // Determine which two channels to swap based on swap_choice
    if(swap_choice==1){ x=1; y=2;}
    else if(swap_choice==2){ x=1; y=3;}
    else if(swap_choice==3){ x=2; y=3;}
    // If swap_choice is not valid, return 1 without making any changes to the image object
    else { return 1;}
    // Iterate through every pixel in the image object
    for(int i=0;i<image_object_to_be_modified.getWidth();i++){
        for(int j=0;j<image_object_to_be_modified.getHeight();j++){
            // Swap the x-th and y-th color channels of the current pixel
            int temp=image_object_to_be_modified(i,j,x);
            image_object_to_be_modified(i,j,x)=image_object_to_be_modified(i,j,y);
            image_object_to_be_modified(i,j,y)=temp;
        }
    }
    // Return 1 to indicate successful execution
    return 1;
}

bool is_it_integer(string user_number){
    int counter=0; 
    string numbers={"0123456789"};
    for(auto i: user_number){
        for(auto j: numbers){
            if(i==j){
                counter++;
            }
        }
        if(counter!=1) return false;
        else counter=0;    
    }
    return true;
}

ppmImage single_color(const ppmImage& source, int color_choice){
    // Declare and initialize variables for the image width and height, and make a copy of the source image.
    int wi=source.getWidth();
    int he=source.getHeight();
    ppmImage temp(source);
    
    for(int i=0;i<wi;i++){
        for(int j=0;j<he;j++){
            // Check the value of the color_choice parameter.
            // If it is 1, set the green and blue channels to 0.
            if(color_choice==1){temp(i,j,2)=0;temp(i,j,3)=0;}
             // If it is 2, set the red and blue channels to 0.
            else if(color_choice==2){temp(i,j,1)=0;temp(i,j,3)=0;}
            // If it is 3, set the red and green channels to 0.
            else if(color_choice==3){temp(i,j,1)=0;temp(i,j,2)=0;}
        }
    }
    // Return the modified image.
    return temp;
}

#pragma endregion

int main(int argc, char** argv){
    string a=argv[1];
    if(is_it_integer(a)==false){
        cerr<<"error\n";
        exit(1);
    }
    int choice_number=stoi(argv[1]);
    string ppm_file_name1,ppm_file_name2,ppm_file_name3;
    if(argc>2){ ppm_file_name1=argv[2];}
    if(argc>3){ ppm_file_name2=argv[3];}
    if(argc>4){ ppm_file_name3=argv[4];}

    if(choice_number==1){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() || ppm_file_name3.empty()){
        cout<<"Files are missing\n";
        exit(1);
        }
        test_addition(ppm_file_name1,ppm_file_name2,ppm_file_name3);
    }
    else if(choice_number==2){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() || ppm_file_name3.empty()){
        cerr<<"Files are missing\n";
        exit(1);
        }
        if(test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3)==0)exit(1);
    }
    else if(choice_number==3){
        if(ppm_file_name1.empty() || ppm_file_name2.empty()){
        cerr<<"Files are missing\n";
        exit(1);
        }
        ppmImage obj;
        if(read_ppm(ppm_file_name1,obj)==0){
            cerr<<"error\n";
             return 0;}
        if(swap_channels(obj,2)==0){
            cerr<<"error\n";
             return 0;}
        if(write_ppm(ppm_file_name2,obj)==0){
            cerr<<"error\n";
             return 0;}
    }
    else if(choice_number==4){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() ){
        cerr<<"Files are missing\n";
        exit(1);
        }
        ppmImage obj;
        if(read_ppm(ppm_file_name1,obj)==0){
            cerr<<"error\n";
             return 0;}
        if(swap_channels(obj,3)==0){
            cerr<<"error\n";
             return 0;}
        if(write_ppm(ppm_file_name2,obj)==0){
            cerr<<"error\n";
             return 0;}
    }
    else if(choice_number==5){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() ){
        cerr<<"Files are missing\n";
        exit(1);
        }
        ppmImage obj,new_obj;
        if(read_ppm(ppm_file_name1,obj)==0){
            cerr<<"error\n";
             return 0;}
        new_obj=single_color(obj,1);
        if(write_ppm(ppm_file_name2,new_obj)==0){
            cerr<<"error\n";
             return 0;}
    }
    else if(choice_number==6){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() ){
        cerr<<"Files are missing\n";
        exit(1);
        }
        ppmImage obj,new_obj;
        if(read_ppm(ppm_file_name1,obj)==0){
            cerr<<"error\n";
             return 0;}
        new_obj=single_color(obj,2);
        if(write_ppm(ppm_file_name2,new_obj)==0){
            cerr<<"error\n";
             return 0;}
    }
    else if(choice_number==7){
        if(ppm_file_name1.empty() || ppm_file_name2.empty() ){
        cerr<<"Files are missing\n";
        exit(1);
        }
        ppmImage obj,new_obj;
        if(read_ppm(ppm_file_name1,obj)==0){
            cerr<<"error\n";
             return 0;}
        new_obj=single_color(obj,3);
        if(write_ppm(ppm_file_name2,new_obj)==0){
            cerr<<"error\n";
             return 0;}
    }
    
    return 0;
}