#ifndef CStudent_hpp
#define CStudent_hpp
#include <string>
#include <stdio.h>

 class CStudent {
 private:
     // --- add attributes here
 	char* name;
 	int id;
 	int maxCourses;
 	int* courses; //array of pointers to the courses the student has chosen
 	int nbCourses;
 	int **grades; //double pointer to dynamic 2D array. courses have NBEXAMS exams. so NBEXAMS cols and maxCourses rows
 
 public: //Memory management methods
     // --- constr, desctructor add Memory management methods here
     CStudent(char* vname, int vid) ;
     ~CStudent() ;
     
 public:
     // --- add getters and setters here
 	void setCourseGrades(int ci, int* scores); 
 	void setExamGrade();
     
 public:
     // --- add grades methods here

 public:
     // --- add other methods here
 	void enroll(CCourse *c);
 	void displayCourses();

     
} ;

#endif
