#include "Course.h"

namespace PA4{
        Course::Course(){
            name=" ";
            code=" ";
            sarr_size=0;     // Initialize member variables
            sarray=new Student[sarr_size];  // Allocate memory for dynamic array
        }   
        Course::Course(std::string n,std::string co){
            name=n;
            code=co;
            sarr_size=0;
            sarray=new Student[sarr_size]; 
        }
        Course::Course(const Course& other){
            name=other.name;
            code=other.code;
            sarr_size=other.sarr_size;
            sarray=new Student[other.sarr_size];    // Deep copy dynamic array
            for(int i=0;i<other.sarr_size;i++){
            sarray[i]=other.sarray[i];
            }
        }
        Course Course::operator=(const Course& other){
            name=other.name;
            code=other.code;
            sarr_size=other.sarr_size;
            sarray=new Student[other.sarr_size];    // Deep copy dynamic array
            for(int i=0;i<other.sarr_size;i++){
                sarray[i]=other.sarray[i];
            }
            return *this;
        }

        bool Course::operator==(const Course& other)const{
            int flag=0,counter=0;
            if(name==other.name && code==other.code && sarr_size==other.sarr_size)flag=1;
            if(flag==0)return false;
            for(int i=0;i<sarr_size;i++){
                for(int j=0;j<sarr_size;j++){
                    if(sarray[i].get_id()==other.sarray[j].get_id() && sarray[i].get_name()==other.sarray[j].get_name() ){
                        counter++;   // Check if students are equal
                    }
                }
            }
            if(counter==sarr_size)return true;  // Return true if all students are equal

            return false;
        }
        bool Course::operator!=(const Course& other)const{
            if(*this==other)return false;   // Check if objects are not equal
            else return true;
        }

        Course::~Course(){
            delete [] sarray;   // Deallocate memory for dynamic array
        }

        std::string Course::get_name(){
            return name;
        }

        std::string Course::get_code(){
            return code;
        }

        void Course::set_name(std::string n){
            name=n;
        }

        void Course::set_code(std::string co){
            code=co;
        }

        void Course::add_student_to_course(const Student ca){
            Student* temp=new Student[sarr_size+1]; // Allocate memory for new dynamic array
            for(int i=0;i<sarr_size;i++){
                temp[i]=sarray[i];
            }
            temp[sarr_size]=ca; // Add new student to dynamic array
            delete [] sarray;   // Deallocate memory for old dynamic array
            sarr_size++;
            sarray=temp;    // Set new dynamic array
        }
        void Course::drop_student_from_course(const Student ca){
            Student* temp=new Student[sarr_size-1]; // Allocate memory for new dynamic array
            int j=0;
            for(int i=0;i<sarr_size;i++){
                if(sarray[i]==ca){} // If student is found, don't add to new dynamic array
                else{
                    temp[j]=sarray[i];
                j++;
                }
            }
            delete [] sarray;   // Deallocate memory for old dynamic array
            sarr_size--;
            sarray=temp;    // Set new dynamic array
        }   

        Student*& Course::get_sarray(){
            return sarray;
        }
        int& Course::get_sarr_size(){
            return sarr_size;
        }
}