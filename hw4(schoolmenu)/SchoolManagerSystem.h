#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <iostream>
#include <sstream>
#include "Course.h"
#include "Student.h"


namespace PA4{

class SCHOOLMANAGERSYSTEM{
    private:
        Course* carr;
        Student* sarr;
        int carr_size;
        int sarr_size;

    public:
        SCHOOLMANAGERSYSTEM();
        SCHOOLMANAGERSYSTEM(const SCHOOLMANAGERSYSTEM& other);
        SCHOOLMANAGERSYSTEM operator=(const SCHOOLMANAGERSYSTEM& other);
        ~SCHOOLMANAGERSYSTEM();
        void menu();

        void add_student(const Student& obj);
        void delete_student(const Student& obj);
        void add_selected_student_to_a_course(Student& obj);
        void drop_selected_student_from_a_course(Student& obj);
        void print_students(); //DEBUG PERPOSES 

        void add_course(const Course& obj);
        void delete_course(const Course& obj);
        void list_students_registered_to_the_selected_course(Course& obj);
        void print_courses(); //DEBUG PERPOSES 

};


}
#endif