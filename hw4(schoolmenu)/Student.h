#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Course.h"

namespace PA4{
class Course;

class Student{
    private:
        std::string name;
        int ID;
        Course* carray;
        int carr_size;

    public:
        Student();
        Student(std::string n,int id);
        Student(const Student& other);
        Student operator=(const Student& other);
        bool operator!=(const Student& other);
        bool operator==(const Student& other);
        ~Student();

        std::string get_name();
        int get_id();
        Course*& get_carray();
        int get_carr_size();
        void set_name(std::string n);
        void set_id(int id);
        
        void add_course_to_student(Course& ca);
        void drop_course_from_student(Course& ca);

        void print_courses();

};


}
#endif