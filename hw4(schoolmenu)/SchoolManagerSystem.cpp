#include "SchoolManagerSystem.h"

namespace PA4{
    SCHOOLMANAGERSYSTEM::SCHOOLMANAGERSYSTEM(){// Constructor for the SCHOOLMANAGERSYSTEM class
        carr_size=0;
        sarr_size=0;
        carr=new Course[carr_size];
        sarr=new Student[sarr_size];
    }
    // Copy assignment operator for the SCHOOLMANAGERSYSTEM class
    SCHOOLMANAGERSYSTEM SCHOOLMANAGERSYSTEM::operator=(const SCHOOLMANAGERSYSTEM& other){
        carr_size=other.carr_size;
        sarr_size=other.sarr_size;
        for(int i=0;i<other.sarr_size;i++){
            sarr[i]=other.sarr[i];
        }
        for(int i=0;i<other.carr_size;i++){
            carr[i]=other.carr[i];
        }
        return *this;
    }
    // Copy constructor for the SCHOOLMANAGERSYSTEM class
    SCHOOLMANAGERSYSTEM::SCHOOLMANAGERSYSTEM(const SCHOOLMANAGERSYSTEM& other){
        carr_size=other.carr_size;
        sarr_size=other.sarr_size;
        for(int i=0;i<other.sarr_size;i++){
            sarr[i]=other.sarr[i];
        }
        for(int i=0;i<other.carr_size;i++){
            carr[i]=other.carr[i];
        }
    }
    // Destructor for the SCHOOLMANAGERSYSTEM class
    SCHOOLMANAGERSYSTEM::~SCHOOLMANAGERSYSTEM(){
        delete [] carr;
        delete [] sarr;
    }
    // Adds a student to the system
    void SCHOOLMANAGERSYSTEM::add_student(const Student& obj){
        int flag=0;
        for(int i=0;i<sarr_size;i++){
            if(sarr[i]==obj){
                flag=1;
            }
        }
        if(flag==0){
        Student* temp=new Student[sarr_size+1];
        for(int i=0;i<sarr_size;i++){
            temp[i]=sarr[i];
        }
        temp[sarr_size]=obj;
        delete [] sarr;
        sarr_size++;
        sarr=temp;
        }
    }
    // Deletes a student from the system
    void SCHOOLMANAGERSYSTEM::delete_student(const Student& obj){
        int flag=0;
        for(int i=0;i<sarr_size;i++){
            if(sarr[i]==obj){
                flag=1;
            }
        }
        if(flag==1){
        Student* temp=new Student[sarr_size-1];
        int j=0;
        for(int i=0;i<sarr_size;i++){
            if(sarr[i]==obj){}
            else{
                temp[j]=sarr[i];
            j++;
            }
        }
        delete [] sarr;
        sarr_size--;
        sarr=temp;
        }
    }
    // Adds a selected student to a course
    void SCHOOLMANAGERSYSTEM::add_selected_student_to_a_course(Student& obj){
        int choice=0;
        std::cout<<"0 up\n";
        for(int i=0;i<carr_size;i++){
            std::cout<<i+1<<" "<<carr[i].get_code()<<" "<<carr[i].get_name()<<"\n";
        }
        std::cin>>choice;
        if (choice > 0) {
            obj.add_course_to_student(carr[choice-1]);
            for(int i=0;i<sarr_size;i++){
                if(sarr[i].get_id()==obj.get_id() && sarr[i].get_name()==obj.get_name()){
                sarr[i]=obj;
                }
            }
        }
    }
    // This function drops a selected course from a student's course array
    void SCHOOLMANAGERSYSTEM::drop_selected_student_from_a_course(Student& obj){
        int choice=0;
        std::cout<<"0 up\n";
        for(int i=0;i<obj.get_carr_size();i++){
            std::cout<<i+1<<" "<<obj.get_carray()[i].get_code()<<" "<<obj.get_carray()[i].get_name()<<"\n";
        }
        std::cin>>choice;
        if (choice > 0) {
            // Display a list of courses the student is registered for
            obj.drop_course_from_student(carr[choice-1]);
            // Update the student object in the main student array
            for(int i=0;i<sarr_size;i++){
                if(sarr[i].get_id()==obj.get_id() && sarr[i].get_name()==obj.get_name()){
                sarr[i]=obj;
                }
            }
        }
    }
    // This function prints out a list of all students in the system
    void SCHOOLMANAGERSYSTEM::print_students(){
        for(int i=0;i<sarr_size;i++){
            std::cout<<sarr[i].get_name()<<sarr[i].get_id()<<"\n";
        }
    }
    // This function adds a new course to the course array
    void SCHOOLMANAGERSYSTEM::add_course(const Course& obj){
        int flag=0;
        // Check if the course already exists in the array
        for(int i=0;i<carr_size;i++){
            if(carr[i]==obj){
                flag=1;
            }
        }
        // If the course doesn't exist in the array, add it
        if(flag==0){
        Course* temp=new Course[carr_size+1];
        for(int i=0;i<carr_size;i++){
            temp[i]=carr[i];
        }
        temp[carr_size]=obj;
        delete [] carr;
        carr_size++;
        carr=temp;
        }
    }
    // This function deletes a course from the course array
    void SCHOOLMANAGERSYSTEM::delete_course(const Course& obj){
        int flag=0;
        // Check if the course exists in the array
        for(int i=0;i<carr_size;i++){
            if(carr[i]==obj){
                flag=1;
            }
        }
        // If the course exists in the array, delete it
        if(flag==1){
        Course* temp=new Course[carr_size-1];
        int j=0;
        for(int i=0;i<carr_size;i++){
            if(carr[i]==obj){}
            else{
                temp[j]=carr[i];
            j++;
            }
        }
        delete [] carr;
        carr_size--;
        carr=temp;
        }
    }
    // This function lists all students who are registered for a selected course
    void SCHOOLMANAGERSYSTEM::list_students_registered_to_the_selected_course(Course& obj){
        for(int i=0;i<obj.get_sarr_size();i++){
            std::cout<<i+1<<" "<<obj.get_sarray()[i].get_name()<<obj.get_sarray()[i].get_id()<<"\n";
        } 
    }
    // This function prints out a list of all courses in the system
    void SCHOOLMANAGERSYSTEM::print_courses(){
        for(int i=0;i<carr_size;i++){
            std::cout<<carr[i].get_code()<<" "<<carr[i].get_name()<<"\n";
        }
    }

