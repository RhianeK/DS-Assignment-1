#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "CDept.hpp"
#include "CCourse.hpp"
#include "CStudent.hpp"

CDept::CDept() {
    // -- do it here --

}

CDept::~CDept() {
    // -- do it here --
    delete [] students;
    delete [] courses;
}

CStudent* CDept::getStudent(int index)
{
    // -- do it here --
    return NULL ; //Added to avoid compiler error. Replace it with the right return statement
}

CCourse* CDept::getCourse(int index)
{
    // -- do it here --
    return NULL ; //Added to avoid compiler error. Replace it with the right return statement
}

void CDept::createStudents() {
    char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
        (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ;
    
    // Let's create 5 students,
    nbStudents= 5 ;
    for(int st= 0; st<nbStudents; st++) students[st] = new CStudent(stNames[st], stCodes[st]) ;
}

void CDept::createCourses() {
    char* crNames[] = {(char*)"CSO", (char*)"OS", (char*)"DB", (char*)"D. Math", (char*)"Software Eng",
        (char*)"logic", (char*)"AI", (char*)"Algo", (char*)"NLP", (char*)"Prog 1"} ;
    int crCodes[]   = {106, 116, 126, 206, 216, 226, 306, 316, 326, 406} ;
    
    // Let's create 5 courses,
    nbCourses= 5 ;
    for(int cr= 0; cr<nbCourses; cr++) courses[cr] = new CCourse(crNames[cr], crCodes[cr]) ;
}

void CDept::enrollStudentsInCourses()
{
    srand((unsigned int)time(0));
    
    // -- do it here --

}

void CDept::createDefaultGrades()
{
    // Use current time as seed for random generator
    srand((unsigned int)time(0));
    
    // -- do it here --

}

bool CDept::addStudent() {
    // -- do it here --

    return true ; //or return false
}

bool CDept::addCourse() {
    
    return true ; //or return false
}

bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --

    return true ; //or return false
}

void CDept::displayStudents() {
    // -- do it here --
     
    
}

void CDept::displayCourses() {
    // -- do it here --
    
}
