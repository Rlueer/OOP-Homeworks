#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "Student.h"

namespace PA4{
class Student;

class Course{
    private:
        std::string name;
        std::string code;
        Student* sarray;
        int sarr_size;

    public:
        Course();
        Course(std::string n,std::string co);
        Course(const Course& other);
        Course operator=(const Course& other);
        bool operator!=(const Course& other)const;
        bool operator==(const Course& other)const;
        ~Course();

        std::string get_name();
        std::string get_code();
        void set_name(std::string n);
        void set_code(std::string co);

        Student*& get_sarray();
        int& get_sarr_size();
        
        void list_students_of_course(const Course ca);

        void print_courses();

        void add_student_to_course(const Student ca);
        void drop_student_from_course(const Student ca);

};


}
#endif