    void SCHOOLMANAGERSYSTEM::menu(){
    
    int choice;
    do{
        std::cout<<"0 exit\n"<<"1 student\n"<<"2 course\n"<<"3 list_all_students\n"<<"4 list_all_courses\n";
        std::cin>>choice;

        switch (choice)
        {
        case 0: //0 exit
            exit(0);
            break;
        case 1: //1 student
            int choice2;
            do{
                std::cout<<"0 up\n"<<"1 add_student\n"<<"2 select_student\n";
                std::cin>>choice2;
                if(choice2==0)break;
                    std::string news,n,last;
                    int id,flagg=0,i=0;
                    std::cin.ignore(1,'\n');
                    getline(std::cin,n);
                    std::istringstream ss(n);
                    std::string* arr=new std::string[100];
                    while ( getline( ss, n, ' ' ) ) {
                        arr[i]=n.c_str();
                        i++;
                    }
                    last=arr[i-1];
                    for(int i=0;i<last.length();i++){   // son girdinin numara olduğunu kontrol ediyor
                        if(isdigit(last[i])==0)flagg=1;
                    }       
                    if(flagg==1)break;
                    id=std::stoi(last);
                    for(int j=0;j<i-1;j++){news+=arr[j]+" ";}
                    Student obj(news,id);
                    bool found = false;
                switch (choice2)
                {
                case 0: //0 up
                    choice2=0;
                    break;
                case 1: //1 add_student
                    add_student(obj);
                    break;
                case 2: //2 select_student
                    int choice4;
                    do{
                        std::cout<<"0 up\n"<<"1 delete_student\n"<<"3 add_selected_student_to_a_course\n"
                        <<"4 drop_selected_student_from_a_course\n";
                        std::cin>>choice4;
                        for(int i=0;i<sarr_size;i++){  
                            if(sarr[i].get_id()==id && sarr[i].get_name()==news){
                                obj=sarr[i];
                                found=true;
                                break;
                            }   
                        }
                        
                        if (!found) continue;  

                        switch (choice4)
                        {
                        case 1: //1 delete_student
                            delete_student(obj);
                            choice4=0;
                            break;
                        case 3: //3 add_selected_student_to_a_course
                            add_selected_student_to_a_course(obj);
                            break;
                        case 4: //4 drop_selected_student_from_a_course
                            drop_selected_student_from_a_course(obj);
                            break;

                        default:
                            break;
                        }
                    }while(choice4!=0);
                    break;
                default:
                    break;
                }
            }while(choice2!=0);
            break;
        case 2: //2 course
            int choice3;
            do{
                std::cout<<"0 up\n"<<"1 add_course\n"<<"2 select_course\n";
                std::cin>>choice3;
                if(choice3==0)break;
                    std::string n,news,code;
                    int i=0;
                    std::cin.ignore(1,'\n');
                    getline(std::cin,n);
                    std::istringstream ss(n);
                    std::string* arr=new std::string[100];
                    while ( getline( ss, n, ' ' ) ) {
                        arr[i]=n.c_str();
                        i++;
                    }
                    code=arr[0];
                    for(int j=1;j<i;j++){news+=arr[j]+" ";}
                    Course obj(news,code);
                    bool found = false;

                switch (choice3)
                {
                case 0:
                    choice2=0;
                    break;
                case 1: //1 add_course
                    add_course(obj);
                    break;
                case 2: //2 select_course
                    int choice5;
                    for(int i=0;i<carr_size;i++){   
                        if(carr[i].get_code()==code && carr[i].get_name()==news){
                            obj=carr[i];
                            found = true;
                            break;
                        }
                    }
                    if (!found) continue;                    
                    do{
                        std::cout<<"0 up\n"<<"1 delete_course\n"<<
                        "2 list_students_registered_to_the_selected_course\n";
                        std::cin>>choice5;
                        switch (choice5)
                        {
                        case 1: //1 delete_student
                            delete_course(obj);
                            choice5=0;
                            break;
                        case 2: //2 list_students_registered_to_the_selected_course()
                            list_students_registered_to_the_selected_course(obj);
                            choice5=0;
                            break;
                        default:
                            break;
                        }
                    }while(choice5!=0);
                    break;
                default:
                    break;
                }
            }while(choice3!=0);
            break;
        case 3: //3 list_all_students
            print_students();
            break;
        case 4: //4 list_all_courses
            print_courses();
            break;

        default:
            break;
        }


    }while(1);
    }

}
