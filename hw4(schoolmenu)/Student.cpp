#include "Student.h"

namespace PA4{
        Student::Student(){// Constructor that sets default values for the Student object
            name=" ";
            ID=0;
            carr_size=0;
            carray=new Course[carr_size];  
        }
        Student::Student(std::string n,int id){// Constructor that sets name and ID values for the Student object
            name=n;
            ID=id;
            carr_size=0;
            carray=new Course[carr_size]; 
        }
        Student::Student(const Student& other){// Copy constructor that creates a deep copy of a Student object
            name=other.name;
            ID=other.ID;
            carr_size=other.carr_size;
            carray=new Course[other.carr_size];
            for(int i=0;i<other.carr_size;i++){
            carray[i]=other.carray[i];
            }
        }
        Student Student::operator=(const Student& other){// Assignment operator that assigns the values of one Student object to another
            name=other.name;
            ID=other.ID;
            carr_size=other.carr_size;
            carray=new Course[other.carr_size];
            for(int i=0;i<other.carr_size;i++){
                carray[i]=other.carray[i];
            }
            return *this;
        }

        bool Student::operator==(const Student& other){// Equality operator that checks if two Student objects are equal
            int flag=0,counter=0;
            if(name==other.name && ID==other.ID && carr_size==other.carr_size)flag=1;
            if(flag==0)return false;
            for(int i=0;i<carr_size;i++){
                for(int j=0;j<carr_size;j++){
                    if(carray[i].get_code()==other.carray[j].get_code() && carray[i].get_name()==other.carray[j].get_name() ){
                        counter++;
                    }
                }
            }
            if(counter==carr_size)return true;

            return false;
        }
        bool Student::operator!=(const Student& other){// Inequality operator that checks if two Student objects are not equal
            if(*this==other)return false;
            else return true;
        }

        Student::~Student(){// Destructor that deletes the dynamically allocated memory for carray
            delete [] carray;
        }

        std::string Student::get_name(){// Returns the name of the Student object
            return name;
        }

        int Student::get_id(){// Returns the ID of the Student object
            return ID;
        }

        void Student::set_name(std::string n){// Sets the name of the Student object
            name=n;
        }

        void Student::set_id(int id){// Sets the ID of the Student object
            ID=id;
        }

        void Student::add_course_to_student(Course& ca){// Adds a course to the Student object's carray
            Course* temp=new Course[carr_size+1];
            for(int i=0;i<carr_size;i++){
                temp[i]=carray[i];
            }
            temp[carr_size]=ca;
            delete [] carray;
            carr_size++;
            carray=temp;
            ca.add_student_to_course(*this);
        }
        void Student::drop_course_from_student(Course& ca){ // Drops a course from the Student object's carray
            Course* temp=new Course[carr_size-1];
            int j=0;
            for(int i=0;i<carr_size;i++){
                if(carray[i]==ca){}
                else{
                    temp[j]=carray[i];
                j++;
                }
            }
            delete [] carray;
            carr_size--;
            carray=temp;
            ca.drop_student_from_course(*this);
        }

        Course*& Student::get_carray(){// Returns carray reference
            return carray;
        }
        int Student::get_carr_size(){// Returns get_carr_size reference
            return carr_size;
        }

        void Student::print_courses(){  //Prints everything inside of carray
        for(int i=0;i<carr_size;i++){
            std::cout<<carray[i].get_code()<<" "<<carray[i].get_name()<<"\n";
        }
    }
}
