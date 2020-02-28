#ifndef CDept_hpp
#define CDept_hpp
#include <stdio.h>
#include "constants.h"
#include "CStudent.hpp"
#include "CCourse.hpp"

class CDept {
private: // You should not add any attribute
    CStudent** students ;
    int nbStudents ;
    CCourse**  courses ;
    int nbCourses ;
    
private: // private functions called by the constructor
    void createStudents() ;
    void createCourses() ;
    void createDefaultGrades() ;
    void enrollStudentsInCourses() ;
    
public:
    CDept() ;
    ~CDept() ;
    
    CStudent* getStudent(int index) ;
    CCourse* getCourse(int index) ;
    
    bool addStudent() ;
    bool addCourse() ;
    void enterStudentGrades(CStudent* ps, CCourse* pc) ;

    bool enroll(CStudent* ps, CCourse* pc) ;
    void displayStudents() ;
    void displayCourses() ;
    
public: // DO NOT TOUCH THE ABOVE CODE
        // Add other other functions below as needed

} ;
#endif /* CDept2_hpp */
