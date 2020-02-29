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

    bool addStudent(char* n, int c) ;
    bool addCourse(char* n, int c) ;
    void enterStudentGrades(CStudent* ps, CCourse* pc, int* gr) ;

    bool enroll(CStudent* ps, CCourse* pc) ;
    void displayStudents() ;
    void displayCourses() ;

public: // DO NOT TOUCH THE ABOVE CODE
        void coursesofStudent(CStudent* ps);
        void bestStudentInCourse(CCourse* pc);
        CStudent* findBestinDept();


} ;
#endif /* CDept2_hpp */
